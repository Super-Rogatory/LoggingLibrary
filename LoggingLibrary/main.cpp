// Ctrl + F9
/*
    TestingProtocol *jerry = new TestingProtocol;
    std::cout << jerry->testingProtocol(5);
    */
    
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <cstring>
#include <fstream>
#include "LoggingPrototypes.h"
#include "DateTime.h"


bool Logging::openFile(const std::string &fileName) // will not store the string or create its own version of it, it will just utilize the string
{
    // try to open the file, if the file could not be opened.. display error.
    fs.open(fileName, std::fstream::in);
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
    auto mytime = ctime(&currenttime);  

    char *token = std::strtok(mytime, " ");
    while(token != nullptr){
        fulldatestream.push_back(token); //filling a vector so that I can retreive the month, day, year and time.
        token = std::strtok(nullptr, " ");
    }
    std::cout << std::endl; // for cleanliness
    month = fulldatestream[1];
    month = converter.convertMonth(month);
    
    day = fulldatestream[2];
    day = converter.convertDate(day);
    
    time = fulldatestream[3];
    
    year = fulldatestream[4];
    year = converter.convertYear(year);
 
    // add time
    std::cout << "[" << month << "-" << day << "-" << year <<  " " << time << "]";
}

void Logging::writelinenumtologFile(int num)
{
    // WRITES LINE NUMBER
    lineNumber = num;
    std::cout << " [LN:" << lineNumber << "] ";
}
void Logging::writefunctiontologFile(const std::string &funcMessage)
{
    std::cout << "[FN: " << funcMessage << "] ";
}
void Logging::writetypetologFile(const std::string &severityLevel){
    std::cout << "[" << severityLevel << "] ";
}
void Logging::writetexttologFile(const std::string &logMessage){ //the message is going to be sent from the other program in order to be logged into a text file. if divide by 0, log (invalid) etc etc.
    // create a vector to append the month day year, line number, message, warning and description. write that into log file.
    std::cout << " " << logMessage << std::endl;
    // WRITES 
}
bool Logging::closeFile()
{   
    // if the file is open, close it
    if(fs.is_open()) { fs.close(); } // ! TODO: throw exception, keep it barebones for now. !
    return true; 
}
// Assume we are creating our own library for open and close functionality

int main(){
    Logging test;
    test.openFile("jesse.txt");
    test.writetimetologFile();
    test.writelinenumtologFile(45);
    test.writefunctiontologFile("Polly");
    test.writetypetologFile("info");
    test.writetexttologFile("This is an information message");
    test.closeFile();
    return 0;
}

