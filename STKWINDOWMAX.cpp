#include<bits/stdc++.h>
using namespace std;
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
    int left[n+1],right[n+1];
    for(int i=0;i<n;i++)
    {
        left[i]=-1;
        right[i]=n;
    }
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        while(!s.empty() && a[s.top()]>=a[i])
        {
            s.pop();
        }
        if(!s.empty())
        {
            left[i]=s.top();
        }
        s.push(i);
    }
    for(int i=n-1;i>=0;i--)
    {
            while(!s.empty() && a[s.top()]>=a[i])
        {
            s.pop();
        }
        if(!s.empty())
        {
            right[i]=s.top();
        }
        s.push(i);
    }
    int ans[n+1];
    memset(ans,0,sizeof(ans));
    for(int i=0;i<n;i++)
    {
        int len=right[i]-left[i]-1;
        ans[len]=max(ans[len],a[i]);
    }
    for(int i=n-1;i>=1;i--)
    {
        ans[i]=max(ans[i],ans[i+1]);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cin.tie(NULL);
    return 0;
}
