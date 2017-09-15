#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    int m=a.length();
    int n=b.length();
    int L[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0)
            {
                L[i][j]=0;
            }
            else if(a[i-1]==b[j-1])
            {
                L[i][j]=L[i-1][j-1]+1;
            }
            else
            {
                L[i][j]=max(L[i-1][j],L[i][j-1]);
            }
        }
    }
    int x=L[m][n];
    cout<<x<<endl;
    int i=m,j=n;
    char lcs[x+1];
    lcs[x]='\0';
    while(i>0&&j>0)
    {
        if(a[i-1]==b[j-1])
        {
            lcs[x-1]=a[i-1];
            x--;
            i--;
            j--;
        }
        else if(L[i-1][j]>L[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout<<lcs;
    return 0;
}
