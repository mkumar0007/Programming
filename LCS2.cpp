#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    string a,b;
    getline(cin,a);
    getline(cin,b);
    int c1[26]={0};
    for(int i=0;i<a.length();i++)
    {
        c1[a[i]-'a']++;
    }
    int c2[26]={0};
    for(int i=0;i<b.length();i++)
    {
        c2[b[i]-'a']++;
    }
    string res;
    for(int i=0;i<26;i++)
    {
        for(int j=1;j<=min(c1[i],c2[i]);j++)
        {
            res=res +(char)(i+'a');
        }
    }
    cout<<res;
    cin.tie(NULL);
    return 0;
}
