#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    string str;
    cin>>str;
    int n=str.length();
    bool dp[n][n];
    memset(dp,false,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        dp[i][i]=true;
    }
    int maxlen=1;
    int start=0;
    for(int i=0;i<(n-1);i++)
    {
        if(str[i]==str[i+1])
        {
            dp[i][i+1]=true;
            start=i;
            maxlen=2;
        }
    }
    for(int k=3;k<=n;k++)
    {
        for(int i=0;i<n-k+1;i++)
        {
            int j=i+k-1;
            if(str[i]==str[j] && dp[i+1][j-1])
            {
                dp[i][j]=true;
                if(k>maxlen)
                {
                    maxlen=k;
                    start=i;
                }
            }
        }
    }
    cout<<maxlen;
    cout<<str.substr(start,start+maxlen-1);
    cin.tie(NULL);
    return 0;
}
