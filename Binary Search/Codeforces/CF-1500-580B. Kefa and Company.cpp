// Author : Mohamed Abdelbaky Tony 
// Topic : Binary Search 
// Source : Codeforces 
// Rate : 1500
// Problem Link : https://codeforces.com/problemset/problem/580/B

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,d;
    cin>>n>>d;
    pair<int,int>arr[100005];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr,arr+n);
    long long sum=0,ans=0;
    int counter=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i].second;
        while(counter<i&&arr[i].first-arr[counter].first>=d)
        {
            sum-=arr[counter].second;
            counter++;
        }
        ans = max(ans,sum);
    }
    cout<< ans;
}
