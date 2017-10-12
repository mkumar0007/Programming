#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int fib[n+2];
    fib[0]=0;
    fib[1]=1;
    for(int i=2;i<=n+2;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
    }
    int res=(1<<n)-fib[n+2];
    cout<<res;
    cin.tie(NULL);
    return 0;
}
