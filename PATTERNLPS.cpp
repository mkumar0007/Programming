#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    string str;
    getline(cin,str);
    int n=str.length();
    int *lps=new int[n];
    int i=1;
    lps[0]=0;
    int len=0;
    while(i<n)
    {
        if(str[i]==str[len])
        {
            len++;
            lps[i]=len;
            i++;
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
    int x=lps[n-1];
    x>0 && (n%(n-x)==0) ? cout<<"YES" : cout<<"NO";
    cin.tie(NULL);
    return 0;
}
