#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    string str;
    getline(cin,str);
    int n=str.length();
    stack<char> s;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='}' && !s.empty())
        {
            if(s.top()=='{')
                s.pop();
            else
                s.push(str[i]);
        }
        else
        {
            s.push(str[i]);
        }
    }
    int len=s.size();
    int x=0;
    while(!s.empty() && s.top()=='{')
    {
        s.pop();
        n++;
    }
    cout<<(len/2)+n%2;
    return 0;
}
