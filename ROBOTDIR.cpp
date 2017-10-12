#include<bits/stdc++.h>
using namespace std;
#define N 0
#define E 1
#define S 2
#define W 3
int main()
{
    ios_base::sync_with_stdio(false);
    char str[10];
    cin>>str;
    int x=0;
    int y=0;
    int dir=N;
    int n=strlen(str);
    for(int i=0;i<n;i++)
    {
        char ch=str[i];
        if(ch=='R')
            dir=(dir+1)%4;
        else if(ch=='L')
            dir=(4+dir-1)%4;
        else
        {
            if(dir==N)
                y++;
            else if(dir==E)
                x++;
            else if(dir==S)
                y--;
            else
                x--;
        }
    }
    cout<<x<<" "<<y<<endl;
    x==0&&y==0?cout<<"YES":cout<<"NO";
    cin.tie(NULL);
    return 0;
}
