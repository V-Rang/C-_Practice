/*
Given an array of time intervals (start, end) for classroom lectures (possibly overlapping), find the minimum number of rooms required.

For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.


//IDEA:
Min halls needed = max halls occupied at a time.


*/


#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


int minhalls(int intervals[][2],int n)
{

    vector<pair<int,int>>Time;

    for(int i=0;i<n;i++)
    {
        Time.push_back({intervals[i][0],1});
        Time.push_back({intervals[i][1],-1});
    }

    sort(Time.begin(),Time.end());

/*
    for(int i=0;i<Time.size();i++)
    {
        cout << Time[i].first << " "<<Time[i].second << endl;
    }
*/

    int max_halls_at_a_time = 0;
    int halls_open  = 0;

    for(int i=0;i<Time.size();i++)
    {
        halls_open += Time[i].second;

        max_halls_at_a_time = max(halls_open,max_halls_at_a_time);
    }

    return max_halls_at_a_time;
}




int main()
{
    int intervals[][2] = { {30,75},{0,50},{60,150} };
    int n = sizeof(intervals)/sizeof(intervals[0]);
    cout << minhalls(intervals,n);



}
