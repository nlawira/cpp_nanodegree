#include <string>
#include <sstream>

#include "format.h"

using std::string;

string Format::StringFormatter(int number) {
  std::stringstream sstr;
  if (number < 10) {
    sstr << "0";
  }
  sstr << number;  
  return sstr.str();
}

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long times) {
  int hour(times / 3600);
  int minute((times % 3600) / 60);
  int second((times % 3600) % 60);
  return Format::StringFormatter(hour) + ":" + Format::StringFormatter(minute) + ":" + Format::StringFormatter(second);
}