#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    int C[n];
    bool dp[n][n];
    for(int i=0;i<n;i++)
    {
        dp[i][i]=true;
    }
    for(int k=2;k<=n;k++)
    {
        for(int i=0;i<n-k+1;i++)
        {
            int j=i+k-1;
            if(k==2)
                dp[i][j]= (s[i]==s[j]);
            else
                dp[i][j]= (s[i]==s[j]) && (dp[i+1][j-1]);
        }
    }
    for(int i=0;i<n;i++)
    {
        if(dp[0][i])
            C[i]=0;
        else
            C[i]=INT_MAX;
            for(int j=0;j<i;j++)
            {
                if(dp[j+1][i]&& 1+C[j]<C[i])
                {
                    C[i]=1+C[j];
                }
            }
    }
    cout<<C[n-1];
    return 0;
}
