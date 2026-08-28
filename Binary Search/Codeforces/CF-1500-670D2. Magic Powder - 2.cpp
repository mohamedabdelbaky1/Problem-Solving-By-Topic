// Author : Mohamed Abdelbaky Tony 
// Topic : Binary Search 
// Source : Codeforces 
// Rate : 1500
// Problem Link : https://codeforces.com/problemset/problem/670/D2

#include<bits/stdc++.h>
using namespace std;
bool can(long long x,long long k,long long arr1[1000000],long long arr2[1000000],long long n)
{
    for(int i=0;i<n;i++)
    {
        if(arr2[i]/arr1[i]>=x)
            continue;
        else
        {
            if(k==0)
                return false;
            else
            {
                k= k- (arr1[i]*x-arr2[i]);
                if(k<0)
                    return false;
            }
        }
    }
    return true;
}
int main()
{
    long long n,k;
    cin>>n>>k;
    long long arr1[n],arr2[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>arr2[i];
    }
    long long l=0,r=10000000000;
    while(l<r)
    {
        long long mid  =(l+r+1)/2;
        if(can(mid,k,arr1,arr2,n))
        {
            l = mid;
        }
        else
            r = mid-1;
    }
    cout<< l;
}


