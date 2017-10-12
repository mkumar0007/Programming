#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int sum=0;
    for(int i=0;i<32;i++)
    {
        int c=0;
        for(int j=0;j<n;j++)
        {
            if(a[j]&(1<<i))
                c++;
        }
        sum+=(1<<i)*
        (c*(c-1)/2);
    }
    cout<<sum;
    return 0;
}
