#include "processor.h"
#include "linux_parser.h"
#include <string>

Processor::Processor() {
  prevIdle_ = LinuxParser::IdleJiffies();
  prevActive_ = LinuxParser::ActiveJiffies();
  prevTotal_ = prevIdle_ + prevActive_;
}

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
  currIdle_ = LinuxParser::IdleJiffies();
  currActive_ = LinuxParser::ActiveJiffies();
  currTotal_ = currIdle_ + currActive_;
  
  auto deltaIdle = currIdle_ - prevIdle_;
  auto deltaTotal = currTotal_ - prevTotal_;
  
  prevIdle_ = currIdle_;
  prevActive_ = currActive_;
  prevTotal_ = currTotal_;
  
  if (deltaTotal > 0) {
    cpuutil_ = static_cast<float>(deltaTotal - deltaIdle) / deltaTotal;
  } else {
    cpuutil_ = 0.0;
  }
  
  return cpuutil_;
}