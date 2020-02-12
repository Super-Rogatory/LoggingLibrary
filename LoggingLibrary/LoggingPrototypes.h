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
    void writelinenumtologFile(int num);
    void writefunctiontologFile(const std::string &fmessage);
    void writetypetologFile(const std::string &level);
    void writetexttologFile(const std::string &message);
    void writetoAll(const std::string & wholetext);
    void clearLog();
    void compileLog(); // take the vector and reorder the output
    // read function
    void readLog(); // you can only read after the log has been compiled.
    // flush function
    ~Logging() {}
private:
    std::fstream fs;
    time_t dt {};
    std::vector<std::string> fulldatestream {};
    std::vector<std::string> loggingstream {}; //might delete soon
    std::string month, day, year, time {};
    std::string funcMessage, severityLevel, logMessage {};
    bool isCompile, startWrite;
    int lineNumber {};
    DateTime converter;
};

#endif