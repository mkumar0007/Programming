#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    string str;
    getline(cin,str);
    int n=str.length();
    bool flag=false;
    stack<char> s;
    for(int i=0;i<n;i++)
    {
        if(str[i]==')')
        {
            char top=s.top();
            s.pop();
            if(top=='(')
            {
                flag=true;
                break;
            }
            else
            {
                while(!s.empty() && s.top()!='(')
                {
                    s.pop();
                }
            }
        }
        else
        {
            s.push(str[i]);
        }
    }
    flag?cout<<"YES":cout<<"NO";
    cin.tie(NULL);
    return 0;
}
