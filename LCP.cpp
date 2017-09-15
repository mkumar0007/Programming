#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    int i,j,c;
    int L[n][n];
    for(int i=0;i<n;i++)
    {
        L[i][i]=1;
    }
    for(int c=2;c<=n;c++)
    {
        for(int i=0;i<n-c+1;i++)
        {
            j=i+c-1;
            if(s[i]==s[j]&&c==2)
            {
                L[i][j]=2;
            }
            else if(s[i]==s[j])
            {
                L[i][j]=L[i+1][j-1]+2;
            }
            else
            {
                L[i][j]=max(L[i][j-1],L[i+1][j]);
            }
        }
    }
    cout<<L[0][n-1];
    return 0;
}
