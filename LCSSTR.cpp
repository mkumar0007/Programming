#include<bits/stdc++.h>
using namespace std;
#define N 100
int dp[N][N]={0};

int lcs(string X,string Y,int m,int n)
{
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0)
            {
                dp[i][j]=0;
            }
            else if(X[i-1]==Y[j-1])
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

set<string> findlcs(string X,string Y,int m,int n)
{
    set<string> s;
    if(m==0||n==0)
    {
        s.insert(" ");
        return s;
    }
    if(X[m-1]==Y[n-1])
    {
        set<string> str=findlcs(X,Y,m-1,n-1);
        for (set<string>::iterator iter = str.begin(); iter != str.end(); ++iter)
        {
            s.insert((*iter) + X[m-1]);
        }
    }
    else
    {
        if(dp[m-1][n] >= dp[m][n-1])
        {
            s=findlcs(X,Y,m-1,n);
        }
        if(dp[m][n-1] >= dp[m-1][n])
        {
            set<string> temp=findlcs(X,Y,m,n-1);
            s.insert(temp.begin(),temp.end());
        }
    }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    string X,Y;
    getline(cin,X);
    getline(cin,Y);
    int m=X.length();
    int n=Y.length();
    set<string> str;
    str=findlcs(X,Y,m,n);
    for (set<string>::iterator iter = str.begin(); iter != str.end(); ++iter)
    {
            cout<<(*iter)<<endl;
    }
    cin.tie(NULL);
    return 0;
}
