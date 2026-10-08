/*
Author: Mohamed Abdelbaky Tony
Platform: Codeforces
Rating: 1600
Topics: 2D Prefix sum
Link: https://codeforces.com/problemset/problem/1722/E

Idea:
- Represent each rectangle as a point in the grid:
  grid[h][w] += h * w

- Build a 2D Prefix Sum over the grid.

- Each query asks for the total area of rectangles satisfying:

  hs < h < hb
  ws < w < wb

- So we query the rectangle:

  (hs+1, ws+1) -> (hb-1, wb-1)

using:

answer =
prefix[hb-1][wb-1]
- prefix[hs][wb-1]
- prefix[hb-1][ws]
+ prefix[hs][ws];

Algorithm:

1. Read all rectangles.

2. For every rectangle:

   grid[h][w] += h * w


3. Build the 2D prefix sum:

   prefix[i][j] =
       grid[i][j]
       + prefix[i-1][j]
       + prefix[i][j-1]
       - prefix[i-1][j-1]


4. For every query:

   hs ws hb wb

   calculate:

   prefix[hb-1][wb-1]
   - prefix[hs][wb-1]
   - prefix[hb-1][ws]
   + prefix[hs][ws]


5. Print the answer.


Complexity:

Time:
O(N + 1000*1000 + Q)

= O(N + 10^6 + Q)

Space:
O(1000*1000)

= O(10^6)

*/

// Solution : 

#include<bits/stdc++.h>
using namespace std;
long long grid[1005][1005];
long long prefix[1005][1005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        for(int i=0;i<1005;i++)
        {
            for(int j=0;j<1005;j++)
            {
                grid[i][j] = 0;
                prefix[i][j] = 0;
            }
        }
        for(int i=0;i<n;i++)
        {
            int h,w;
            cin>>h>>w;
            grid[h][w]+= 1LL * h * w;
        }
        for(int i=1;i<1005;i++)
        {
            for(int j=1;j<1005;j++)
            {
                 prefix[i][j] =
                    grid[i][j]
                    + prefix[i-1][j]
                    + prefix[i][j-1]
                    - prefix[i-1][j-1];
            }
        }
        while(q--)
        {
            int hs, ws, hb, wb;
            cin >> hs >> ws >> hb >> wb;
            long long answer =
                prefix[hb-1][wb-1]
                - prefix[hs][wb-1]
                - prefix[hb-1][ws]
                + prefix[hs][ws];

            cout<< answer<< "\n";
        }
    }
}
