#ifndef LOGGINGPROTOTYPES_H
#define LOGGINGPROTOTYPES_H
#include "DateTime.h"
class Logging{
 
public:   
    Logging() = default;
// open function
    bool openFile (const std::string &fileName);
    // close function
    bool closeFile ();
    // write function. To write to the log file.
    void writetimetologFile();
    void writetexttologFile(const std::string &logMessage);
    void writelinenumtologFile(int num);
    void writefunctiontologFile(const std::string &funcMessage);
    void writetypetologFile(const std::string &severityLevel);
    // read function
    // flush function
    ~Logging() {}
private:
    std::fstream fs;
    time_t dt;
    std::vector<std::string> fulldatestream{};
    std::string month, day, year, time{};
    int lineNumber;
    DateTime converter;
};

#endif