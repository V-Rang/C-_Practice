/*

Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.

For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".

*/


#include<iostream>
#include<string>
#include<cstring>

using namespace std;
#define MAX_CHARS 26

bool isValid(int count[],int k)
{
    int val = 0;

    for(int i=0;i<MAX_CHARS;i++)
    {
        if(count[i] != 0 ) val++;
    }
    return (k>=val);
}

int ls(string s,int k)
{
    //count number of unique characters in string; if required(k) > total, return error if q says EXACTLY k, if ATMOST then
    //code can be commented.
    //
    int count[MAX_CHARS];

 /*
    int n_unique = 0;
    memset(count,0,sizeof(count));

    for(int i=0;i<s.size();i++)
    {
        if(count[s[i]-'a'] == 0) n_unique ++;

        count[s[i]-'a']++;
    }

    if(k>n_unique) return -1;
*/

    memset(count,0,sizeof(count));

    int curr_start = 0; int curr_end = 0;
    int max_window_start = 0; int max_window_size = 1;


    // initializing for case i=0

    count[s[0]-'a']++;
    curr_start = 0;

    for(int i=1;i<s.size();i++)
    {
        count[s[i]-'a'] ++;
        curr_end++;

        while(!isValid(count,k))
        {
            count[ s[curr_start]-'a']--;
            curr_start++;
        }



        if(curr_end-curr_start+ 1 > max_window_size)
        {
            max_window_start = curr_start;
            max_window_size = curr_end-curr_start+1;
        }
    }

    cout << s.substr(max_window_start,max_window_size)<<endl;

    return max_window_size;

}



int main()
{
    string s = "aaaaaaaabbe";
    int k = 2;
    cout <<ls(s,k) << " ";

    //cout << s.substr(1,4) << endl;
}
