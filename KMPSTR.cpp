#include<bits/stdc++.h>
using namespace std;
int main()
{
    string txt,pat;
    getline(cin,txt);
    getline(cin,pat);
    int m=txt.length();
    int n=pat.length();
    int *lps=new int[n];
    int len=0;
    int i=1;
    lps[0]=0;
    while(i<n)
    {
        if(pat[i]==pat[len])
        {
            i++;
            len++;
            lps[i]=len;
        }
        else
        {
            if(len!=0)
            {
                len=lps[len-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
    i=0;
    len=0;
    while(i<m)
    {
        if(txt[i]==pat[len])
        {
            i++;
            len++;
        }
        if(len==n)
        {
            cout<<i-len;
            len=lps[len-1];
        }
        else if(i<m && txt[i]!=pat[len])
        {
            if(len!=0)
            {
                len=lps[len-1];
            }
            else
            {
                i++;
            }
        }
    }
    cin.tie(NULL);
    return 0;
}

