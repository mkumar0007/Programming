#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,char> p1,pair<int,char> p2)
{
    if(p1.first==p2.first)
    {
        return p1.second<p2.second;
    }
    else
    {
        return p1.first>p2.first;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    string str;
    getline(cin,str);
    int d;
    cin>>d;
    int n=str.length();
    int freq[26]={0};
    int m=0;
    for(int i=0;i<n;i++)
    {
        if(freq[str[i]-'a']==0)
        {
            freq[str[i]-'a']=1;
            m++;
        }
        else
        {
            freq[str[i]-'a']++;
        }
    }
    char res[n];
    vector< pair<int,char> > q;
    for(int i=0;i<26;i++)
    {
        char ch=(i + 'a');
        pair<char ,int > temp;
        temp.first=freq[i];
        temp.second=ch;
        q.push_back(temp);
    }
    sort(q.begin(),q.end(),compare);
    for(int i=0;i<m;i++)
    {
        pair<int,char> x=q[i];
        int p=i;
        cout<<x.first<<" "<<x.second<<endl;
        for(int k=0;k<x.first;k++)
        {
            if(p+d*k>=n)
            {
                cout<<"cannot be arranged";
                exit(0);
            }
            res[(p+d*k)]=x.second;
        }
    }
    cout<<res;
    cin.tie(NULL);
    return 0;
}
