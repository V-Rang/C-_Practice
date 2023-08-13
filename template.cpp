/*
using enum in template of C++ function
*/

#include<iostream>
using namespace std;

enum test{dog,cat,horse};

template<test some_val>
void caller(int a)
{
    if(some_val == 2) cout << a << endl;
    else printf("not printed\n");
}

int main()
{
    test var;
    var  = horse;

    int t = 14;
    caller<cat>(t);

    return 0;
}
