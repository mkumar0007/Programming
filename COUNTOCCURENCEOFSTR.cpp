#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    string x,y;
    getline(cin,x);
    getline(cin,y);
    int m=x.length();
    int n=y.length();
    int dp[m+1][n+1];
    for(int i=0;i<=n;i++)
    {
        dp[0][i]=0;
    }
    for(int i=0;i<=m;i++)
    {
        dp[i][0]=1;
    }

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[m][n];
    cin.tie(NULL);
    return 0;
}
