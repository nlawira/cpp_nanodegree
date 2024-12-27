#include "processor.h"
#include "linux_parser.h"
#include <string>
using std::string;

Processor::Processor() : 
	prevIdle_(LinuxParser::IdleJiffies()),
	prevActive_(LinuxParser::ActiveJiffies()),
	prevTotal_(prevIdle_ + prevActive_) {}

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
  float cpuutil;
  long currIdle = LinuxParser::IdleJiffies();
  long currActive = LinuxParser::ActiveJiffies();
  long currTotal = currIdle + currActive;
  
  long deltaIdle = currIdle - prevIdle_;
  long deltaTotal = currTotal - prevTotal_;
  
  prevIdle_ = currIdle;
  prevActive_ = currActive;
  prevTotal_ = currTotal;
  
  if(deltaTotal == 0) {
    cpuutil = 0;
  }
  else {
    cpuutil = (deltaTotal - deltaIdle) / deltaTotal;
  }
  return cpuutil;
}