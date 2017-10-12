#include<bits/stdc++.h>
using namespace std;
#define MAX_CHAR 26
bool isvalid(int freq[],int k)
{
    int v=0;
    for(int i=0;i<MAX_CHAR;i++)
    {
        if(freq[i]>0)
        {
            v++;
        }
    }
    return (k>=v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    string str;
    cin>>str;
    int k;
    cin>>k;
    int n=str.length();
    int freq[MAX_CHAR];
    memset(freq,0,sizeof(freq));
    int m=0;
    for(int i=0;i<n;i++)
    {
        if(freq[str[i]-'a']==0)
            m++;
        freq[str[i]-'a']++;
    }
    if(m<k)
    {
        cout<<"LESS THAN K CHARS";
        return 0;
    }
    int curstart=0,curend=0;
    int maxlen=1;
    int maxstart=0;
    memset(freq,0,sizeof(freq));
    freq[str[0]-'a']++;
    for(int i=1;i<n;i++)
    {
        freq[str[i]-'a']++;
        curend++;
        while(!isvalid(freq,k))
        {
            freq[str[curstart]-'a']--;
            curstart++;
        }
        if(curend-curstart+1>maxlen)
        {
            maxlen=curend-curstart+1;
            maxstart=curstart;
        }
    }
    cout<<maxlen<<endl;
    cout<<str.substr(maxstart,maxlen);
    cin.tie(NULL);
    return 0;
}
