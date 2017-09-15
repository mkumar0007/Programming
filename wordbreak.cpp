#include<bits/stdc++.h>
using namespace std;
int main()
{
    string A;
    cin>>A;
    int n;
    cin>>n;
    vector<string> dictv(n);
    for(int i=0;i<n;i++)
    {
        cin>>dictv[i];
    }
    set<string> dict(dictv.begin(),dictv.end());
    int s=A.length();
    vector<vector<string> > words(s+1,vector<string> (0));
    words[s].push_back("");
    for(int  i=s-1;i>=0;i--)
    {
        vector<string> values;
        for(int j=i+1;j<=s;j++)
        {
            if(dict.find(A.substr(i,j-i))!=dict.end())
            {
                for(int k=0;k<words[j].size();k++)
                {
                    values.push_back(A.substr(i,j-i) + (words[j][k].empty()?"":" ") + words[j][k]);
                }
            }
        }
        words[i]=values;
    }
    for(int i=0;i<words[0].size();i++)
    {
        cout<<words[0][i]<<endl;
    }
    return 0;
}
