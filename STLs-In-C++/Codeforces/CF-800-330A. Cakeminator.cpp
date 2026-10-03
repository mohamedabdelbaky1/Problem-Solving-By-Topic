/*
Author: Mohamed Abdelbaky Tony
Platform: Codeforces
Rating: 800
Topics: Implementation, Set
Link: https://codeforces.com/problemset/problem/330/A


Idea:
The cakerinator can eat any row or column that does not contain a strawberry.

So:
- Any row containing 'S' can never be eaten.
- Any column containing 'S' can never be eaten.

The cells that will remain uneaten are exactly the intersection of:
- rows that contain strawberries
- columns that contain strawberries

Therefore:

Maximum eaten cells =
Total cells - (number of rows containing strawberries × number of columns containing strawberries)


Approach:
1. Read the cake dimensions R and C.
2. Store the cake grid.
3. While reading the grid:
      - If a cell contains 'S':
            - Add its row index to RowsCantBeEaten.
            - Add its column index to ColumnsCantBeEaten.
4. Count the cells that cannot be eaten:
      Rows containing strawberries × Columns containing strawberries.
5. Subtract these cells from the total number of cells.
6. Print the answer.


Complexity:
Time: O(R * C) because we scan every cell in the grid once.

Auxiliary Space: O(R + C) because we store the rows and columns that contain strawberries.

In general:
Time : O(n * m) where n is the number of rows and m is the number of columns.
Space : O(n + m) for storing blocked rows and columns.
*/


// Solution:

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int R , C ;
    cin>>R>>C;
    char arr[10][10];
    set<int>RowsCantBeEaten;
    set<int>ColumnsCantBeEaten;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]=='S')
            {
                RowsCantBeEaten.insert(i);
                ColumnsCantBeEaten.insert(j);
            }
        }
    }
    int ans = R * C - RowsCantBeEaten.size() * ColumnsCantBeEaten.size();
    cout<< ans;
}
