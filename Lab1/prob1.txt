#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int v[100],n=-1;
    FILE* f=fopen("test.txt","r");
    if(!f)
    {
        cout<<"Nu s-a putut deschide!\n";
        return -1;
    }
    char line[255];
    while(fgets(line,255,f))
    {
        int numar=atoi(line);
        n++;
        v[n]=numar;
    }
    fclose(f);

    /*
    int m[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int v[9]={1,2,3,4,5,6,7,8,9};

    cout<<m[2][2]<<endl;

    int* ptr=(int*)m;
    cout<<*(ptr+2*3+2)<<endl;
    cout<<ptr[2*3+2]<<endl;
    */
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            if(v[i]>v[j])
            {
                int aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
    for(int i=0;i<n;i++)cout<<v[i]<<"\n";
    return 0;
}
