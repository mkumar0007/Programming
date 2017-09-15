#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int *lis=new int[n];
    for(int i=0;i<n;i++)
    {
        lis[i]=1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(v[i]>v[j]&&lis[i]<lis[j]+1)
            {
                lis[i]=lis[j]+1;
            }
        }
    }
    int *lds=new int[n];
    for(int i=0;i<n;i++)
    {
        lds[i]=1;
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=n-1;j>i;j--)
        {
            if(v[i]>v[j]&&lds[i]<lds[j]+1)
            {
                lds[i]=lds[j]+1;
            }
        }
    }
    int m=lds[0]+lis[0]-1;
    for(int i=1;i<n;i++)
    {
        if(m<lds[i]+lis[i]-1)
        {
            m=lds[i]+lis[i]-1;
        }
    }
    cout<<m;
    return 0;
}
