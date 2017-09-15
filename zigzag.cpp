#include<bits/stdc++.h>
using namespace std;
int m,n;
bool valid(int i,int j)
{
    if(i<0||j<0||i>=m||j>=n)
        return false;
    return true;
}
int main()
{
    cin>>m>>n;
    int a[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int k=0;k<m;k++)
    {
        cout<<a[k][0]<<" ";
        int i=k-1;
        int j=1;
        while(valid(i,j))
        {
            cout<<a[i][j]<<" ";
            i--;
            j++;
        }
        cout<<endl;
    }
    for(int k=1;k<n;k++)
    {
        cout<<a[m-1][k]<<" ";
        int i=m-2;
        int j=k+1;
        while(valid(i,j))
        {
            cout<<a[i][j]<<" ";
            i--;
            j++;
        }
        cout<<endl;
    }
    return 0;
}
