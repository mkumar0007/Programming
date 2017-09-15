#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    int a[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    int dp[m][n];
    for(int i=0;i<m;i++)
    {
        dp[i][0]=a[i][0];
    }
    for(int i=0;i<n;i++)
    {
        dp[0][i]=a[0][i];
    }
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(a[i][j]==1)
            {
                dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            }
            else
            {
                dp[i][j]=0;
            }
        }
    }
    int maxofs=dp[0][0];
    int maxi,maxj;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(maxofs<dp[i][j])
            {
                maxofs=dp[i][j];
                maxi=i;
                maxj=j;
            }
        }
    }
    cout<<maxi<<endl;
    cout<<maxj<<endl<<maxofs<<endl;
    for(int i=maxi;i>maxi-maxofs;i--)
    {
        for(int j=maxj;j>maxj-maxofs;j--)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
