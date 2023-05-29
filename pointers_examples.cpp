#include<iostream>
#include<vector>

using namespace std;

int main()
{

    //1. 
    int *p = new int(4); // new returns a pointer
    // (*p) = 12; // or p[0]
    // *(p+1) = 14; // or p[1] ...
    for(int i=0;i<4;i++)
    {
        cout << p[i] << " "; // or cout << *(p+i) << " ";
    }
    cout << endl;

    //2. 
    vector<int>*q = new vector<int>{1,2,3,4};
    for(int i=0;i<4;i++)
    {
        // cout << *(q+i) << " "; // gives error
        // cout << q[i] << " "; // gives error
        cout << (*q)[i] << " "; //works
    }
    cout << endl;

    //3. 
    // vector<int*>r = vector<int>{1,2,3,4}; // wrong
    // vector<int*>r = vector<int*>{1,2,3,4}; // wrong 
    // for(int i=0;i<4;i++)
    // {
    //     cout << *(r[i]) << " ";
    // }
    // cout << endl;

    // int *t = new int(5);
    // for(int i=0;i<5;i++)
    // {
    //     *(t+i) = i+5; //test case , or t[i] = i+5;
    // }

    // vector<int*>r = vector<int*>{t,t+1,t+2,t+3,t+4}; //works, each element of vector<int*> has to be a pointer to an integer.
    // for(int i=0;i<5;i++) 
    // {
    //     cout << *( (*r)[i]  ) << " ";
    // }
    // cout << endl;


    // vector<int>*y = new vector<int>{12,13,14,15};
    // for(int i=0;i<4;i++)
    // {
    //     cout << (*y)[i] << " ";
    // }
    // cout << endl;

    int*a = new int(4);
    for(int i=0;i<4;i++)
    {
        a[i] = i+10;
    }

    vector<int*>b = {a,a+1,a+2,a+3};
    printf("Test values\n");
    for(int i=0;i<4;i++)
    {
        cout << a[i] << " " << *(a+i) << endl;
    }

    printf("Using b\n");
    for(int i=0;i<4;i++)
    {
        cout << *( b[i] ) << endl; //works
    }
    // cout << b[0] <<  endl;





    return 0;
}