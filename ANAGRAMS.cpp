#include<bits/stdc++.h>
#include<map>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    map<string,vector<string> > has;
    for(int i=0;i<n;i++)
    {
        string temp(v[i]);
        sort(temp.begin(),temp.end());
        if(has.find(temp)==has.end())
        {
            vector<string> t;
            t.push_back(v[i]);
            has.insert(make_pair(temp,t));
        }
        else
        {
            vector<string> t(has[temp]);
            t.push_back(v[i]);
            has[temp]=t;
        }
    }
    map<string,vector<string> > ::iterator it;
    for(it=has.begin();it!=has.end();it++)
    {
        vector<string > temp(it->second);
        int s=temp.size();
        if(s>1)
        {
            for(int i=0;i<s;i++)
            {
                cout<<temp[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
