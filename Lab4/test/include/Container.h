#ifndef CONTAINER_H
#define CONTAINER_H


class Container {

   public:

      virtual bool Add(int value) = 0;

      virtual bool Del(int value) = 0;

      virtual int  Count(int value) = 0;

      virtual bool Exists(int value) = 0;

      virtual int* GetSortedArray() = 0;

      virtual int  GetCount() = 0;

};
class Lista:Container {
public:
    int value;
    Lista *prim;
    Lista *ultim;
    Lista *urm;
    Lista();

      bool Add(int value);

      bool Del(int value) ;

      int  Count(int value);

      bool Exists(int value);

      int* GetSortedArray() ;

      int  GetCount();

};
class Arbore:Container {
public:
    int value;
    Arbore *st,*dr;
    Arbore();
    bool Add(int value);

    bool Del(int value);

    int  Count(int value);

    bool Exists(int value);

    int* GetSortedArray();

    int  GetCount();

};
#endif // CONTAINER_H
