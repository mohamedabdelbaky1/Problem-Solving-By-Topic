// Author : Mohamed Abdelbaky Tony 
// Topic : Binary Search 
// Source : Codeforces 
// Rate : 1400
// Problem Link : https://codeforces.com/problemset/problem/279/B

#include<bits/stdc++.h>
using namespace std;
bool can(int x,int arr[100005],int n,int k)
{
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        v.push_back(arr[i]);
    }
    int pre[n+1]={0};
    for(int i=1;i<=n;i++)
    {
        pre[i]=pre[i-1]+v[i-1];
    }
    for(int i=x;i<=n;i++)
    {
        if(pre[i]-pre[i-x]<=k)
            return true;
    }

    return false;
}
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[100005];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int l=0,r = n;
    while(l<r)
    {
        int mid = (l+r+1)/2;
        if(can(mid,arr,n,k))
            l = mid;
        else
            r = mid-1;
    }
    cout<< l;
}
