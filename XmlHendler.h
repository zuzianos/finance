#ifndef XmlHendler_H
#define XmlHendler_H
#include <iostream>


using namespace std;

class XmlHendler{

const string FILE_NAME;

public:
    XmlHendler(string fileName) : FILE_NAME(fileName) {};
    string getFileName();
    bool IsFileEmpty();
};
#endif
