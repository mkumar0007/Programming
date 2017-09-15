#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
    int s[n];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    cin>>m;
    int table[m+1];
    memset(table,0,sizeof(table));
    table[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=s[i];j<=m;j++)
        {
            table[j]+=table[j-s[i]];
        }
    }
    cout<<table[m];
    return 0;

}
