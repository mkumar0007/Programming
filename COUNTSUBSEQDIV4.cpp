#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    string str;
    getline(cin,str);
    int n;
    cin>>n;
    int len=str.length();
    int dp[len][n];
    memset(dp,0,sizeof(dp));
    dp[0][(str[0]-'0')%n]=1;
    for(int i=1;i<len;i++)
    {
        dp[i][(str[i]-'0')%n]++;
        for(int j=0;j<n;j++)
        {
            dp[i][j]+=dp[i-1][j];
            dp[i][(j*10+(str[i]-'0'))%n]+=dp[i-1][j];
        }
    }
    cout<<dp[len-1][0];
    cin.tie(NULL);
    return 0;
}
