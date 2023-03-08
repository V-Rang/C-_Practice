/*
Given an array of integers and a number k, where 1 <= k <= length of the array, compute the maximum values of
each subarray of length k.

For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:

10 = max(10, 5, 2)
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)
Do this in O(n) time and O(k) space. You can modify the input array in-place and you do not need to store
 the results. You can simply print them out as you compute them.
*/

/*
THIS IS NOOB WAY OF SOLVING THIS PROBLEM:

*/
#include <iostream>
#include<map>
#include<string>
#include<vector>
#include<deque>

using namespace std;

void maxsub(vector<int>nums, int k)
{
    int n = nums.size();
    deque<int>Qi(k);
    int i;

    for(i=0;i<k;i++)
    {
        while(  (!Qi.empty()) && nums[i]>=nums[Qi.back()]) Qi.pop_back();

        Qi.push_back(i);
    }

    for(;i<n;i++)

    {

        cout << nums[Qi.front()] << " ";

        while(!Qi.empty() && i-k>=Qi.front()) Qi.pop_front();

        while(!Qi.empty() && nums[i]>=nums[Qi.back()]) Qi.pop_back();

        Qi.push_back(i);

    }
    cout << nums[Qi.front()] << " ";

}


int main()
{
    vector<int>nums = {1 ,2, 3, 1, 4, 5, 2, 3, 6};
    int k = 3;
    maxsub(nums,k);



}
