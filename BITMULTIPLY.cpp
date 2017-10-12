#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int a,b;
    cin>>a>>b;
    int ans=0;
    while(b)
    {
        if(b&1)
            ans+=a;
        a=a<<1;
        b=b>>1;
    }
    cout<<ans;
    return 0;
}
