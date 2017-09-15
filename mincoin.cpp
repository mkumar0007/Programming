#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int m;
    cin>>m;
    int coin[m+1];
    coin[0]=0;
    for(int i=1;i<=m;i++)
    {
        coin[i]=INT_MAX;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int res=coin[i-a[j]];
            if(res!=INT_MAX&&res+1<coin[i])
                coin[i]=res+1;
        }
    }
    cout<<coin[m];
    return 0;
}
