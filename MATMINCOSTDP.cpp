#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int r,c;
    cin>>r>>c;
    int a[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
    int dp[r][c];
    dp[r-1][c-1]=a[r-1][c-1]>0?1:abs(a[r-1][c-1])+1;
    for(int i=r-2;i>=0;i--)
    {
        dp[i][c-1]=max(dp[i+1][c-1]-a[i][c-1],1);
    }
    for(int i=c-2;i>=0;i--)
    {
        dp[r-1][i]=max(dp[r-1][i+1]-a[r-1][i],1);
    }
    for(int i=r-2;i>=0;i--)
    {
        for(int j=c-2;j>=0;j--)
        {
            int mp=min(dp[i+1][j],dp[i][j+1]);
            dp[i][j]=max(mp-a[i][j],1);
        }
    }
    cout<<dp[0][0];
    cin.tie(NULL);
    return 0;
}
