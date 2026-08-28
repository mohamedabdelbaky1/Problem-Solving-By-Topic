// Author : Mohamed Abdelbaky Tony 
// Topic : Binary Search 
// Source : Codeforces 
// Rate : 1500
// Problem Link : https://codeforces.com/problemset/problem/812/C

#include<bits/stdc++.h>
using namespace std;
bool can(long long num,long long n,long long arr[],long long s)
{
    long long sum=0;
    for(int i=0;i<num;i++)
    {
        sum+=arr[i];
    }
    if(sum>s)
        return false;
    return true;
}
int main()
{
    long long n,s;
    cin>>n>>s;
    long long arr[n],arr2[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    long long l=0,r=n,wanted=0;
    while(l<r)
    {
        long long mid = (l+r+1)/2;
        for(int i=0;i<n;i++)
        {
            arr2[i] = arr[i]+mid*(i+1);
        }
        sort(arr2,arr2+n);
        if(can(mid,n,arr2,s))
        {
            l = mid;
            wanted=0;
            for(int i=0;i<mid;i++)
            {
                wanted+=arr2[i];
            }
        }
        else
        {
            r = mid-1;
           // cout<< r<< "\n";
        }
    }

    cout<< l<< " "<<wanted;
}
