#include<bits/stdc++.h>
using namespace std;

void func(int a[],int n,int s[])
{
    stack<int> d;
    for(int i=0;i<n;i++)
    {
        while(!d.empty() && d.top()>=a[i])
        {
            d.pop();
        }
        if(!d.empty())
        {
            s[i]=d.top();
        }
        else
        {
            s[i]=0;
        }
        d.push(a[i]);
    }
    return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int l[n];
    func(a,n,l);
    reverse(a,a+n);
    int r[n];
    func(a,n,r);
    int res=0;
    for(int i=0;i<n;i++)
    {
        res=max(res,abs(l[i]-r[n-i-1]));
    }
    cout<<res;
    cin.tie(NULL);
    return 0;
}
