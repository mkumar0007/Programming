#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int pow=1;
    int res=0;
    while(n)
    {
        pow=pow*5;
        if(n&1)
            res+=pow;
        n>>=1;
    }
    cout<<res;
    return 0;
}
