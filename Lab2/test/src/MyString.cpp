#include "MyString.h"
#include <string.h>

MyString::MyString()
{
    sir=new char[16];
    *sir='\0';
    AllocatedSize=16;
    Size=0;
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

void MyString::Set(MyString &m)
{
    if(strlen(m.sir)+1>AllocatedSize)
    {
        delete sir;
        sir=new char[strlen(m.sir)+1];
        AllocatedSize=strlen(m.sir);
    }
    strcpy(sir,m.sir);
    Size=strlen(m.sir);
}

void MyString::Add(const char *text)
{
    if(strlen(text)+Size>AllocatedSize)
    {
        MyString tmp;
        tmp.Set(sir);
        delete sir;
        sir=new char[tmp.GetSize()+strlen(text)+1];
        strcpy(sir,tmp.sir);
        strcat(sir,text);
        Size=strlen(sir);
        AllocatedSize=Size;
    }
    else
        strcat(sir,text);
}

void MyString::Add(MyString &m)
{
    if(strlen(m.sir)+Size>AllocatedSize)
    {
        MyString tmp;
        tmp.Set(sir);
        delete sir;
        sir=new char[tmp.GetSize()+strlen(m.sir)+1];
        strcpy(sir,tmp.sir);
        strcat(sir,m.sir);
        Size=strlen(sir);
        AllocatedSize=Size;
    }
    else
        strcat(sir,m.sir);
}

const char* MyString::GetText()
{
    return sir;
}

MyString* MyString::SubString(unsigned int start,unsigned int size)
{
    if(start>Size || start<0 || start+size>Size)
        return NULL;
    char *tmp=new char[size];
    int cont=-1;
    for(int i=start; i<=start+size; i++)
    {
        cont++;
        tmp[cont]=sir[i];
    }
    tmp[cont+1]='\0';
    MyString *rtr=new MyString;
    rtr->Set(tmp);
    delete[] tmp;
    return rtr;
}

bool MyString::Delete(unsigned int start,unsigned int size)
{
    if(start>Size || start<0 || start+size>Size)
        return false;
    strcpy(sir+start,sir+start+size);
    Size=strlen(sir);
    return true;
}

int MyString::Compare(const char* text)
{
    return strcmp(sir,text);
}

int MyString::Compare(MyString& m)
{
    return strcmp(sir,m.sir);
}

char MyString::GetChar(unsigned int index)
{
    if(index<0 || index>Size)
        return 0;
    return sir[index];
}

bool MyString::Insert(unsigned int index,const char* text)
{
    if(index<0 || index>Size)
        return false;
    MyString tmp;
    if(strlen(text)+Size>AllocatedSize)
    {
        tmp.Set(sir);
        delete sir;
        sir=new char[strlen(text)+tmp.GetSize()+1];
        strcpy(sir,tmp.GetText());
    }
    tmp.Set(sir+index);
    strcpy(sir+index,text);
    strcpy(sir+index+strlen(text),tmp.GetText());
    Size=strlen(sir);
    AllocatedSize=Size;
    return true;
}

bool MyString::Insert(unsigned int index,MyString& m)
{
    if(index<0 || index>Size)
        return false;
    MyString tmp;
    if(strlen(m.sir)+Size>AllocatedSize)
    {
        tmp.Set(sir);
        delete sir;
        sir=new char[strlen(m.sir)+tmp.GetSize()+1];
        strcpy(sir,tmp.GetText());
    }
    tmp.Set(sir+index);
    strcpy(sir+index,m.sir);
    strcpy(sir+index+strlen(m.sir),tmp.GetText());
    Size=strlen(sir);
    AllocatedSize=Size;
    return true;
}

int MyString::Find(const char* text)
{

    for(int i=0;i<strlen(sir);i++)
    {
        bool test=true;
        for(int j=0;j<strlen(text);j++)
            if(sir[i+j]!=text[j])test=false;
        if(test==true)return i;
    }
    return 0;
}

int MyString::FindLast(const char* text)
{
    int value=0;
    for(int i=0;i<strlen(sir);i++)
    {
        bool test=true;
        for(int j=0;j<strlen(text);j++)
            if(sir[i+j]!=text[j])test=false;
        if(test==true)value=i;
    }
    return value;
}

MyString::~MyString()
{
    delete[] sir;
}
