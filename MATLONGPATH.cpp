#include<bits/stdc++.h>
using namespace std;
int n;
int longpathcell(int **mat,int **dp,int i ,int j)
{
    if(i<0 || i>=n || j<0 || j>=n)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(j<n-1 && mat[i][j]+1==mat[i][j+1])
        return dp[i][j]=1+longpathcell(mat,dp,i,j+1);
    if(j>0 && mat[i][j]+1==mat[i][j-1])
        return dp[i][j]=1+longpathcell(mat,dp,i,j-1);
    if(i>0 && mat[i][j]+1==mat[i-1][j])
        return dp[i][j]=1+longpathcell(mat,dp,i-1,j);
    if(i<n-1 && mat[i][j]+1==mat[i+1][j])
        return dp[i][j]=1+longpathcell(mat,dp,i+1,j);

    return dp[i][j]=1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    int **mat=new int*[n];
    for(int i=0;i<n;i++)
    {
        mat[i]=new int[n];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>mat[i][j];
        }
    }
    int **dp=new int*[n];
    for(int i=0;i<n;i++)
    {
        dp[i]=new int[n];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i][j]=-1;
        }
    }
    int res=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dp[i][j]==-1)
                longpathcell(mat,dp,i,j);
            res=max(res,dp[i][j]);
        }
    }
    cout<<res;
    cin.tie(NULL);
    return 0;
}
