#include <iostream>
#include <BigNumber.h>

using namespace std;

int main()
{
    BigNumber a(100), b("2"), c;

    c = b / a;
    cout << (int)c << '\n';
    cout << a(0, 1) << '\n';

    c.Set("5628943");
    cout << (int)c << '\n';

    return 0;
}
