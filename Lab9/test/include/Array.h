#ifndef ARRAY_H
#define ARRAY_H


class Compare

{

public:

 virtual int CompareElements(void* e1, void* e2) = 0;

};

template<typename T>
class Objectcmp : public Compare
{
public:
    int CompareElements(void* e1, void* e2)
    {
        if(*(T*)e1 > *(T*)e2)return 1;
        else if(*(T*)e1 < *(T*)e2)return -1;
        return 0;
    }
};

template<class T>

class ArrayIterator

{

private:

 int Current; // mai adaugati si alte date si functii necesare pentru iterator
 //int Size;
 T** List;
public:

ArrayIterator()
{
     Current = 0;
     List = nullptr;
}

/*
 ArrayIterator(int index, T** Copy, int dim) : Current(index)
 {
    Size = dim;
    List = new T*[Size];

    for(int i = 0; i < Size; ++i)
    {
        List[i] = new T;
        *List[i] = *Copy[i];
    }
 }
*/
ArrayIterator(T*& Copy)
 {
    List = &Copy;
 }
 ~ArrayIterator()
 {
     //for(int i = 0; i < Size; ++i)
    //    delete List[i];
    //Size = 0;
 }

 ArrayIterator& operator ++ ()
 {
     //if(Current + 1 >= Size)throw "Invalid position";
     Current++;
     List++;
     return *this;
 }

 ArrayIterator& operator -- ()
 {
     //if(Current - 1 < 0)throw "Invalid position";
     Current--;
     List--;
     return *this;
 }

 bool operator= (ArrayIterator<T> &Copy)
 {
    Current = Copy.Current;
    //Size = Copy.Size;
    //List = new T*[Size];
    List = &Copy.List;
    //for(int i = 0; i < Size; ++i)
    //{
    //    List[i] = new T;
    //    *List[i] = *Copy[i];
    //}
    return true;
 }

 bool operator!=(ArrayIterator<T> &a)
 {
     return (List != a.List);
     //return (Current != a.Current);
 }


 T operator*()
 {
     return **List;
    //return *List[Current];
 }


 T* GetElement()
 {
     return *List;
 }

};

template<typename T>
int cmp(const T& x, const T& y)
{
    if(x > y)return 1;
    else if(x < y)return -1;
    return 0;
}

template<class T>

class Array

{

private:

 T** List; // lista cu pointeri la obiecte de tipul T*

 int Capacity; // dimensiunea listei de pointeri

 int Size; // cate elemente sunt in lista

public:

Array() // Lista nu e alocata, Capacity si Size = 0
{
    Capacity = Size = 0;
    List = nullptr;
}

~Array() // destructor
{
    for(int i = 0; i < Size; ++i)
        delete List[i];
    Capacity = Size = 0;
    delete[] List;
}

Array(int capacity) // Lista e alocata cu 'capacity' elemente
{
    Capacity = capacity;
    Size = 0;
    List = new T* [capacity];
}

Array(const Array<T> &otherArray) // constructor de copiere
{
    Size = otherArray.Size;
    Capacity = otherArray.Capacity;
    List = new T*[Capacity];

    for(int i = 0; i < Size; ++i)
    {
        List[i] = new T;
        *List[i] = *otherArray.List[i];
    }
}


T& operator[] (int index) // arunca exceptie daca index este out of range
{
    if(index >= Size || index < 0)throw "Index out of range";
    return *List[index];
}


const Array<T>& operator+=(const T &newElem) // adauga un element de tipul T la sfarsitul listei si returneaza this
{
    if(Size == Capacity)
    {
        Array tmp = *this;
        List = new T*[++Capacity];
        for(int i = 0; i < Size; ++i)
        {
            List[i] = new T;
            *List[i] = *tmp.List[i];
        }
    }
    List[Size] = new T;
    *List[Size++] = newElem;
    return *this;
}

const Array<T>& Insert(int index, const T &newElem) // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
{
        if(index < 0 || index >= Size + 1)throw "Element cant be added at index";

        if(Size == Capacity)
        {
            Array tmp = *this;
            List = new T*[++Capacity];
            for(int i = 0; i < Size; ++i)
            {
                List[i] = new T;
                *List[i] = *tmp.List[i];
            }
        }

        for(int i = Size - 1; i >= index; --i)
            List[i+1] = List[i];

        List[index] = new T;
        *List[index] = newElem;;
        Size++;
        return *this;
}

const Array<T>& Insert(int index, const Array<T> otherArray) // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
{
        if(index < 0 || index > Size + 1)throw "Array cant be added at index";

        if(Size + otherArray.Size > Capacity)
        {
            Array tmp = *this;
            Capacity = Size + otherArray.Size;
            List = new T*[Capacity];
            for(int i = 0; i < Size; ++i)
            {
                List[i] = new T;
                *List[i] = *tmp.List[i];
            }
        }

        for(int i = Size - 1; i >= index; i--)
            List[otherArray.Size + i] = List[i];

        for(int i = 0; i < otherArray.Size; ++i)
        {
            List[index + i] = new T;
            *List[index + i] = *otherArray.List[i];
        }
        Size = Size + otherArray.Size;
        return *this;
}

const Array<T>& Delete(int index) // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
{
    if(index < 0 || index >= Size)throw "Cant delete element at index";

    delete List[index];

    for(int i = index; i < Size - 1; ++i)
        List[i] = List[i+1];

    --Size;

    return *this;
}


bool operator=(const Array<T> &otherArray)
{
    Size = otherArray.Size;
    Capacity = otherArray.Capacity;
    List = new T*[Capacity];

    for(int i = 0; i < Size; ++i)
    {
        List[i] = new T;
        *List[i] = *otherArray.List[i];
    }
    return true;
}


void Sort() // sorteaza folosind comparatia intre elementele din T
{
    for(int i = 0; i < Size - 1; ++i)
        for(int j = i + 1; j < Size; ++j)
            if(*List[i] > *List[j])
            {
                T tmp;
                tmp = *List[i];
                *List[i] = *List[j];
                *List[j] = tmp;
            }
}

void Sort(int(*compare)(const T&, const T&)) // sorteaza folosind o functie de comparatie
{
     for(int i = 0; i < Size - 1; i++)
        for(int j = i + 1; j < Size; j++)
            if(compare(*List[i],*List[j]) == 1)
            {
                T tmp;
                tmp = *List[i];
                *List[i] = *List[j];
                *List[j] = tmp;
            }
}

void Sort(Compare *comparator) // sorteaza folosind un obiect de comparatie
{
    for(int i = 0; i < Size - 1; i++)
        for(int j = i + 1; j < Size; j++)
            if(comparator->CompareElements(List[i],List[j]) == 1)
            {
                T tmp;
                tmp = *List[i];
                *List[i] = *List[j];
                *List[j] = tmp;
            }
}


 // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista

int BinarySearch(const T& elem) // cauta un element folosind binary search in Array
{
    int st = 0, dr = Size - 1, mij = (Size - 1) / 2;
    while(st <= dr)
    {
        if(elem < *List[mij])
        {
            dr = mij - 1;
            mij = (st + dr)/2;
        }
        else if(elem > *List[mij])
        {
            st = mij + 1;
            mij = (st + dr)/2;
        }
        else return 1;
    }
    return 0;
}

int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) //  cauta un element folosind binary search si o functie de comparatie
{
    int st = 0, dr = Size - 1, mij = (Size - 1) / 2;
    while(st <= dr)
    {
        if(compare(elem, *List[mij]) == -1)
        {
            dr = mij - 1;
            mij = (st + dr)/2;
        }
        else if(compare(elem, *List[mij]) == 1)
        {
            st = mij + 1;
            mij = (st + dr)/2;
        }
        else return 1;
    }
    return 0;
}

int BinarySearch(const T& elem, Compare *comparator) //  cauta un element folosind binary search si un comparator
{
    int st = 0, dr = Size - 1, mij = (Size - 1) / 2;
    T tmp = elem;
    while(st <= dr)
    {
        if(comparator->CompareElements(&tmp, List[mij]) == -1)
        {
            dr = mij - 1;
            mij = (st + dr)/2;
        }
        else if(comparator->CompareElements(&tmp, List[mij]) == 1)
        {
            st = mij + 1;
            mij = (st + dr)/2;
        }
        else return 1;
    }
    return 0;
}


int Find(const T& elem) // cauta un element in Array
{
    for(int i = 0; i < Size; ++i)
        if(*List[i] == elem)return 1;
    return 0;
}

int Find(const T& elem, int(*compare)(const T&, const T&)) //  cauta un element folosind o functie de comparatie
{
    for(int i = 0; i < Size; ++i)
        if(compare(*List[i],elem) == 0)return 1;
    return 0;
}

int Find(const T& elem, Compare *comparator) //  cauta un element folosind un comparator
{
    T tmp = elem;
    for(int i = 0; i < Size; ++i)
        if(comparator->CompareElements(List[i],&elem) == 0)return 1;
    return 0;
}


int GetSize()
{
     return Size;
}

int GetCapacity()
{
     return Capacity;
}



ArrayIterator<T> GetBeginIterator()
{
    return ArrayIterator<T>(List[0]);
    //return ArrayIterator<T>(0,List,Size);
}

ArrayIterator<T> GetEndIterator()
{
    //return ArrayIterator<T>(Size,List,Size);
    return ArrayIterator<T>(List[Size]);
}

};

#endif // ARRAY_H
