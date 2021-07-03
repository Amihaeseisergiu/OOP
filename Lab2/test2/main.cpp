#include <iostream>
#include <MyString.h>

using namespace std;

void f(int size)
{
    //stack // stiva
    char sir[255];

    //heap (alocare dinamica)
    char* sir2 = new char[size]; //new[]
    delete[] sir2;               //delete[]

    int* i = new int; //new
    delete i;         //delete
}

void f2()
{
    MyString s;
    MyString* s2=new MyString("Ana are mere");
    //MyString *sirString=new MyString[100];
    //delete[] sirString;
    s.Print();
    s2->Print();
}

int main()
{
    f2();
}
