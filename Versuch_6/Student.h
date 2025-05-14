//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

class Student
{
public:
    Student();
    Student(std::string matNr, std::string name, std::string geburtstag, std::string address);
    std::string getMatNr() const;
    std::string getName() const;
    std::string getGeburtstag() const;
    std::string getAdresse() const;
    void ausgabe() const;
private:
    std::string matNr;
    std::string name;
    std::string geburtstag;
    std::string adresse;
};

#endif
