#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <string>
#include <set>
using namespace std;

ifstream fin("data.in");
ofstream fout("data.out");

struct Comparator
{
	bool operator()( pair<string,int>x , pair<string,int>y) const
	{
		return x.second > y.second;

	}
};

void sensitive(string &s)
{
    for(int i = 0; i <= s.length(); ++i)
        if(s[i] >= 'A' && s[i] <= 'Z')s[i]=s[i]+32;
}

multiset<pair<string,int>, Comparator> toSet(map<string,int>a)
{
    multiset<pair<string,int>, Comparator> out;
    for(map<string,int>::iterator i = a.begin(); i != a.end(); ++i)
        out.insert(make_pair(i->first,i->second));
    return out;
}

void printset(multiset< pair<string,int>, Comparator>out)
{
    int j=0;
    for(multiset< pair<string,int>, Comparator>::iterator i = out.begin(); i != out.end() && j < 10; ++i, ++j)
        {
            fout<<i->first<<" "<<i->second<<endl;
        }
}

bool isLetter(char l)
{
    if((l >= 'a' && l <= 'z') || (l >= 'A' && l <= 'Z' ))return true;
    return false;
}

void tokenize(const string &s, map<string,int> &h)
{
    string word;
    int i = 0;
    while(s[i])
    {
        if(isLetter(s[i]))word.push_back(s[i++]);
            else if(!word.empty())
            {
                sensitive(word);
                h[word]++;
                word.erase();
                i++;
            }
                else i++;
    }
}

int main()
{
    string text;
    map<string,int> h;
    multiset<pair<string,int>, Comparator>x;
    getline(fin,text);
    tokenize(text,h);
    x=toSet(h);
    printset(x);
}
