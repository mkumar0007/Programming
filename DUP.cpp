#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    string str;
    getline(cin,str);
    int i=0;
    while(i<str.length()-1)
    {
        int j=i;
        while(j<str.length()-1 && str[i]==str[j+1])
        {
            j++;
        }
        if(j>i)
        {
            str = str.substr(0,i) + str.substr(j+1,str.length());
            i--;
        }
        else
        {
            i++;
        }
    }
    i<1?cout<<"-1":cout<<str;
    cin.tie(NULL);
    return 0;
}
