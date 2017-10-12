#include<bits/stdc++.h>
#define MAX_CHARS 256
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    string str1,str2;
    getline(cin,str1);
    getline(cin,str2);
    int m=str1.length();
    int n=str2.length();
    bool marked[MAX_CHARS];
    memset(marked,false,sizeof(marked));
    int hmap[MAX_CHARS];
    memset(hmap,-1,sizeof(hmap));
    if(m!=n)
        return -1;
    for(int i=0;i<n;i++)
    {
        if(hmap[str1[i]]==-1)
        {
            if(marked[str2[i]]==true)
                return -1;
            hmap[str1[i]]=str2[i];
            marked[str2[i]]=true;
        }
        else if(hmap[str1[i]]!=str2[i])
        {
            return -1;
        }
    }
    return 1;
}

