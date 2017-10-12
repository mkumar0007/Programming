#include<bits/stdc++.h>
using namespace std;

int lcs(char *x,char *y,int m,int n)
{
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0)
            {
                dp[i][j]=0;
            }
            else if(x[i-1]==y[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

int insertions(char *str)
{
    int n=strlen(str);
    char rev[n+1];
    strcpy(rev,str);
    strrev(rev);
    return (n-lcs(str,rev,n,n));
}

int main()
{
    ios_base::sync_with_stdio(false);
    char str[20];
    cin>>str;
    cout<<insertions(str);
    cin.tie(NULL);
    return 0;
}
