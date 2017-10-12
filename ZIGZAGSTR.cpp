#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    string str;
    getline(cin,str);
    int n;
    cin>>n;
    int len=str.length();
    int row=0;
    bool dir;
    string res[n];
    for(int i=0;i<len;i++)
    {
        res[row].push_back(str[i]);
        if(row==n-1)
        {
            dir=true;
        }
        else if(row==0)
        {
            dir=false;
        }
        dir?row--:row++;
    }
    for(int i=0;i<n;i++)
    {
        cout<<res[i];
    }
    cin.tie(NULL);
    return 0;
}
