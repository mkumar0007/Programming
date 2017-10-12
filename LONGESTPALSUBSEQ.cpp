#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    char str[20];
    gets(str);
    int n=strlen(str);
    int dp[n][n];
    for(int i=0;i<n;i++)
    {
        dp[i][i]=1;
    }
    for(int k=2;k<=n;k++)
    {
        for(int i=0;i<n-k+1;i++)
        {
            int j=i+k-1;
            if(str[i]==str[j]&&k==2)
            {
                dp[i][j]=2;
            }
            else if(str[i]==str[j])
            {
                dp[i][j]=dp[i+1][j-1]+2;
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
            }
        }
    }
    cout<<dp[0][n-1];
    cin.tie(NULL);
    return 0;
}
