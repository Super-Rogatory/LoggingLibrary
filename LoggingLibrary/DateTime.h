#ifndef DATETIME_H
#define DATETIME_H

class DateTime{
public:
    DateTime() = default;
    std::string convertMonth(std::string month);
    std::string convertDate(std::string day);
    std::string convertYear(std::string year);

private:
    
};




#endif