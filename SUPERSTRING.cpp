#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    string X,Y;
    getline(cin,X);
    getline(cin,Y);
    string str="";
    int m=X.length();
    int n=Y.length();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0)
                dp[i][j]=j;
            else if(j==0)
                dp[i][j]=i;
            else if(X[i-1]==Y[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
        }
    }
    int index=dp[m][n];
    int i=m,j=n;
    while(i>0&&j>0)
    {
        if(X[i-1]==Y[j-1])
        {
            str.push_back(X[i-1]);
            i--;
            j--;
            index--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            str.push_back(Y[j-1]);
            j--;
            index--;
        }
        else
        {
            str.push_back(X[i-1]);
            i--;
            index--;
        }
    }
    while(i>0)
    {
        str.push_back(X[i-1]);
        i--;
        index--;
    }
    while(j>0)
    {
        str.push_back(Y[j-1]);
        j--;
        index--;
    }
    reverse(str.begin(),str.end());
    cout<<str;
    cin.tie(NULL);
    return 0;
}
