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
    vector<int> m(n);
    vector<int> n1(n);
    m[0]=v[0];
    n1[0]=v[0];
    int res=v[0];
    for(int i=1;i<n;i++)
    {
        if(v[i]>0)
        {
            m[i]=max(v[i],m[i-1]*v[i]);
            n1[i]=min(v[i],n1[i-1]*v[i]);
        }
        else
        {
            m[i]=max(v[i],n1[i-1]*v[i]);
            n1[i]=min(v[i],m[i-1]*v[i]);
        }
        res=max(res,m[i]);
    }
    cout<<res;
    return 0;
}
