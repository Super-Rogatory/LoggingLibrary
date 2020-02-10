// Ctrl + F9
/*
    TestingProtocol *jerry = new TestingProtocol;
    std::cout << jerry->testingProtocol(5);
    */
    
#include <iostream>
#include <iterator>
#include <vector>
#include <chrono>
#include <ctime>
#include <cstring>
#include <string>
#include <fstream>
#include "LoggingPrototypes.h"
#include "DateTime.h"


bool Logging::openFile(const std::string &fileName) // will not store the string or create its own version of it, it will just utilize the string
{
    // try to open the file, if the file could not be opened.. display error.
    fs.open(fileName, std::fstream::out);
    if(!fs.is_open()) { 
        std::cout << "Error opening file" << std::endl; // ! TODO: throw exception, keep it barebones for now. !
        return false; 
    } 
    return true;
}
// requires that the log file receives an error message and an integer for the line number
void Logging::writetimetologFile(){
    // THIS IS WHAT WRITES THE TIME
    auto currenttime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); 
    auto mytime = ctime(&currenttime);  //formats currentime into a more human like structure

    char *token = std::strtok(mytime, " "); // creates a token of space, spaces in between month day and others can be pushed into vector
    while(token != nullptr){
        fulldatestream.push_back(token); //filling a vector so that I can retreive the month, day, year and time.
        token = std::strtok(nullptr, " ");
    }

    month = fulldatestream[1];
    month = converter.convertMonth(month); //utilizes my very own converter. From Feb -> 02.
    
    day = fulldatestream[2];
    day = converter.convertDate(day);
    
    time = fulldatestream[3];
    
    year = fulldatestream[4];
    year = converter.convertYear(year);
}

void Logging::writelinenumtologFile(int num)
{
    lineNumber = num;
}
void Logging::writefunctiontologFile(const std::string &fmessage)
{
    funcMessage = fmessage;
}
void Logging::writetypetologFile(const std::string &level)
{
    severityLevel = level;
}
void Logging::writetexttologFile(const std::string &message)
{ //the message is going to be sent from the other program in order to be logged into a text file. if divide by 0, log (invalid) etc etc.
    logMessage = message;
}
void Logging::compileLog()
{
    /*
    // create a vector to append the month day year, line number, message, warning and description. write that into log file.
    loggingstream.push_back(month);
    loggingstream.push_back(day);
    loggingstream.push_back(year);
    loggingstream.push_back(time);
    // Converting
    std::string stringlineNumber = std::to_string(lineNumber);
    loggingstream.push_back(stringlineNumber);
    loggingstream.push_back(funcMessage);
    loggingstream.push_back(severityLevel);
    loggingstream.push_back(logMessage);
    */
    fs << "[" << month << "-" << day << "-" << year <<  " " << time << "]";
    fs << " [LN:" << lineNumber << "] ";
    fs << "[FN: " << funcMessage << "] ";
    fs << "[" << severityLevel << "] ";
    fs << " " << logMessage << std::endl;
    /*
    for(auto ptr = loggingstream.begin(); ptr < loggingstream.end(); ptr++)
    {
        std::cout << *ptr << " ";
    }
     * it works */
     
    isCompile = true;
    
    
}
void Logging::readLog()
{
    
    if(isCompile)
    {
        
    }
    else
    {
    
    }
    
}
bool Logging::closeFile()
{   
    // if the file is open, close it
    if(fs.is_open()) { fs.close(); } // ! TODO: throw exception, keep it barebones for now. !
    return true; 
}
// Assume we are creating our own library for open and close functionality

int main(){
    // delete soon! TODO:!
    Logging test;
    test.openFile("jesse.txt");
    test.writetimetologFile();
    test.writelinenumtologFile(45);
    test.writefunctiontologFile("Polly");
    test.writetypetologFile("info");
    test.writetexttologFile("This is a test to display a working logging system");
    test.compileLog();
    test.closeFile();
    return 0;
}

