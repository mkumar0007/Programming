#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int k;
    cin>>n>>k;
    int egg[n+1][k+1];
    for(int i=1;i<=n;i++)
    {
        egg[i][1]=1;
        egg[i][0]=0;
    }
    for(int j=1;j<=k;j++)
    {
        egg[1][j]=j;
    }
    int res;
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=k;j++)
        {
            egg[i][j]=INT_MAX;
            for(int x=1;x<=j;x++)
            {
                res=1+max(egg[i-1][x-1],egg[i][j-x]);
                egg[i][j]=min(res,egg[i][j]);
            }
        }
    }
    cout<<egg[n][k];
    return 0;
}
