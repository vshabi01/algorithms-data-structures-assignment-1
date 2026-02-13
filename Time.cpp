#include <iomanip>
#include <stdexcept> //this includes the "invalid argument" exception class
#include <sstream>
#include <string>
#include "Time.h" //indicates that member functions in Time.cpp belong to class Time (AKA includes class definition)

using namespace std;

void Time::setTime(int h, int m, int s){
if ((h>=0 && h<24) && (m>=0 && m<60) && (s>=0 && s<60)){    // lines 10-11 specify acceptable range of inputs
secondsSinceMidnight = h*3600 + m*60 + s;   // here the public member function setTime is modified to take the client's h,m,s input and save it under one variable, saving memory.
}

else {
throw invalid_argument(
"hour, minute, and/or second was out of range");
}
}

int Time::getHour() const { return secondsSinceMidnight / 3600; }   // public member functions in 20-22 uses secondsSinceMidnight to deliver h,m,s to client.
int Time::getMinute() const {return (secondsSinceMidnight%3600)/60; }
int Time::getSecond() const {return secondsSinceMidnight % 60; }

string Time::toUniversalString() const{
ostringstream output;
output << setfill('0') << setw(2) << getHour() << ":" << setw(2) << getMinute() << ":" << setw(2) << getSecond();
return output.str();
}

string Time::toStandardString() const{
ostringstream output;

int hour = getHour();

output << ((hour==0 || hour==12) ? 12:hour%12) << ":" << setfill('0') << setw(2) << getMinute() << ":" << setw(2) << getSecond() << (hour<12 ? "AM" : "PM");

return output.str();
}
