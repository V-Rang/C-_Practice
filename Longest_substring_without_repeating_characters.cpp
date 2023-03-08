#include <iostream>
#include <map>


using namespace std;

int main()
{
    string s = "abcabcbb";
    map <char,int> chars;
    int l=0,r=0;
    int maxl;

    while (r != s.length())
    {
        auto it = chars.find(s[r]);
        if(it != chars.end() && it->second >=l) // found
        {
            l = it->second+1;
            
        }
        else
        {
            maxl = max(maxl,r-l+1);

        }
        chars[s[r]] = r;
        r += 1;
    }
    
    cout << maxl << '\n';


}