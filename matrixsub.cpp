#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int A[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>A[i][j];
        }
    }
    int B[n][n];
    for(int i=0;i<n;i++)
    {
        B[i][0]=A[0][i];
    }
    for(int i=0;i<n;i++)
    {
        B[0][i]=A[i][0];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(A[i][j]==1)
            {
                B[i][j]=1+min(A[i][j-1],min(A[i-1][j],A[i-1][j-1]));
            }
            else
            {
                B[i][j]=0;
            }
        }
    }
    int maxi=0,maxj=0,maxofs=B[0][0];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(maxofs < B[i][j])
            {
                maxofs=B[i][j];
                maxi=i;
                maxj=j;
            }
        }
    }
    for(int i=maxi;i>maxi-maxofs;i--)
    {
        for(int j=maxj;j>maxj-maxofs;j--)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
