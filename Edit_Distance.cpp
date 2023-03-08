#include<iostream>
#include <cstring>
#include <vector>

using namespace std;
/*
int edist(string s1,string s2,int m, int n)
{
    if(m == 0) return n;

    if(n==0) return m;

    if(s1[m-1] == s2[n-1]) return edist(s1,s2,m-1,n-1);

    return 1+min( min(edist(s1,s2,m,n-1), edist(s1,s2,m-1,n)), edist(s1,s2,m-1,n-1));
}
*/
/*
int edist(string s1, string s2, int m, int n)
{
    int
}
*/

int edist(string s1, string s2, int m, int n)
{
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    //int dp[m+1][n+1];

    for(int i=0;i<=m;i++)
    {
        for(int j = 0;j<=n;j++)
        {
            if(i==0) dp[i][j] = j;

            else if(j==0) dp[i][j] = i;

            else if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1];

            else
                dp[i][j] = 1+ min(  min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
        }

    }
    return dp[m][n];
}


int main()
{
    string s1 = "kitten";
    string s2 = "sitting";
    int m = s1.length();
    int n = s2.length();

    cout<<edist(s1,s2,m,n) << " ";
    //vector<vector<int>>dp(m,vector<int>(n,0));
}
