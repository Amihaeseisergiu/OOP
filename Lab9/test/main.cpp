#include <iostream>
#include <Array.h>

using namespace std;

int main()
{
    Array<int> a;
    a += 3;
    a += 2;
    a += 1;
    Array<int> c;
    c += 5;
    c += 8;
    c += 4;
    a.Insert(0,c);
    Compare *b = new Objectcmp<int>;
    a.Sort(b);
    cout<<"Obiect Comparator:"<<boolalpha<<a.BinarySearch(1,b)<<"\n\n";
    cout<<"Functie de comparare:"<<boolalpha<<a.BinarySearch(2,cmp)<<"\n\n";
    auto start = a.GetBeginIterator();
    auto end = a.GetEndIterator();
    for(auto i = start; i != end; ++i)
        cout<<*i<<endl;
    try
    {
        try
        {
            a.Insert(20,3);
        }
        catch(const char* msg)
        {
            cout<<"Err: "<<msg<<endl;
        }
        try
        {
            a.Delete(-1);
        }
        catch(const char* msg)
        {
            cout<<"Err: "<<msg<<endl;
        }
        cout<<a[-1];
    }
    catch(const char* msg)
    {
        cout<<"Err: "<<msg<<endl;
    }
}
