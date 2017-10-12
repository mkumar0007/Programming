#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR=26;
int fact(int n)
{
    int f=1;
    for(int i=1;i<=n;i++)
    {
        f*=i;
    }
    return f;
}
int main()
{
    ios_base::sync_with_stdio(false);
    string str;
    getline(cin,str);
    int freq[MAX_CHAR]={0};
    int n=str.length();
    for(int i=0;i<n;i++)
    {
        freq[str[i]-'a']++;
    }
    int f=1;
    for(int i=0;i<MAX_CHAR;i++)
    {
        f*=fact(freq[i]);
    }
    cout<<fact(n)/f;
    cin.tie(NULL);
    return 0;
}
