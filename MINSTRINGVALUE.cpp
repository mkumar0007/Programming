#include<bits/stdc++.h>
using namespace  std;
const int MAX_CHAR=26;
int main()
{
    ios_base::sync_with_stdio(false);
    string str;
    getline(cin,str);
    int k;
    cin>>k;
    int n=str.length();
    int freq[MAX_CHAR]={0};
    for(int i=0;i<n;i++)
    {
        freq[str[i]-'a']++;
    }
    priority_queue<int> q;
    for(int i=0;i<MAX_CHAR;i++)
    {
        q.push(freq[i]);
    }
    int temp;
    while(k--)
    {
        temp=q.top();
        q.pop();
        temp=temp-1;
        q.push(temp);
    }
    int res=0;
    while(!q.empty())
    {
        temp=q.top();
        q.pop();
        res+=(temp*temp);
    }
    cout<<res;
    cin.tie(NULL);
    return 0;
}
