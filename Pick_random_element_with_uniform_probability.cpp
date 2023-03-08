/*
Given a stream of elements too large to store in memory, pick a random element from the stream with uniform probability.
Read: Reservoir Sampling. This problem is special case with k=1.
https://www.geeksforgeeks.org/reservoir-sampling/

*/



#include <iostream>
#include <vector>
#include <random>

using namespace std;


int unisel(vector<int>nums)
{
    int val = nums[0];
    int rand_index;
    int range;

    for(int i=1;i<nums.size();i++)
    {
        range = i + 1;
        rand_index = rand()%range;

        if(rand_index == 0) val = nums[i];
        cout << "value after iteration "<<i<<" "<<"is:"<<val<<endl;
    }
    return val;
}

int main()
{

    vector<int>ls = {4,3,2,5,6,7};
    cout <<unisel(ls)<<endl;
}


