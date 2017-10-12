#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int r,c;
    cin>>r>>c;
    int **mat=new int*[r];
    for(int i=0;i<r;i++)
    {
        mat[i]=new int[c];
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>mat[i][j];
        }
    }
    bool row[r];
    bool col[c];
    memset(row,false,sizeof(row));
    memset(col,false,sizeof(col));
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(mat[i][j]==1)
            {
                row[i]=true;
                col[j]=true;
            }
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(row[i] || col[j])
            {
                mat[i][j]=1;
            }
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cin.tie(NULL);
    return 0;
}
