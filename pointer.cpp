#include <iostream>
using namespace std;

int addition(int a, int b)
{
    return (a+b);
}

int subtraction(int a, int b)
{
    return (a-b);
}

int operation(int x, int y, int (functocall)(int,int))
{
    int g;
    g = (functocall)(x,y);
    return g;
}

int main()
{
    int m,n;
    int (*minus) = subtraction;
    cout<<operation(1,1,minus)<<endl;
    cout<<operation(1,1,addition);
}
