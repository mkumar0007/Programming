#include<bits/stdc++.h>
using namespace std;
int r,c;

int x[]={0,1,1,-1,1,0,-1,-1};
int y[]={1,0,1,1,-1,-1,0,-1};

bool valid(int i,int j)
{
    if(i<0 || i>=r || j<0 || j>=c)
        return false;
    return true;
}

bool isadjacent(char pre,char cur)
{
    return (cur-pre==1);
}

int getlenutil(char **mat,int i,int j,char prev,int **dp)
{
    if(!valid(i,j) || !isadjacent(prev,mat[i][j]))
    {
        return 0;
    }
    if(dp[i][j]!=-1)
        return dp[i][j];
    int ans=0;
    for(int k=0;k<8;k++)
    {
        ans=max(ans,1+getlenutil(mat,i+x[k],j+y[k],mat[i][j],dp));
    }
    return dp[i][j]=ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>r>>c;
    char **mat=new char*[r];
    for(int i=0;i<r;i++)
    {
        mat[i]=new char[c];
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>mat[i][j];
        }
    }
    int **dp=new int*[r];
    for(int i=0;i<r;i++)
    {
        dp[i]=new int[c];
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            dp[i][j]=-1;
        }
    }
    char ch;
    cin>>ch;
    int ans=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(mat[i][j]==ch)
            {
                for(int k=0;k<8;k++)
                {
                    ans=max(ans,1 + getlenutil(mat,i+x[k],j+y[k],ch,dp));
                }
            }
        }
    }
    cout<<ans;
    cin.tie(NULL);
    return 0;
}

