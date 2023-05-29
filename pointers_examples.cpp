#include<iostream>
#include<vector>
using namespace std;

int  main()
{

    //1.
    printf("Case 1\n");
    int *p = new int(4);
    p[0] = 14;
    p[1] = 15;
    p[2] = 16;
    p[3] = 17;

    for(int i=0;i<4;i++)
    {
        cout << p[i] << " " << *(p+i) << endl;
        // *(p+i) = i+5;
    }

    //2.
    printf("Case 2\n");
    vector<int> *q = new vector<int>{1,2,3,4};
    for(int i=0;i<4;i++)
    {
        cout << (*q)[i] << endl;
    }

    //3. 
    printf("Case 3\n");
    vector<int*>r = {p,p+1,p+2,p+3};
    for(int i=0;i<4;i++)
    {
        cout << *(r[i]) << endl;
    }



    return 0;
}