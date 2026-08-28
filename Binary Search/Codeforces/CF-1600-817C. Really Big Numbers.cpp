// Author : Mohamed Abdelbaky Tony 
// Topic : Binary Search 
// Source : Codeforces 
// Rate : 1600
// Problem Link : https://codeforces.com/problemset/problem/817/C

#include <bits/stdc++.h>
using namespace std;
long long fun(long long x)
{
       long long sumOfDigits=0;
  while(x>0)
  {
      sumOfDigits+= x%10;
      x = x/10;
  }
   return sumOfDigits;
}
int main()
{
   long long n,s;
   string x;
   cin>>x>>s;
   n = stoll(x);
   long long l=0,r=n+1;

   while(l<r)
   {
       long long mid = (l+r)/2;
       if(mid-fun(mid)>=s)
        r = mid;
       else
        l = mid+1;
   }
   if(r!=n+1)
   cout<< n-r+1;
   else
    cout<< 0;
}
