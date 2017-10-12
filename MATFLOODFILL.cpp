#include<bits/stdc++.h>
using namespace std;
int r,c;
void floodfill(char **mat,int x,int y,char pre,char cur)
{
    if(x<0 || x>=r || y<0 || y>=c)
        return;
    if(mat[x][y]!=pre)
        return ;
    mat[x][y]=cur;
    floodfill(mat,x+1,y,pre,cur);
    floodfill(mat,x-1,y,pre,cur);
    floodfill(mat,x,y+1,pre,cur);
    floodfill(mat,x,y-1,pre,cur);
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
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(mat[i][j]=='O')
            {
                mat[i][j]='-';
            }
        }
    }
    for(int i=0;i<r;i++)
    {
        if(mat[i][0]=='-')
        {
            floodfill(mat,i,0,'-','O');
        }
    }
    for(int i=0;i<r;i++)
    {
        if(mat[i][c-1]=='-')
        {
            floodfill(mat,i,c-1,'-','O');
        }
    }
    for(int i=0;i<c;i++)
    {
        if(mat[0][i]=='-')
        {
            floodfill(mat,0,i,'-','O');
        }
    }
    for(int i=0;i<c;i++)
    {
        if(mat[r-1][i]=='-')
        {
            floodfill(mat,r-1,i,'-','O');
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(mat[i][j]=='-')
            {
                mat[i][j]='X';
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
