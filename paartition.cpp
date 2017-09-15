#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    bool L[n][n];
    for(int i=0;i<n;i++)
    {
        L[i][i]=true;
    }
    int k;
    for(k=2;k<=n;k++)
    {
        for(int i=0;i<n-k+1;i++)
        {
            int j=i+k-1;
            if(k==2)
            {
                L[i][j]=(s[i]==s[j]);
            }
            else
            {
                L[i][j]=(s[i]==s[j])&&(L[i+1][j-1]);
            }
        }
    }
    int C[n],j,i;
    for (i=0; i<n; i++)
    {
        if (L[0][i] == true)
            C[i] = 0;
        else
        {
            C[i] = INT_MAX;
            for(j=0;j<i;j++)
            {
                if(L[j+1][i] == true && 1+C[j]<C[i])
                    C[i]=1+C[j];
            }
        }
    }
    cout<<C[n-1];
    return 0;
}
