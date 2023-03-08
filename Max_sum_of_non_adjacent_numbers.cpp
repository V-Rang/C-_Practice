/*
This problem was asked by Airbnb.

Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.

Follow-up: Can you do this in O(N) time and constant space?

*/


#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lsum(vector<int>ls)
{

    // Method1
/*
    int n = ls.size();

    if(n==1) return ls[0];

    int dp[n][2];

    dp[0][0] = 0;

    dp[0][1]  = ls[0];

    for(int i=1;i<=n-1;i++)
    {
        dp[i][1] = dp[i-1][0] + ls[i];
        dp[i][0] = max(dp[i-1][1],dp[i-1][0]);
    }

    return max(dp[n-1][0],dp[n-1][1]);
*/

    // Method 2

    int n = ls.size();

    if(n==1) return ls[0];
    int incl = ls[0];
    int excl = 0;
    int excl_new;
    for(int i=1;i<=n-1;i++)
    {
        excl_new = max(incl,excl);
        incl = excl + ls[i];
        excl = excl_new;
    }

    return max(incl,excl);



}

int main()
{

    vector<int>ls={5,1,1,5};
    int val = 0;
    cout << lsum(ls) << " ";

}
