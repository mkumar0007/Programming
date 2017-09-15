#include<bits/stdc++.h>
using namespace std;
int main()
{
    clock_t start,end;
    start=clock();
    double s;
    int n;
    cin>>n;
    int *ugly=new int[n];
    ugly[0]=1;
    int i2=0,i3=0,i5=0;
    int next2=ugly[i2]*2;
    int next3=ugly[i3]*3;
    int next5=ugly[i5]*5;
    int next=1;
    for(int i=1;i<n;i++)
    {
        next=min(next2,min(next3,next5));
        ugly[i]=next;
        if(next==next2)
        {
            i2=i2+1;
            next2=ugly[i2]*2;
        }
        if(next==next3)
        {
            i3=i3+1;
            next3=ugly[i3]*3;
        }if(next==next5)
        {
            i5=i5+1;
            next5=ugly[i5]*5;
        }
    }
    cout<<next;
    end=clock();
    cout<<(double)(end-start);
    return 0;
}
