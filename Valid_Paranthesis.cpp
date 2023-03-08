#include <iostream>
#include<map>
#include<stack>
using namespace std;

bool isValid(string s)
{

    map<char,char>corr=  { {']','['},
                            {'}','{'},
                            {')','('} };
    stack<char>stacky;

    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='['||s[i]=='{'||s[i]=='(')
            {
                stacky.push(s[i]);
                continue;
            }

        if(s[i]==']'||s[i]=='}'||s[i]==')')
        {
            if(stacky.top() != corr[s[i]) return false;

            stack.pop()
        }

    }

}

int main()
{
    string s = "(){}[]";

    cout <<isValid(s) << " ";
}
