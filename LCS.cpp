#include<bits/stdc++.h>
using namespace std;
int main()
{
    string X,Y;
    cin>>X;
    cin>>Y;
    int m=X.length();
    int n=Y.length();
    int L[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0)
                L[i][j]=0;
            else if(X[i-1]==Y[j-1])
                L[i][j]=L[i-1][j-1]+1;
            else
                L[i][j]=max(L[i-1][j],L[i][j-1]);
        }
    }
    cout<<L[m][n];
    int index=L[m][n];
    int i=m,j=n;
    char lcs[index];
    while(i>0&&j>0)
    {
        if(X[i-1]==Y[j-1])
        {
            lcs[index-1]=X[i-1];
            i--;
            j--;
            index--;
        }
        else if(L[i-1][j]<L[i][j-1])
        {
            j--;
        }
        else
        {
            i--;
        }
    }
    cout<<endl;
    puts(lcs);
    return 0;
}
