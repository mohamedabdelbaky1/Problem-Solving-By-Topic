// Author : Mohamed Abdelbaky Tony 
// Topic : Binary Search 
// Source : Codeforces 
// Rate : 1400
// Problem Link : https://codeforces.com/problemset/problem/1201/C

#include<bits/stdc++.h>
using namespace std;
bool can(long long x,long long n,long long arr[],long long k,long long median)
{
    long long steps = k;
    if(x>median)
    {
        steps-= (x-median);
        if(steps<0)
            return false;
        for(int i=n/2+1;i<n;i++)
        {
            if(arr[i]<x)
            {
                steps-= (x-arr[i]);
                if(steps<0)
                    return false;
            }
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
    long long n,k;
    cin>>n>>k;
    long long arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    if(n==1)
    {
        cout<< arr[0]+k;
        return 0;
    }
    sort(arr,arr+n);
    long long median = arr[n/2];
    //cout<< can(6,n,arr,k,median);
    long long l = median , r = median + k+1;
    while(l<r)
    {
        long long mid = (l+r+1)/2;
        if(can(mid,n,arr,k,median))
        {
            l = mid;
        }
        else
            r = mid-1;
    }
    cout<< l<< "\n";
}


