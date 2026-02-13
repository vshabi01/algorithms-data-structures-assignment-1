// Last names Shabi, Alqaderi
// Question 2
// This program is interpreted correctly because the source-code file works with one variable, secondsSinceMidnight. Public member-functions have been tested. 

#include <string>
#ifndef TIME_H //lines 6,7, and 24 are called an include guard. It prevents multiple inclusions of the header file Time.h 
#define TIME_H

//this is the header file that provides the definition of the class Time. This is what will be given to the client.
class Time {

public: //function prototypes describe public interface without revealing member-function implementations that are described in Time.cpp
void setTime(int,int,int);
int getHour() const;
int getMinute() const;
int getSecond() const;
std::string toUniversalString() const;
std::string toStandardString() const;

private:
unsigned int secondsSinceMidnight{0};   // one variable will be used to store hours, minutes, and seconds.
};

#endif
