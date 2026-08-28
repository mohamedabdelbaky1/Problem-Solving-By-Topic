// Author : Mohamed Abdelbaky Tony 
// Topic : Binary Search 
// Source : Codeforces 
// Rate : 1100
// Problem Link : https://codeforces.com/problemset/problem/706/B/

#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin>>n;
   int arr[100005];
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
   }
   sort(arr,arr+n);
   int q;
   cin>>q;
   while(q--)
   {
       int c;
       cin>>c;
       int l=-1,r=n;
       while(l<r)
       {
           int mid= (l+r+1)/2;
           if(arr[mid]<=c)
            l = mid;
           else
            r = mid-1;
       }
       if(l!=n)
       cout<< l+1<< "\n";
       else
        cout<< l<< "\n";
   }

}
