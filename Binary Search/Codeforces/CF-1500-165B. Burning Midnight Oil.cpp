// Author : Mohamed Abdelbaky Tony 
// Topic : Binary Search 
// Source : Codeforces 
// Rate : 1500
// Problem Link : https://codeforces.com/problemset/problem/165/B

#include<bits/stdc++.h>
using namespace std;
bool can(int n,int k,int v)
{
    int power = 0;
    int lines = n;
    int var = v/pow(k,power);
    while(var>0)
    {
        lines-=var;
        power++;
        var = v/pow(k,power);
    }
    if(lines>0)
        return false;
    return true;
}
int main()
{
    int n,k,ans=0;
    cin>>n>>k;


    int l=1,r = 1000000000;
    while(l<r)
    {
        int mid = (l+r)/2;
        if(can(n,k,mid))
        {
            r=mid;
        }
        else
        {
            l = mid+1;
        }
    }
    cout<< r;
}
