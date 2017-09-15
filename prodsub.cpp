#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],maxarr[n],minarr[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    maxarr[0]=a[0];
    minarr[0]=a[0];
    int result=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>0)
        {
            maxarr[i]=max(a[i],maxarr[i-1]*a[i]);
            minarr[i]=min(a[i],minarr[i-1]*a[i]);
        }
        else
        {
            maxarr[i]=max(a[i],minarr[i-1]*a[i]);
            minarr[i]=min(a[i],maxarr[i-1]*a[i]);
        }
        result=max(maxarr[i],result);
    }
    cout<<result;
    return 0;
}
