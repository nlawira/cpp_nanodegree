#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(int pid) : 
	pid_(pid), 
	user_(LinuxParser::User(pid)), 
	comm_(LinuxParser::Command(pid)),
	cpuutil_(CpuUtilization()) {};

// TODO: Return this process's ID
int Process::Pid() { return pid_; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() {
  long sUpTime = LinuxParser::UpTime();
  long pTotalTime = LinuxParser::ActiveJiffies(pid_);
  long pUpTime = LinuxParser::UpTime(pid_);
  
  long TotalElapsedTime = sUpTime - pUpTime;
  float cpuUsage = 100.0 * ((pTotalTime / sysconf(_SC_CLK_TCK)) / TotalElapsedTime);
  
  return cpuUsage;
}

// TODO: Return the command that generated this process
string Process::Command() { return comm_; }

// TODO: Return this process's memory utilization
string Process::Ram() { return LinuxParser::Ram(this->pid_); }

// TODO: Return the user (name) that generated this process
string Process::User() { return user_; }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(this->pid_); }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const {
  return this->cpuutil_ < a.cpuutil_;
}