#include<bits/stdc++.h>
using namespace std;
int overlap(string str1,string str2,string &str)
{
       int max=INT_MIN;
    int len1=str1.length();
    int len2=str2.length();

    for(int i=1;i<=min(len1,len2);i++)
    {
        if(str1.compare(len1-i,i,str2,0,i)==0)
        {
            if(max<i)
            {
                max=i;
                str=str1+str2.substr(i);
            }
        }
    }

    for(int i=1;i<=min(len1,len2);i++)
    {
          if (str1.compare(0, i, str2, len2-i, i) == 0)
        {
            if (max < i)
            {
                //update max and str
                max = i;
                str = str2 + str1.substr(i);
            }
        }
    }
    return max;
}
int main()
{
    int n;
    cin>>n;
    vector<string> A(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    int max=INT_MIN;
    int l,r,len=n;
    while(len!=1)
    {
        int max=INT_MIN;
        string resstr;
        for(int i=0;i<len;i++)
        {
            for(int j=i+1;j<len;j++)
            {
                string str;

                int res=overlap(A[i],A[j],str);
                if(res>max)
                {
                    max=res;
                    resstr=str;
                    l=i;
                    r=j;
                }
            }
        }
        len--;
        if(max==INT_MIN)
        {
            A[0]+=A[len];
        }
        else
        {
            A[l]=resstr;
            A[r]=A[len];
        }
    }
    cout<<A[0];
    return 0;
}
