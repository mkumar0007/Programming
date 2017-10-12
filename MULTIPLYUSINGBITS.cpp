#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,res=0;
    cin>>a>>b;
    while(b>0)
    {
        if(b&1)
        {
            res+=a;
        }
        a<<=1;
        b>>=1;
    }
    cout<<res;
    return 0;
}
