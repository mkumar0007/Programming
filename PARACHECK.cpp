#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    string str;
    getline(cin,str);
    int n=str.length();
    int m=0,cm=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='(')
        {
            cm++;
            if(cm>m)
            {
                m=cm;
            }
        }
        else if(str[i]==')')
        {
            if(cm>0)
            {
                cm--;
            }
            else
            {
                return -1;
            }
        }
    }
    if(cm!=0)
        return -1;
    cout<<m;
    cin.tie(NULL);
    return 0;
}
