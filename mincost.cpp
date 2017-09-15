#include<bits/stdc++.h>
#define r 3
#define c 3
using namespace std;

int check(int a[r][c],int m,int n)
{
    if(m<0||n<0)
        return INT_MAX;
    int dp[r][c];
    dp[0][0]=a[0][0];
    for(int i=1;i<=m;i++)
    {
        dp[i][0]=a[i][0]+dp[i-1][0];
    }
    for(int j=1;j<=n;j++)
    {
        dp[0][j]=a[0][j]+dp[0][j-1];
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=a[i][j]+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
        }
    }
    return dp[m][n];
}
int main()
{
    int a[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
    int m,n;
    cin>>m>>n;
    cout<<check(a,m,n);
    return 0;
}
