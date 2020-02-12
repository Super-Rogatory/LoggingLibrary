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
    fs.open(fileName, std::fstream::out | std::fstream::app);
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
    startWrite = true;
    lineNumber = num;
}
void Logging::writefunctiontologFile(const std::string &fmessage)
{
    startWrite = true;
    funcMessage = fmessage;
}
void Logging::writetypetologFile(const std::string &level)
{
    startWrite = true;
    severityLevel = level;
}
void Logging::writetexttologFile(const std::string &message)
{ //the message is going to be sent from the other program in order to be logged into a text file. if divide by 0, log (invalid) etc etc.
    startWrite = true;
    logMessage = message;
}
void Logging::writetoAll(const std::string &wholetext)
{
    writetimetologFile(); // creates time stamp
    int len = wholetext.length(); // in order to avoid convert std::string to char* error I am going to convert to myself.
    char char_array[len + 1]; // allocates n+1 size for the array due to "start from 0"
    strcpy(char_array, wholetext.c_str()); //copies wholetext into array
    
    // utilize the delimiter (|)
    if(!startWrite)
    {
        char *token = std::strtok(char_array, "|"); // creates a token of space, spaces in between month day and others can be pushed into vector
        while(token != nullptr)
        {
            loggingstream.push_back(token); //filling a vector so that I can retreive the month, day, year and time.
            token = std::strtok(nullptr, "|");
                
        }
        lineNumber = std::stoi(loggingstream[0]); // TODO: Try catch for lineNumber
        funcMessage = loggingstream[1];
        severityLevel = loggingstream[2];
        logMessage = loggingstream[3];
        compileLog();
    }
    
    else
    {
        char choice;
        std::string failstatement;
        std::cout << "You have utilzed one of more dependent functions. Utilize the writetoAll or a combination of dependent functions. \n";
        std::cout << "Clear data (restart)? : [y/n] ";
        choice = getchar();
        putchar(tolower(choice));
        if(choice == 'y')
        {
            clearLog();
        }
        std::cout << "\nPlease exit the application.";
    }
}
void Logging::clearLog()
{
        month = day = year = funcMessage = severityLevel = logMessage = {};
        lineNumber = 0;
}
void Logging::compileLog()
{
    fs << "[" << month << "-" << day << "-" << year <<  " " << time << "]";
    fs << " [LN:" << lineNumber << "] ";
    fs << "[FN: " << funcMessage << "] ";
    fs << "[" << severityLevel << "] ";
    fs << " " << logMessage << std::endl;    
    isCompile = true;
}
void Logging::readLog()
{
    
    if(isCompile)
    {
        std::cout << "[" << month << "-" << day << "-" << year <<  " " << time << "]";
        std::cout << " [LN:" << lineNumber << "] ";
        std::cout << "[FN: " << funcMessage << "] ";
        std::cout << "[" << severityLevel << "] ";
        std::cout << " " << logMessage << std::endl;  
    }
    
}
bool Logging::closeFile()
{   
    // if the file is open, close it
    if(fs.is_open()) { fs.close(); } // ! TODO: throw exception, keep it barebones for now. !
    return true; 
}
// Assume we are creating our own library for open and close functionality



