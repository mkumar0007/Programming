#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int x=a^b;
    int c=0;
    while(x)
    {
        c+=(x&1);
        x>>=1;
    }
    cout<<c;
    return 0;
}
