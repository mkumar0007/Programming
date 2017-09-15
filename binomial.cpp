#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int c[k+1];
    memset(c,0,sizeof(c));
    c[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=min(i,k);j>0;j--)
        {
            c[j]=c[j]+c[j-1];
        }
    }
    cout<<c[k];
    return 0;
}
