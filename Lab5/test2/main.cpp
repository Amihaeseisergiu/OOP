#include <iostream>
#include <math.h>

using namespace std;

template <class T>
class List
{
    T * Elemente;
    int Count, Allocated;

public:

    List<T>();
    ~List<T>();
    bool Add(T &item);
    T&   operator[] (int index);
    void Sort();
};

template <class T>
List<T>::List()
{
    Count=0;
    Allocated=100;
    Elemente = new T[sizeof(T)*100];
}

template <class T>
List<T>::~List()
{
    Count=0;
    Allocated=0;
    delete[] Elemente;
}

template <class T>
bool List<T>::Add(T &item)
{
    if(Count>Allocated)
    {
        T* cpy=new T[sizeof(T)*Count];
        for(int i=0;i<=Count;++i)cpy[i]=Elemente[i];
        Elemente= new T[sizeof(T)*(Count+1)];
        for(int i=0;i<=Count;++i)Elemente[i]=cpy[i];
        Elemente[Count++]=item;
        Allocated++;
    }
    else Elemente[Count++]=item;
    return true;
}

template <class T>
T& List<T>::operator[] (int index)
{
    if(index>Allocated)return Elemente[0];
    return Elemente[index];
}

template <class T>
void List<T>::Sort()
{
    for(int i=0;i<Count-1;++i)
        for(int j=i+1;j<Count;++j)
            if(Elemente[i]>Elemente[j])
            {
                T aux=Elemente[i];
                Elemente[i]=Elemente[j];
                Elemente[j]=aux;
            }
}

class Point
{
    int x,y;
public:
    Point() : x(0), y(0) {}
    Point(int x1,int x2) {x=x1; y=x2;}
    Point(const Point &p2);
    friend bool operator> (const Point &p1,const Point &p2);
    void GetCoords();
};

Point::Point(const Point &p2)
{
    x=p2.x;
    y=p2.y;
}

bool operator> (const Point &p1,const Point &p2)
{
    double dist1=sqrt(p1.x*p1.x+p1.y*p1.y),dist2=sqrt(p2.x*p2.x+p2.y*p2.y);
    if(dist1 > dist2)return true;
        else return false;
}

void Point::GetCoords()
{
    cout<<x<<" "<<y<<" "<<endl;
}

int main()
{
    cout<<"Tip de baza:"<<endl;
    List<int> test;
    for(int i=100;i>=0;--i)test.Add(i);
    cout<<test[0]<<endl;
    test.Sort();
    for(int i=0;i<=100;++i)cout<<test[i]<<" ";
    cout<<endl<<"Tip point:"<<endl;
    List<Point> test2;
    for(int i=100;i>=0;--i)
    {
        Point p(i,i+1);
        test2.Add(p);
    }
    Point p=test2[0];
    p.GetCoords();
    test2.Sort();
    p=test2[0];
    p.GetCoords();
}
