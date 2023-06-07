/*
Example demonstrating:
1. Pass by value
2. Pass by reference
3. Pass by address

Difference between pass by reference and pass by address: 
https://stackoverflow.com/questions/52177329/differences-between-passing-by-reference-and-passing-by-address
*/

//1. Pass by value
// #include<iostream>

// using namespace std;

// void func(int a);

// int main()
// {
//     int b = 32;
//     cout << "Value before function call = " << b << endl;
//     func(b);
//     cout << "Value after function call = " << b << endl;


//     return 0;
// }


// void func(int a)
// {
//     a = 64;
//     cout <<"Value inside function = " << a << endl;
// }

//2. Pass by reference
// #include<iostream>

// using namespace std;

// void func(int &a);

// int main()
// {
//     int b = 32;
//     cout << "Value before function call = " << b << endl;
//     func(b);
//     cout << "Value after function call = " << b << endl;


//     return 0;
// }


// void func(int &a)
// {
//     a = 64;
//     cout <<"Value inside function = " << a << endl;
// }


//3. Pass by address
#include<iostream>

using namespace std;

void func(int *a);

int main()
{
    int b = 32;
    cout << "Value before function call = " << b << endl;
    func(&b);
    cout << "Value after function call = " << b << endl;


    return 0;
}


void func(int *a)
{
    *a = 64;
    cout <<"Value inside function = " << *a << endl;
}
