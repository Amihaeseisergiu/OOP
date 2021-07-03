#include <iostream>
using namespace std;

#define ABC class
#define AAA public
#define INIT(number)  number(0)
#define CREATE(number); \
    Set_##number(int value){ number=value;} \
    Get_##number() { return number;}
ABC Test

{
    int x,y,z;

AAA:


    Test() : INIT(x), INIT(y), INIT(z) {}

    CREATE(x);

    CREATE(y);

    CREATE(z);

};

int main()

{

    Test t;

    t.Set_x(18);

    t.Set_y(24);

    #define AFISEAZA(number) cout<<(number)<<" "
    AFISEAZA(t.Get_x() + t.Get_y());

    #define CAT_TIMP(conditie) while(conditie){
    #define SFARSIT_CAT_TIMP }
    #define X_DIN_T t.Get_x()
    #define ESTE_DIFERIT_DE !=
    #define Y_DIN_T t.Get_y()
    #define MINUS -
    #define MAI_MARE_DECAT >
    #define DACA(conditie1,conditie2,conditie3) (conditie1?conditie2:conditie3)
    CAT_TIMP(X_DIN_T ESTE_DIFERIT_DE Y_DIN_T)
    DACA(X_DIN_T MAI_MARE_DECAT Y_DIN_T, t.Set_x(X_DIN_T MINUS Y_DIN_T), t.Set_y(Y_DIN_T MINUS X_DIN_T));

    SFARSIT_CAT_TIMP

    AFISEAZA(X_DIN_T);

    return 0;

}
