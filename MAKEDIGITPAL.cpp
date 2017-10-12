#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    string str;
    getline(cin,str);
    int k;
    cin>>k;
    int l=0;
    int r=str.length()-1;
    string pal=str;
    while(l<r)
    {
        if(str[l]!=str[r])
        {
            pal[l]=pal[r]=max(str[l],str[r]);
            k--;
        }
        l++;
        r--;
    }
    if(k<0)
    {
        cout<<"Not Possible";
    }
    l=0;
    r=str.length()-1;
    while(l<=r)
    {
        if(l==r)
        {
            pal[l]='9';
        }
        if(pal[l]<'9')
        {
            if(k>=2 && str[l]==pal[l] && str[r]==pal[r])
            {
                k-=2;
                pal[l]=pal[r]='9';
            }
            else if(k>=1 && str[l]!=pal[l] || str[r]!=pal[r])
            {
                k-=1;
                pal[l]=pal[r]='9';
            }
        }
        l++;
        r--;
    }
    cout<<pal;
    cin.tie(NULL);
    return 0;
}
