#include <iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> v1 = {1,3};
    vector<int> v2 = {2};
    vector<int> v3;
    
    int l1=0,l2 = 0;
    
    // cout << v1[l1+1]<<"\n";

    while (l1 != v1.size() && l2 != v2.size())
    {
        if(v1[l1]<= v2[l2])
        {
            v3.push_back(v1[l1]);
            l1 += 1;
        }
        else
        {
            v3.push_back(v2[l2]);
            l2 += 1;
        }
    }

    while (l1 != v1.size())
    {
        v3.push_back(v1[l1]);
        l1 += 1;
    }

    while(l2 != v2.size())
    {
        v3.push_back(v2[l2]);
        l2 += 1;
    }

    // for (int i: v3)
    // {cout << i <<'\n';}

    if(v3.size()%2 == 0)
    {
        cout << 0.5*(  v3[ (v3.size()-1)/2 ] + v3[ v3.size()/2 ]  );
    }
    else
    {
        cout << v3[ (v3.size()-1)/2];
    }


    cout << endl;
}