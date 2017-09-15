#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    int r=m,c=n;
    char a[m][n];
    char x='X';
    int k=0,l=0;
    while( k<m && l<n )
    {
        for(int i=l;i<n;i++)
        {
            a[k][i]=x;
        }
        k++;
        for(int i=k;i<m;i++)
        {
            a[i][n-1]=x;
        }
        n--;
        if(k<m)
        {
            for(int i=n-1;i>=l;i--)
            {
                a[m-1][i]=x;
            }
            m--;
        }
        if(l<n)
        {
            for(int i=m-1;i>=k;i--)
            {
                a[i][l]=x;
            }
            l++;
        }
        x=(x=='X')?'O':'X';
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
