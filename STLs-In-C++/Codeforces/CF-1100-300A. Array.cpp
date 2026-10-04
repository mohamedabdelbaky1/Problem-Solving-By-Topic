/*
Author: Mohamed Abdelbaky Tony
Platform: Codeforces
Rating: 1100
Topics: Implementation, Arrays, Brute Force
Link: https://codeforces.com/contest/300/problem/A


Idea:
We need to divide the array into three non-empty sets:

1. First set:
   Product of elements < 0
   → It must contain an odd number of negative numbers.

2. Second set:
   Product of elements > 0
   → It must contain either:
      - Positive numbers only
      - Or an even number of negative numbers

3. Third set:
   Product of elements = 0
   → It must contain all zeros and extra elements that are not needed
     in the first two sets.

The important observation:
- A single negative number always creates a negative product.
- A single positive number creates a positive product.
- Zero can always be placed in the third group.


Approach:
1. Read all array elements.
2. Check whether there is at least one positive number.

3. If positive numbers exist:
      - Put one negative number in the first set.
      - Put one positive number in the second set.
      - Put all remaining elements in the third set.

4. If there are no positive numbers:
      - Put one negative number in the first set.
      - Put two negative numbers in the second set 
        to make a positive product.
      - Put remaining elements in the third set.

5. Print the three groups.


Complexity:
Time: O(n) because we traverse the array a constant number of times.

Auxiliary Space: O(n) because we store the three resulting groups.
.
*/


// Solution:

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int arr[105] = {0};

    bool PosExist = 0;
    bool NegDone = 0;
    bool PosDone = 0;

    vector<int>Neg , Pos , Zero;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];

        if(arr[i]>0)
            PosExist = 1;
    }


    for(int i=0;i<n;i++)
    {
        if(PosExist)
        {
            if(arr[i]<0)
            {
                if(NegDone==0)
                {
                    Neg.push_back(arr[i]);
                    NegDone = 1;
                }
                else
                {
                    Zero.push_back(arr[i]);
                }
            }

            else if(arr[i]>0)
            {
                if(PosDone==0)
                {
                    Pos.push_back(arr[i]);
                    PosDone = 1;
                }
                else
                {
                    Zero.push_back(arr[i]);
                }
            }

            else
            {
                Zero.push_back(arr[i]);
            }
        }

        else
        {
            if(arr[i]<0)
            {
                if(NegDone==0)
                {
                    Neg.push_back(arr[i]);
                    NegDone = 1;
                }

                else
                {
                    if(Pos.empty()||Pos.size()==1)
                    {
                        Pos.push_back(arr[i]);
                    }
                    else
                    {
                        Zero.push_back(arr[i]);
                    }
                }
            }

            else
            {
                Zero.push_back(arr[i]);
            }
        }

    }


    cout<< Neg.size()<< " ";

    for(int i=0;i<Neg.size();i++)
    {
        cout<< Neg[i]<< " ";
    }

    cout<< "\n";


    cout<< Pos.size()<< " ";

    for(int i=0;i<Pos.size();i++)
    {
        cout<< Pos[i]<< " ";
    }

    cout<< "\n";


    cout<< Zero.size()<< " ";

    for(int i=0;i<Zero.size();i++)
    {
        cout<< Zero[i]<< " ";
    }
}
