#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n][n];
    int dp[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        dp[0][i]=sum+a[0][i];
        sum=dp[0][i];
    }
    sum=0;
    for(int i=0;i<n;i++)
    {
        dp[i][0]=sum+a[i][0];
        sum=dp[i][0];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            dp[i][j]=a[i][j]+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
        }
    }
    cout<<dp[n-1][n-1];
    return 0;
}
