// Author : Mohamed Abdelbaky Tony 
// Topic : Binary Search 
// Source : Codeforces 
// Rate : 1200
// Problem Link : https://codeforces.com/problemset/problem/1221/C

#include<bits/stdc++.h>
using namespace std;
bool could(long long NumOfTeams , long long c , long long m , long long x)
{
    long long Teams = (c+m+x) / 3 ;
    if(Teams<NumOfTeams)
        return false;
    else
    {
        if(c<NumOfTeams)
            return false;
        else if(m<NumOfTeams)
            return false;
    }
    return true;
}
int main()
{

    int q;
    cin>>q;
    while(q--)
    {
        long long c,m,x;
        cin>>c>>m>>x;
        long long Teams = (c+m+x)/3;
        int l=0 , r = Teams+1;
        while(l<r)
        {
            int mid = (l+r+1)/2;
            if(could(mid,c,m,x))
                l = mid;
            else
                r = mid-1;
        }
        cout<< r<< "\n";
    }
}
