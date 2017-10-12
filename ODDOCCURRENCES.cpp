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
    int x=0,y=0;
    int xo=a[0];
    for(int i=1;i<n;i++)
    {
        xo=xo^a[i];
    }
    int bit=(xo)&~(xo-1);
    for(int i=0;i<n;i++)
    {
        if(a[i]&bit)
            x=x^a[i];
        else
            y=y^a[i];
    }
    cout<<x<<" "<<y;
    return 0;
}
