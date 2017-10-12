#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    string s;
    getline(cin,s);
    int n=s.length();
    int i=0;
    string expand="";
    string temp;
    int freq;
    while(i<n)
    {
        temp="";
        freq=0;
        while(s[i]>='a' && s[i]<='z')
        {
            temp.push_back(s[i]);
            i++;
        }
        while(s[i]>='0' && s[i]<='9')
        {
            freq=freq*10+(s[i]-'0');
            i++;
        }
        for(int j=0;j<freq;j++)
        {
            expand.append(temp);
        }
        if(freq==0)
        {
            expand.append(temp);
        }
    }
    cout<<expand;
    cin.tie(NULL);
    return 0;
}
