#include<iostream>

using namespace std;

bool isMatch(string s, string p)
{
    if(p.length()==0)
    {
        return s.length()==0;
    }


    if(p.length()>1 && p[1]=='*')
    {
        if(isMatch(s,p.substr(2))) return true; // eg p = c*aaa and s = aaa;

        if(  (p[0]=='.' || p[0]==s[0]) && s.length()>0 ) return isMatch(s.substr(1),p); // p=a*aa and s = aaaaaaaaaaaaaaaa;
        return false;
    }
    else
    {
        if( (p[0]=='.' || p[0]==s[0]) && s.length()>0) return isMatch(s.substr(1),p.substr(1));
        return false;
    }

}


int main()
{
    string s = "aaaaa";
    string p = "a*";

    cout <<isMatch(s,p)<<endl;
}
