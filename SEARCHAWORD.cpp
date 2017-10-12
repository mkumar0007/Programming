#include<bits/stdc++.h>
using namespace std;

int R,C;

int x[]={-1,-1,-1,0,0,1,1,1};
int y[]={-1,0,1,-1,1,-1,0,1};

bool match(char **grid,int row,int col,string word)
{
    if(grid[row][col]!=word[0])
        return false;
    int len=word.length();
    for(int dir=0;dir<8;dir++)
    {
        int k;
        int rd=row+x[dir],cd=col+y[dir];
        for(k=1;k<len;k++)
        {
            if(rd>=R||rd<0||cd>=C||cd<0)
                break;
            if(grid[rd][cd]!=word[k])
                break;
            rd+=x[dir],cd+=y[dir];
        }
        if(k==len)
            return true;
    }
    return false;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin>>R>>C;
    char **grid=new char*[R];
    for(int i=0; i<R; i++)
    {
        grid[i] = new char[C];
    }
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cin>>grid[i][j];
        }
    }
    string word;
    cin>>word;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(match(grid,i,j,word))
            {
                cout<<"Found at ("<<i<<","<<j<<")"<<endl;
            }
        }
    }
    cin.tie(NULL);
    return 0;
}
