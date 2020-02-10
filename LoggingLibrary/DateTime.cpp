#include <iostream>
#include <vector>
#include "DateTime.h"

std::string DateTime::convertMonth(std::string month) 
{
    if(month == "Jan") { return "01"; }
    if(month == "Feb") { return "02"; }
    if(month == "Mar") { return "03"; }
    if(month == "Apr") { return "04"; }
    if(month == "May") { return "05"; }
    if(month == "Jun") { return "06"; }
    if(month == "Jul") { return "07"; }
    if(month == "Aug") { return "08"; }
    if(month == "Sep") { return "09"; }
    if(month == "Oct") { return "10"; }
    if(month == "Nov") { return "11"; }
    if(month == "Dec") { return "12"; }
    else { 
        //throw error 
    }
    return 0; // WATCH OUT
}
std::string DateTime::convertDate(std::string day){
    if(day.size() == 1) { return '0' + day; }
    else { return day; } 
}
std::string DateTime::convertYear(std::string year){
    year = year.substr(2,2);
    return year; // returns from starting position to a certain length
}