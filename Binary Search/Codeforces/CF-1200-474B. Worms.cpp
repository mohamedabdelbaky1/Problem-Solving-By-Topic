// Author : Mohamed Abdelbaky Tony 
// Topic : Binary Search 
// Source : Codeforces 
// Rate : 1200
// Problem Link : https://codeforces.com/problemset/problem/474/B

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[100005];
    int pre[100006]={0};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++)
    {
        pre[i] = pre[i-1]+arr[i-1];
    }
    int m;
    cin>>m;
    while(m--)
    {
        int q,ans;
        cin>>q;
        long long l=0,r = 2*n;
        while(l<=r)
        {
            long long mid = (l+r)/2;
            if(pre[mid]>=q)
            {
                ans = mid;
                r = mid-1;
            }
            else
                l = mid+1;
        }
        cout<< ans<< "\n";
    }
}
