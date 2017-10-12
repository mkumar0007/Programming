#include<bits/stdc++.h>
using namespace std;

int multiple(int n)
{
    int odd=0,even=0;
    if(n==0)
        return 1;
    if(n==1)
        return 0;
    while(n)
    {
        if(n&1)
            odd++;
        n>>=1;
        if(n&1)
            even++;
        n>>=1;
    }
    return multiple(abs(odd-even));
}
int main()
{
    int n;
    cin>>n;
    if(multiple(n))
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
