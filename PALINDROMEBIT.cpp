#include<bits/stdc++.h>
using namespace std;

bool setbit(unsigned int x,unsigned int k)
{
    return (x&(1<<(k-1)))?true:false;
}

bool pal(int x)
{
    int reversed = 0, aux = x;
    while (aux > 0)
    {
        reversed = (reversed  << 1) | (aux & 1);
        aux = aux >> 1;
    }
    return (reversed  == x) ? 1 : 0;
}
int main()
{
    int n;
    cin>>n;
    if(pal(n))
        cout<<"PALINDROME";
    else
        cout<<"NOT";
    return 0;
}
