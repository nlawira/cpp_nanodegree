#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  Processor();
  float Utilization();  // TODO: See src/processor.cpp

  // TODO: Declare any necessary private members
 private:
  long prevIdle_;
  long prevActive_;
  long prevTotal_;
  long currIdle_;
  long currActive_;
  long currTotal_;
  float cpuutil_;
};

#endif