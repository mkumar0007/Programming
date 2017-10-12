#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned int n;
    cin>>n;
    unsigned int reverse_no=0;
    unsigned int bits=(sizeof(n)*8);
    for(int i=0;i<bits;i++)
    {
        if(n&(1<<i))
            reverse_no|=(1<<(bits-1)-i);
    }
    cout<<reverse_no;
    return 0;
}
