#include<bits/stdc++.h>
using namespace std;
#define MAX_CHAR 26
int main()
{
    ios_base::sync_with_stdio(false);
    char str[50];
    cin>>str;
    int k;
    cin>>k;
    int res=0;
    int occupied=0;
    int n=strlen(str);
    int seen[MAX_CHAR]={0};
    for(int i=0;i<n;i++)
    {
        int ind=str[i]-'A';
        if(seen[ind]==0)
        {
            seen[ind]=1;
            if(occupied<k)
            {
                seen[ind]=2;
                occupied++;
            }
            else
            {
                res++;
            }
        }
        else
        {
            if(seen[ind]==2)
                occupied--;
            seen[ind]=0;
        }
    }
    cout<<res;
    cin.tie(NULL);
    return 0;
}
