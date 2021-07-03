#include <iostream>
#include <fstream>
#include <string.h>
#include <set>

using namespace std;

ifstream fin("data.in");
ofstream fout("data.out");

int toInt(string s)
{
    unsigned int number = 0;
    for(string::iterator i = s.begin(); i != s.end(); ++i)
        if(*i >= '0' && *i <= '9')
            number = number*10 + ( *i - '0' );
    return number;
}

template<typename T>
void getNumbers(set<T>&out,const string &numbers)
{
    int st = 0, found = numbers.find(",");
    while(found!=string::npos)
    {
        out.insert(toInt(numbers.substr(st,found-st)));
        st=found+1;
        found = numbers.find(",",st);
    }
}

template<typename T>
void printset(set<T>out)
{
    for(typename set<T>::iterator i = out.begin(); i != out.end(); ++i)
        fout<<*i<<endl;
}

int main()
{
    string numbers;
    set<int> out;
    getline(fin,numbers);
    getNumbers(out,numbers);
    printset(out);
}
