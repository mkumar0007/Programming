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
    int tp,area=0,cur_area=0;
    int i=0;
    stack<int> s;
    while(i<n)
    {
        if(s.empty() || a[s.top()]<=a[i])
        {
            s.push(i++);
        }
        else
        {
            tp=s.top();
            s.pop();
            cur_area=a[tp]*(s.empty()?i:(i-s.top()-1));
            area=max(area,cur_area);
        }
    }
    while(!s.empty())
    {
            tp=s.top();
            s.pop();
            cur_area=a[tp]*(s.empty()?i:(i-s.top()-1));
            area=max(area,cur_area);
    }
    cout<<area;
    cin.tie(NULL);
    return 0;
}
