#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<int> > a(m,vector<int>(n));
    vector<vector<int> > dp(m+1,vector<int>(n+1,INT_MAX));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    dp[m][n-1]=1;
    dp[m-1][n]=1;
    for(int i=m-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            int need=min(dp[i+1][j],dp[i][j+1])-a[i][j];
            dp[i][j]=need<=0?1:need;
        }
    }
    cout<<dp[0][0];
    return 0;
}
