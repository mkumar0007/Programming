#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    string str;
    getline(cin,str);
    int n=str.length();
    stack<int> s;
    int cur_max=0,res=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='(')
        {
            cur_max++;
            res=max(res,cur_max);
        }
        else if(str[i]==')')
        {
            if(cur_max>0)
                cur_max--;
            else
                return -1;
        }
    }
    cin.tie(NULL);
    return cur_max!=0?-1:res;
}
