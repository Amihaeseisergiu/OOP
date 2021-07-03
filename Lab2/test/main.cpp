#include <iostream>
#include <MyString.h>

using namespace std;

int main()
{
    char text[]="test";
    MyString d("a"),p("ab"),*c;
    d.Set(text);
    cout<<d.GetText()<<"\n";
    c=d.SubString(0,2);
    cout<<c->GetText()<<"\n";
    d.Insert(3,"Ana");
    cout<<d.GetText();
}
