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
    int k=0,m=r;
    int l=0,n=c;
    while(k<m && l<n)
    {
        for(int i=l;i<n;i++)
        {
            cout<<a[k][i]<<" ";
        }
        k++;
        for(int i=k;i<m;i++)
        {
            cout<<a[i][n-1]<<" ";
        }
        n--;
        if(k<m)
        {
            for(int i=n-1;i>=l;i--)
            {
                cout<<a[m-1][i]<<" ";
            }
            m--;
        }
        if(l<n)
        {
            for(int i=m-1;i>=k;i--)
            {
                cout<<a[i][l]<<" ";
            }
            l++;
        }
    }
    cin.tie(NULL);
    return 0;
}
