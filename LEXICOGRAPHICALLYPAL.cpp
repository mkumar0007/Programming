#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR=26;
int main()
{
    ios_base::sync_with_stdio(false);
    string str;
    getline(cin,str);
    int n=str.length();
    int freq[MAX_CHAR]={0};
    for(int i=0;i<n;i++)
    {
        freq[str[i]-'a']++;
    }
    /*int odd=0;
    for(int i=0;i<MAX_CHAR;i++)
    {
        if(freq[i]%2!=0)
        {
            odd++;
        }
        if(odd>1)
            break;
    }
    if(n%2==0 && odd>0)
    {
        cout<<"NOT POSSIBLE";
        return 0;
    }
    else
    {
        if(n%2==1 && odd!=1)
            cout<<"NOT POSSIBLE";
            return 0;
    } */
    string odd_str="",front_str="",rear_str="";
    for(int i=0;i<MAX_CHAR;i++)
    {
        if(freq[i]%2!=0)
        {
            freq[i]--;
            odd_str=odd_str+(char)(i+'a');
        }
    }
    for(int i=0;i<MAX_CHAR;i++)
    {
        string temp="";
        if(freq[i]!=0)
        {
            char ch=(char)(i+'a');
            for(int j=1;j<=freq[i]/2;j++)
            {
                temp=temp+ch;
            }
            front_str=front_str+temp;
            rear_str=temp+rear_str;
        }
    }
    string res=front_str+odd_str+rear_str;
    cout<<res;
    cin.tie(NULL);
    return 0;
}
