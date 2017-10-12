#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int r,c;
    cin>>r>>c;
    int **a=new int*[r];
    for(int i=0;i<r;i++)
    {
        a[i]=new int[c];
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
    int s[r][c];
    for(int i=0;i<c;i++)
    {
        s[i][0]=a[i][0];
    }
    for(int j=0;j<r;j++)
    {
        s[0][j]=a[0][j];
    }
    for(int i=1;i<r;i++)
    {
        for(int j=1;j<c;j++)
        {
            if(a[i][j]==1)
            {
                s[i][j]=min(s[i-1][j],min(s[i][j-1],s[i-1][j-1]))+1;
            }
            else
            {
                s[i][j]=0;
            }
        }
    }
    int maxofs=s[0][0],maxi=0,maxj=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(s[i][j]>maxofs)
            {
                maxi=i;
                maxj=j;
                maxofs=s[i][j];
            }
        }
    }
    for(int i=maxi;i>maxi-maxofs;i--)
    {
        for(int j=maxj;j>maxj-maxofs;j--)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cin.tie(NULL);
    return 0;
}
