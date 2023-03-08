/*
A builder is looking to build a row of N houses that can be of K different colors. He has a goal of minimizing cost while
ensuring that no two neighboring houses are of the same color.

Given an N by K matrix where the nth row and kth column represents the cost to build the nth house with kth color,
return the minimum cost which achieves this goal.

*/
#include<iostream>
#include <vector>

using namespace std;


int mincost(vector<vector<int>>costs)
{
  int N = costs.size();
  int K = costs[0].size();
  int minval;
  int i,j,k;

  //int dp[N-1][K-1] = 0;

  vector<vector<int>>dp(N,vector<int>(costs[0].size(),0));

  for(int i=0;i<K;i++)
  {
      dp[0][i] = costs[0][i];
  }


  for(i=1;i<N;i++)
  {
      for(j=0;j<K;j++)
      {
            minval  = INT_MAX;
            for(k=0;k<K;k++)
            {
                if(k==j) continue;
                minval = min(minval,dp[i-1][k]);
            }
            dp[i][j] = minval + costs[i][j];
      }

  }

  minval = INT_MAX;

  for(i=0;i<K;i++)
  {
      minval = min(minval,dp[N-1][i]);
  }

  return minval;
}

int main()
{
    vector<vector<int>>costs{ {14,2,11},
                              {11,14,5},
                              {14,3,10}};

    cout << mincost(costs)<<endl; //(2,5,3) = 10.
}
