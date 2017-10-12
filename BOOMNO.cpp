#include<bits/stdc++.h>
using namespace  std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;
    ll c=0;
    queue<string>q;
    q.push("");
    while(c<=n)
    {
        string s1=q.front();
        q.pop();
        string s2=s1;
        q.push(s1.append("2"));
        c++;
        if(c==n)
        {
            cout<<s1;
            break;
        }
        q.push(s2.append("3"));
        c++;
        if(c==n)
        {
            cout<<s2;
            break;
        }
    }
    return 0;
}
