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
    int M[n];
    for(int i=0;i<n;i++)
    {
        M[i]=a[i];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j]&&M[i]<M[j]+a[i])
            {
                M[i]=M[j]+a[i];
            }
        }
    }
    int m=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(m<M[i])
        {
            m=M[i];
        }
    }
    cout<<m;
    return 0;
}
