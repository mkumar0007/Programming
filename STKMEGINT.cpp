#include<bits/stdc++.h>
using namespace std;
struct Interval
{
    int start;
    int end;
};
bool compare(Interval i1,Interval i2)
{
    return i1.start<i2.start;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<Interval> V(n);
    for(int i=0;i<n;i++)
    {
        cin>>V[i].start>>V[i].end;
    }
    sort(V.begin(),V.end(),compare);
    stack<Interval> S;
    S.push(V[0]);
    for(int i=1;i<n;i++)
    {
        Interval temp=S.top();
        if(temp.end<V[i].start)
        {
            S.push(V[i]);
        }
        else if(temp.end<V[i].end)
        {
            temp.end=V[i].end;
            S.pop();
            S.push(temp);
        }
    }
    while(!S.empty())
    {
        Interval temp=S.top();
        cout<<temp.start<<" "<<temp.end<<endl;
        S.pop();
    }
    cin.tie(NULL);
    return 0;
}
