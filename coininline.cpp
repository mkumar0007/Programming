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
    int dp[n][n];
    int i,j,gap,x,y,z;
    for(gap=0;gap<n;gap++)
    {
        for(i=0,j=gap;j<n;i++,j++)
        {
            x=(i+2<=j)?dp[i+2][j]:0;
            y=(i+1<=j-1)?dp[i+1][j-1]:0;
            z=(i<=j-2)?dp[i][j-2]:0;
            dp[i][j]=max(a[i]+min(x,y),a[j]+min(y,z));
        }
    }
    cout<<dp[0][n-1];
    return 0;
}
