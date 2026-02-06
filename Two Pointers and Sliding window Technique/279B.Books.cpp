// Author : Mohamed Abdelbaky 
// Problem Ling : https://codeforces.com/problemset/problem/279/B

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t ;
    cin>>n>>t;
    int arr[100001]={0};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int p1 = 0 , p2 = 0;
    long long sum = 0;
    int ans;
    while(p1<n)
    {
        while(p2<n&&sum+arr[p2]<=t)
        {
            sum+=arr[p2];
            p2++;
        }
        ans = max(ans , p2-p1);
        sum-=arr[p1];
        p1++;
    }
    cout<< ans;
}
