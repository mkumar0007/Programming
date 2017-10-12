#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    string str;
    getline(cin,str);
    int n=str.length();
    int dp[9];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    int res=0;
    int modsum=0,zero=0;
    for(int i=0;i<n;i++)
    {
        if(!(int)(str[i]-'0'))
            zero++;
        else
            zero=0;
        modsum+=(int)str[i]-'0';
        modsum%=9;
        res+=dp[modsum];
        dp[modsum]++;
        res-=zero;
    }
    cout<<res;
    cin.tie(NULL);
    return 0;
}
