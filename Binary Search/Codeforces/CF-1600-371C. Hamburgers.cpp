// Author : Mohamed Abdelbaky Tony 
// Topic : Binary Search 
// Source : Codeforces 
// Rate : 1600
// Problem Link : https://codeforces.com/problemset/problem/371/C

#include<bits/stdc++.h>
using namespace std;
long long maxi(long long a,long long b)
{
    if(a>=b)
        return a;
    else
        return b;
}
bool can(long long maxNUMBurger,long long Mymoney,string x,long long nb,long long ns,long long nc,long long pb,long long ps,long long pc)
{
    long long Cb=0,Cs=0,Cc=0;
    long long totalMoney=0;
    for(int i=0;i<x.size();i++)
    {
        if(x[i]=='B')
            Cb++;
        else if(x[i]=='S')
            Cs++;
        else
            Cc++;
    }
    totalMoney = maxi(0,Cb*maxNUMBurger-nb)*pb+maxi(0,Cs*maxNUMBurger-ns)*ps+maxi(0,Cc*maxNUMBurger-nc)*pc;
    return totalMoney<=Mymoney;
}
int main()
{
    string x;
    cin>>x;
    int nb,ns,nc,pb,ps,pc;
    cin>>nb>>ns>>nc>>pb>>ps>>pc;
    long long money ;
    cin>>money;
    long long l=0,r=10000000000000;
    while(l<r)
    {
        long long mid = (l+r+1)/2;
        if(can(mid,money,x,nb,ns,nc,pb,ps,pc))
            l = mid;
        else
            r = mid-1;
    }
    cout<< l;
}
