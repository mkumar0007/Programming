#include<bits/stdc++.h>
using namespace std;

int noble(int a[],int n)
{
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        if(a[i]==a[i+1])
            continue;
        if(a[i]==n-i-1)
            return a[i];
    }
    if(a[n-1]==0)
        return a[n-1];
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<noble(a,n);
    return 0;
}
