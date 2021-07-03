#include "Container.h"
#include <iostream>
using namespace std;

Lista::Lista()
{
    prim=NULL;
    ultim=NULL;
    urm=NULL;
}

bool Lista::Add(int value)
{
    if(prim==NULL)
    {
        prim=new Lista;
        prim->value=value;
        prim->urm=NULL;
        ultim=prim;
        return true;
    }
    else
    {
        Lista *p= new Lista;
        p->value=value;
        p->urm=NULL;
        ultim->urm=p;
        ultim=p;
        return true;
    }
}
bool Lista::Del(int value)
{
    if(prim==this)
        return false;
    Lista *p=new Lista;
    p=prim;
    if(p->value==value)
    {
        prim=p->urm;
        //delete p;
        return true;
    }
    while(p!=ultim && p->urm->value!=value )
        p=p->urm;
    if(p->urm==NULL)
        return false;
    if(p->urm==ultim && p->urm->value==value)
    {
        ultim=p;
        p->urm=NULL;
        //delete p->urm;
        return true;
    }
    if(p->urm->value==value)
    {
        Lista *q =new Lista;
        q=p->urm;
        p->urm=p->urm->urm;
        //delete q;
        return true;
    }

}
int Lista::Count(int value)
{
    Lista *p=new Lista;
    int c=0;
    p=prim;
    while(p!=NULL)
    {
        if(p->value==value)
            c++;
        p=p->urm;
    }
    return c;

}
bool Lista::Exists(int value)
{
    Lista *p=new Lista;
    p=prim;
    while(p!=NULL)
    {
        if(p->value==value)
            return 1;
        p=p->urm;
    }
    return 0;
}
int* Lista::GetSortedArray()
{
    Lista *p=new Lista;
    p=prim;
    int l=0;
    int aux;
    int i,j;
    while(p!=NULL)
    {
        l++;
        p=p->urm;
    }
    int* v=new int  [l*sizeof(int)];
    p=prim;
    l=0;
    while(p!=NULL)
    {
        v[l]=p->value;
        l++;
        p=p->urm;
    }
    for(i=0; i<l-1; i++)
        for(j=i+1; j<l; j++)
        {
            if(v[i]>v[j])
            {
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
        }
    return v;
}
int Lista::GetCount()
{
    Lista *p=new Lista;
    p=prim;
    int l=0;
    while(p!=NULL)
    {
        l++;
        p=p->urm;
    }
    return l;
}
Arbore::Arbore()
{
    st=NULL;
    dr=NULL;
    value=NULL;
}
bool Arbore::Add(int value)
{
    Arbore* newnode = new Arbore;
    newnode->value=value;
    Arbore* x = this;

    Arbore* y = NULL;

    while (x!=NULL) {
        y = x;
        if (value < x->value)
            x = x->st;
        else
            x = x->dr;
    }

    if (y == this && this->value==NULL)
        {
            this->value = value;
            delete newnode;
            return true;
        }
    else if (value < y->value)
        {
            y->st = newnode;
            return true;
        }
    else
        {
            y->dr = newnode;
            return true;
        }
    return false;
}

bool Arbore::Del(int value)
{
    Arbore *p=this,*q=this;
    while((p->st!=NULL || p->dr!=NULL ) && p->value!=value)
    {
        if(value>=p->value)
        {
            q=p;
            p=p->dr;
        }
        else if(value<p->value)
        {
            q=p;
            p=p->st;
        }
    }
    if(p->st==NULL && p->dr==NULL && p->value!=value)
    {
        return false;
    }
    if(p->st==NULL && p->dr==NULL)
    {
        if(q->st==p)
            {
                q->st=NULL;
                //delete p;
                return true;
            }
        else if(q->dr==p)
            {
                q->dr=NULL;
                //delete p;
                return true;
            }
        //delete p;
        return true;
    }
    else if(p->st!=NULL)
    {
        if(p->st->dr==NULL)
        {
            p->value=p->st->value;
            if(p->st->st!=NULL)
            {
                p->st=p->st->st;
                return true;
            }
            //delete p->st;
            p->st=NULL;
            return true;
        }
        q=p->st;
        while(q->dr->dr!=NULL)
            q=q->dr;
        p->value=q->dr->value;
        q->dr=q->dr->st;
        //delete r;
        return true;
    }
    else if(p->dr!=NULL)
    {
        if(p->dr->st==NULL)
        {
            p->value=p->dr->value;
            if(p->dr->dr!=NULL)
            {
                p->dr=p->dr->dr;
                return true;
            }
            //delete p->dr;
            p->dr=NULL;
            return true;
        }
        q=p->dr;
        while(q->st->st!=NULL)
            q=q->st;
        p->value=q->st->value;
        q->st=q->st->dr;
        //delete r;
        return true;
    }

}

int Arbore::GetCount()
{
    Arbore *a=new Arbore;
    a=this;
    Arbore cpy;
    int l=0;
    while(a->st!=NULL || a->dr!=NULL)
    {
        cpy.Add(a->value);
        a->Del(a->value);
        l++;
    }
    cpy.Add(a->value);
    a->value=cpy.value;
    cpy.Del(cpy.value);
    while(cpy.dr!=NULL || cpy.st!=NULL)
    {
        this->Add(cpy.value);
        cpy.Del(cpy.value);
    }
    this->Add(cpy.value);
    return ++l;
}

int* Arbore::GetSortedArray()
{
    int lung=GetCount();
    int* v=new int [4*lung];
    Arbore *a=new Arbore;
    a=this;
    int l=0;
    Arbore cpy;
    while(a->st!=NULL || a->dr!=NULL)
    {
        cpy.Add(a->value);
        v[l++]=a->value;
        a->Del(a->value);
    }
    v[l]=a->value;
    cpy.Add(a->value);
    a->value=cpy.value;
    cpy.Del(cpy.value);
    while(cpy.dr!=NULL || cpy.st!=NULL)
    {
        this->Add(cpy.value);
        cpy.Del(cpy.value);
    }
    this->Add(cpy.value);
    for(int i=0;i<l;++i)
        for(int j=i+1;j<=l;++j)
            if(v[j]<v[i])
            {
                int aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
    //for(int i=0;i<=l;++i)cout<<v[i]<<" ";
    return v;
}

bool Arbore::Exists(int value)
{
    Arbore *p=this,*q=this;
    while((p->st!=NULL || p->dr!=NULL ) && p->value!=value)
    {
        if(value>=p->value)
        {
            q=p;
            p=p->dr;
        }
        else if(value<p->value)
        {
            q=p;
            p=p->st;
        }
    }
    if(p->value!=value)
        return false;
    else return true;
}

int Arbore::Count(int value)
{
    int *v=GetSortedArray(),sum=0;
    for(int i=0;i<=GetCount();++i)
        if(v[i]==value)sum++;
    return sum;
}
