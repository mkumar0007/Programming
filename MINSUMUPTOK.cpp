#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int k;
    cin>>k;
    int res=0;
    int i, j, min_idx;
	for (i = 0; i < k-1; i++)
	{
		min_idx = i;
		for (j = i+1; j < n; j++)
            if (a[j] < a[min_idx])
                cout<<a[j]<<endl;
                res+=a[j];
    //    swap(&arr[min_idx], &arr[i]);
	}
	cout<<res;
	cin.tie(NULL);
	return 0;
}
