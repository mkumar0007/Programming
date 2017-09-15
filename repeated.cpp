#define MAX_CHAR 256
#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string s,int l,int h)
{
    while(h>l)
    {
        if(s[l++]!=s[h--])
            return false;
    }
    return true;
}
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    int freq[MAX_CHAR]={0};
    bool flag=false;
    for(int i=0;i<n;i++)
    {
        freq[s[i]]++;
        if(freq[s[i]]>3)
            flag=true;
            break;
    }
    int k=0;
    string r;
    for(int i=0;i<n;i++)
    {
        if(freq[s[i]]>1)
        {
            r[k++]=s[i];
        }
    }
    cout<<r;
    r[k]='\0';
    if(isPalindrome(r,0,k-1))
    {
        if(k&1&&r[k/2]==r[k/2 - 1])
            flag=true;
        flag=false;
    }
    if(flag)
        cout<<r;
    return 0;
}
