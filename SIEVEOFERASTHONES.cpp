#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    bool prime[n+1];
    memset(prime,true,sizeof(prime));
    for(int p=2;p*p<=n;p++)
    {
        if(prime[p])
        {
            for(int i=p*2;i<=n;i+=p)
            {
                prime[i]=false;
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        if(prime[i])
            cout<<i<<" ";
    }
    cin.tie(NULL);
    return 0;
}
