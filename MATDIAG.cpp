#include<bits/stdc++.h>
using namespace std;
int r,c;
bool valid(int i,int j)
{
    if(i<0 || i>=r || j<0 || j>=c)
        return false;
    return true;
}

void print(int **a)
{
    for(int k=0;k<r;k++)
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
    for(int k=1;k<c;k++)
    {
        cout<<a[r-1][k]<<" ";
        int i=r-2;
        int j=k+1;
        while(valid(i,j))
        {
            cout<<a[i][j]<<" ";
            i--;
            j++;
        }
        cout<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
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
    print(a);
    cin.tie(NULL);
    return 0;
}
