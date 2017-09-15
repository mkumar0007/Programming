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
    int i=0,j=0,k=0;
    bool isup=true;
    while(k<m*n)
    {
        if(isup)
        {
            while(valid(i,j))
            {
                cout<<a[i][j]<<" ";
                i--;
                j++;
                k++;
            }
            cout<<endl;
            if (i < 0 && j<=n-1)
                i = 0;
            if (j == n)
                i = i+2 , j--;
        }
        else
        {
            while(valid(i,j))
            {
                cout<<a[i][j]<<" ";
                i++;
                j--;
                k++;
            }
            cout<<endl;
            if (j < 0 && i<=m-1)
                j = 0;
            if (i == m)
                j = j+2 , i--;
        }
        isup=!isup;
    }
    return 0;
}
