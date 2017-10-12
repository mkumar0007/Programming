#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR=256;
int main()
{
    ios_base::sync_with_stdio(false);
    string str;
    getline(cin,str);
    int n=str.length();
    bool visited[MAX_CHAR];
    memset(visited,false,sizeof(visited));
    int dist_count=0;
    for(int i=0;i<n;i++)
    {
        if(visited[str[i]]==false)
        {
            visited[str[i]]=true;
            dist_count++;
        }
    }
    int has[MAX_CHAR]={0};
    int count =0;
    int start=0,index=-1,minlen=INT_MAX;
    for(int i=0;i<n;i++)
    {
        has[str[i]]++;
        if(has[str[i]]==1)
            count++;
        if(count==dist_count)
        {
            while(has[str[start]]>1)
            {
                if(has[str[start]]>1)
                {
                    has[str[start]]--;
                }
                start++;
            }
            int len=i-start+1;
            if(minlen>len)
            {
                minlen=len;
                index=start;
            }
        }
    }
    cout<<str.substr(start,minlen);
    cin.tie(NULL);
    return 0;
}
