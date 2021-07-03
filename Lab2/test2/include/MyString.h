#ifndef MYSTRING_H
#define MYSTRING_H


class MyString
{
    //atributele clasei
    char *sir;
    int Size;
    int AllocatedSize;

public:
    MyString();
    MyString(const char* text);
    unsigned int GetSize();
    const char* GetText();
    void Set(const char *text);
    ~MyString();
};

#endif // MYSTRING_H
