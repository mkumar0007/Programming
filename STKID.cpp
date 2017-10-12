#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    string str;
    getline(cin,str);
    int n=str.length();
    int avail=1;
    vector<int> v;
    int pos=0;
    if(str[0]=='I')
    {
        v.push_back(1);
        v.push_back(2);
        avail=3;
        pos=1;
    }
    else
    {
        v.push_back(2);
        v.push_back(1);
        avail=3;
        pos=0;
    }
    for(int i=1;i<n;i++)
    {
        if(str[i]=='I')
        {
            v.push_back(avail);
            avail++;
            pos=i+1;
        }
        else
        {
            v.push_back(v[i]);
            for(int j=pos;j<=i;j++)
            {
                v[j]++;
            }
            avail++;
        }
    }
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i];
    }
    cin.tie(NULL);
    return 0;
}
