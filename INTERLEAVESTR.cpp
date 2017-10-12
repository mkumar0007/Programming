#include<bits/stdc++.h>
using namespace std;

bool interleave(char *x,char *y,char *z)
{
    int m=strlen(x);
    int n=strlen(y);
    if(m+n!=strlen(z))
        return false;
    int dp[m+1][n+1];
    memset(dp,false,sizeof(dp));
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 && j==0)
            {
                dp[i][j]=true;
            }
            else if(i==0 && y[j-1]==z[j-1])
            {
                dp[i][j]=dp[i][j-1];
            }
            else if(j==0 && x[i-1]==z[i-1])
            {
                dp[i][j]=dp[i-1][j];
            }
            else if(x[i-1]==z[i+j-1] && y[j-1]!=z[i+j-1])
            {
                dp[i][j]=dp[i-1][j];
            }
            else if(x[i-1]!=z[i+j-1] && y[j-1]==z[i+j-1])
            {
                dp[i][j]=dp[i][j-1];
            }
            else if(x[i-1]==z[i+j-1] && y[j-1]==z[i+j-1])
            {
                dp[i][j]=dp[i-1][j] || dp[i][j-1];
            }
        }
    }
    return dp[m][n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    char x[20],y[20],z[20];
    cin>>x>>y>>z;
    (interleave(x,y,z))?cout<<"YES":cout<<"NO";
    cin.tie(NULL);
    return 0;
}
