#include "MyString.h"
#include <iostream>
#include <string.h>

using namespace std;

MyString::MyString()
{
    AllocatedSize=16;
    Size=0;
    sir = new char[AllocatedSize];
}

MyString::MyString(const char* text)
{
    AllocatedSize=strlen(text)+1;
    Size=strlen(text);
    sir = new char[AllocatedSize];
    strcpy(sir,text);
}

unsigned int MyString::GetSize()
{
    return Size;
}

const char* MyString::GetText()
{
    return sir;
}

void MyString::Set(const char *text)
{
    if(strlen(text)+1 > AllocatedSize)
    {
        delete sir;
        sir = new char[strlen(text)+1];
        AllocatedSize = strlen(text) + 1;
    }
    strcpy(sir,text);
    Size=strlen(text);
}

MyString::~MyString()
{
    delete[] sir;
}
