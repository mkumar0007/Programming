#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    int a[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    stack<int> s;
    int k=0,l=0;
    while(k<m && l<n)
    {
        for(int i=l;i<n;i++)
        {
            s.push(a[k][i]);
        }
        k++;
        for(int i=k;i<m;i++)
        {
            s.push(a[i][n-1]);
        }
        n--;
        if(k<m)
        {
            for(int i=n-1;i>=l;i--)
            {
                s.push(a[m-1][i]);
            }
            m--;
        }
        if(l<n)
        {
            for(int i=m-1;i>=k;i--)
            {
                s.push(a[i][l]);
            }
            l++;
        }
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
