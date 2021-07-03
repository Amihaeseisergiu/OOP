#include <iostream>
#include <vector>
#include <functional>

using namespace std;

template<typename T>
int partition (vector<T> &lista, int low, int high, int (*Compare)(T &e1, T &e2))
{
    T pivot = lista[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (Compare(lista[j],pivot) == -1)
        {
            i++;
            T tmp = lista[i];
            lista[i] = lista[j];
            lista[j] = tmp;
        }
    }
    T tmp = lista[i+1];
    lista[i+1] = lista[high];
    lista[high] = tmp;
    return (i + 1);
}

template<typename T>
int partition (vector<T> &lista, int low, int high, function<int(T &e1,T &e2)> cmp)
{
    T pivot = lista[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (cmp(lista[j],pivot) == -1)
        {
            i++;
            T tmp = lista[i];
            lista[i] = lista[j];
            lista[j] = tmp;
        }
    }
    T tmp = lista[i+1];
    lista[i+1] = lista[high];
    lista[high] = tmp;
    return (i + 1);
}

template<typename T>
void quickSort(vector<T> &lista, int low, int high, int (*Compare)(T &e1, T &e2))
{
    if (low < high)
    {
        int pi = partition(lista, low, high, Compare);

        quickSort(lista, low, pi - 1, Compare);
        quickSort(lista, pi + 1, high, Compare);
    }
}

template<typename T>
void quickSort(vector<T> &lista, int low, int high, function<int(T &e1,T &e2)> cmp)
{
    if (low < high)
    {
        int pi = partition(lista, low, high, cmp);

        quickSort(lista, low, pi - 1, cmp);
        quickSort(lista, pi + 1, high, cmp);
    }
}

template <class T>
void Sort(std::vector<T> lista, int (*Compare)(T &e1, T &e2))
{
    quickSort(lista, 0, lista.size() - 1, Compare);
    for(auto it: lista)
        cout<<it<<" ";
    cout<<endl;
}

template <class T>
void Sort(vector<T> lista, function<int(T &e1, T &e2)> cmp)
{
    quickSort(lista, 0, lista.size() - 1, cmp);
    for(auto it: lista)
        cout<<it<<" ";
    cout<<endl;
}


int main()
{
    ///Using pointer to function
    vector<int> numbers = { 30, 41, 50, 19 };
    auto f = +[](int& a, int& b)->int { return a > b ? 1 : (a < b?(-1):0); };
    Sort(numbers, f);
    ///Using std::function
    int ar = 0;
    vector<int> numbers2 = { 6, 5, 4, 3, 2, 1 };
    function<int(int&,int&)>cmp;
    cmp = [ar](int& a, int& b)->int { return (a+ar) > b ? 1 : (a < b?(-1):0); };
    Sort(numbers2, cmp);
    return 0;
}
