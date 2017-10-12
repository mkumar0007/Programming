#include<bits/stdc++.h>
using namespace std;
#define MAX_CHAR 256
int main()
{
    ios_base::sync_with_stdio(false);
    string str,pat;
    int hash_str[MAX_CHAR]={0};
    int hash_pat[MAX_CHAR]={0};
    getline(cin,str);
    getline(cin,pat);
    int len1=str.length();
    int len2=pat.length();
    for(int i=0;i<len2;i++)
    {
        hash_pat[pat[i]]++;
    }
    int start=0,index=-1;
    int minlen=INT_MAX;
    int c=0;
    for(int i=0;i<len1;i++)
    {
        hash_str[str[i]]++;
        if(hash_pat[str[i]] != 0 && hash_pat[str[i]] >= hash_str[str[i]])
        {
             c++;
        }
        if(c==len2)
        {
            while(hash_str[str[start]] > hash_pat[str[start]] || hash_pat[str[start]]==0)
            {
                if(hash_str[str[start]] > hash_pat[str[start]])
                {
                    hash_str[str[start]]--;start++;
                }

            }
            int len=i-start+1;
            if(len < minlen)
            {
                minlen=len;
                index=start;
            }
        }
    }
    cout<<str.substr(index,minlen);
    return 0;
}
