#include <iostream>
#include <Container.h>
using namespace std;

int main()
{
    Arbore tree;
    Lista lis;
    cout<<"Liste:"<<endl;
    lis.Add(50);
    lis.Add(25);
    lis.Add(7);
    lis.Add(75);
    lis.Add(58);
    lis.Add(29);
    lis.Add(7);
    lis.Add(7);
    lis.Add(23);
    lis.Add(46);
    lis.Add(57);
    lis.Add(35);
    lis.Add(7);
    lis.Add(234);
    cout<<lis.GetCount()<<endl;
    lis.Del(234);
    cout<<lis.GetCount()<<endl;
    int *v1=lis.GetSortedArray();
    for(int i=0;i<lis.GetCount();++i)cout<<v1[i]<<" ";
    cout<<endl;
    cout<<lis.Count(7)<<endl;
    cout<<"Arbori:"<<endl;
    tree.Add(50);
    tree.Add(25);
    tree.Add(7);
    tree.Add(75);
    tree.Add(58);
    tree.Add(29);
    tree.Add(7);
    tree.Add(7);
    tree.Add(23);
    tree.Add(46);
    tree.Add(57);
    tree.Add(35);
    tree.Add(7);
    tree.Add(234);
    cout<<tree.GetCount()<<endl;
    tree.Del(235);
    cout<<tree.st->st->value<<endl;
    cout<<tree.GetCount()<<endl;
    int *v=tree.GetSortedArray();
    for(int i=0;i<tree.GetCount();++i)cout<<v[i]<<" ";
    cout<<endl;
    cout<<tree.Count(7);
}
