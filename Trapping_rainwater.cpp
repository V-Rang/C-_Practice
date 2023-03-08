#include<iostream>
#include<vector>

using namespace std;

int maxw(vector<int>wh)
{
    int n = wh.size();

    int left[n];
    int right[n];

    int maxl = wh[0];
    int maxr = wh[n-1];

    for(int i=1;i<=n-2;i++)
    {
        maxl = max(maxl,wh[i-1]);
        left[i] = maxl;

    }

    for(int i=n-2;i>=1;i--)
    {
        maxr = max(maxr,wh[i+1]);
        right[i] = maxr;
    }

    int tot_vol = 0;

    for(int i=1;i<=n-2;i++)
    {
        int vol = min(left[i],right[i]) - wh[i];
        if(vol > 0) tot_vol += vol;
    }

    return tot_vol;

}


int main()
{
    vector<int>wh = {3,0,1,3,0,5};
    cout <<maxw(wh) << " ";


}
