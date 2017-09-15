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
    int k;
    cin>>k;
    int dp[k+1][n+1];
    for(int i=0;i<=k;i++)
    {
        dp[i][0]=0;
    }
    for(int j=0;j<=n;j++)
    {
        dp[0][j]=0;
    }
    int prevDiff;
    for(int i=1;i<=k;i++)
    {
        prevDiff=INT_MIN;
        for(int j=1;j<n;j++)
        {
            prevDiff=max(prevDiff,dp[i-1][j-1]-a[j-1]);
            dp[i][j]=max(dp[i][j-1],a[j]+prevDiff);
        }
    }
    cout<<dp[k][n-1];
    return 0;
}
