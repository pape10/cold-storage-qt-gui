#include<string>
#include<iostream>
#include<fstream>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctime>
namespace c {
std::string generate_rand4()
{
    time_t currentTime;
     struct tm *localTime;

     time( &currentTime );                   // Get the current time
     localTime = localtime( &currentTime );  // Convert the current time to the local time

     int Day    = localTime->tm_mday;
     int Month  = localTime->tm_mon + 1;
     int Year   = localTime->tm_year + 1900;
     int Hour   = localTime->tm_hour;
     int Min    = localTime->tm_min;
     int Sec    = localTime->tm_sec;
    std::string d = std::to_string(Day);
    std::string mo = std::to_string(Month);
    std::string y = std::to_string(Year);
    std::string h = std::to_string(Hour);
    std::string m = std::to_string(Min);
    std::string s = std::to_string(Sec);
    std::string f = "";
    f= f + d + mo +y +h + m + s;
    return f;
}
}
