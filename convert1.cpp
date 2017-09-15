#include<bits/stdc++.h>
using namespace std;
int check(string a,string b,int m,int n)
{
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0)
            {
                dp[i][j]=j;
            }
            else if(j==0)
            {
                dp[i][j]=i;
            }
            else if(a[i-1]==b[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=1+min(dp[i][j-1],min((dp[i-1][j]),dp[i-1][j-1]));
            }
        }
    }
    return dp[m][n];
}
int main()
{
    string X,Y;
    cin>>X>>Y;
    int m=X.length();
    int n=Y.length();
    int y=check(X,Y,m,n);
    cout<<y;
    return 0;
}
