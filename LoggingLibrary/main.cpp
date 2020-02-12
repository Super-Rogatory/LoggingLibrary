#include <iostream>
#include <iterator>
#include <vector>
#include <chrono>
#include <ctime>
#include <cstring>
#include <string>
#include <fstream>
#include <numeric>
#include "LoggingPrototypes.h"
#include "DateTime.h"
const int MAX = 5;

int main()
{
    Logging log;
    double quotient, numerator, denominator{};
    std::cout << "Divide two numbers: ";
    std::cin >> numerator >> denominator;
    
    try{
        quotient = numerator / denominator;
        std::cout << "ANSWER: " << quotient << std::endl;
        if(denominator == 0) {
            throw 0;
        }
        
        
    }
    
    catch(int &ex)
    {
        std::cout << "ERROR: Cannot divide by zero" << std::endl;
        // 1.) First Use
        log.openFile("02_11_20_LOG.txt");
        log.writetoAll("22|MAIN()|ERROR|Attempted to divide by zero! Error Caught.");
        log.closeFile();
        
        log.openFile("02_11_20_LOG2.txt");
        log.writetimetologFile();
        log.writelinenumtologFile(22);
        log.writefunctiontologFile("Main()");
        log.writetypetologFile("ERROR");
        log.writetexttologFile("Attempted a divide by zero!");
        log.compileLog();
        log.closeFile();
    }

    
    
    return 0;
}