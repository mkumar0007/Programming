#include<bits/stdc++.h>
using namespace std;

int win[8][3]={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};

bool valid(char *board,char c)
{
    for(int i=0;i<8;i++)
    {
        if(board[win[i][0]]==c && board[win[i][1]]==c && board[win[i][2]]==c )
        {
            return true;
        }
    }
    return false;
}

bool isvalidboard(char *board)
{
    int xc=0,oc=0;
    for(int i=0;i<9;i++)
    {
        if(board[i]=='X')
            xc++;
        else if(board[i]=='O')
            oc++;
    }
    if( xc==oc || xc==oc+1 )
    {
        if(valid(board,'O'))
        {
            if(valid(board,'X'))
                return false;
            return xc==oc;
        }
        else
        {
            if(valid(board,'X') && xc != oc+1)
                return false;
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    char *board=new char[9];
    for(int i=0;i<9;i++)
    {
        cin>>board[i];
    }
    if(isvalidboard(board))
        cout<<"YES";
    else
        cout<<"NO";
    cin.tie(NULL);
    return 0;
}
