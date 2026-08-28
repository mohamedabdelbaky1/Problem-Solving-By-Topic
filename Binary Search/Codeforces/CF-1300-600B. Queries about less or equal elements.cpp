// Author : Mohamed Abdelbaky Tony 
// Topic : Binary Search 
// Source : Codeforces 
// Rate : 1300
// Problem Link : https://codeforces.com/problemset/problem/600/B

#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n,m;
   cin>>n>>m;
   int arr[200005],arr2[200005];
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
   }
   for(int i=0;i<m;i++)
   {
       cin>>arr2[i];
   }
   sort(arr,arr+n);
   for(int i=0;i<m;i++)
   {
       int l=-1,r = n;
       while(l<r)
       {
           int mid = (l+r+1)/2;
           if(arr[mid]<=arr2[i])
            l = mid;
           else
            r = mid-1;
       }
       if(l!=n)
       cout<< l+1<< " ";
       else
        cout<< l<< " ";
   }
}
