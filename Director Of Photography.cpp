#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

int getArtisticPhotographCount(int N, string C, int X, int Y) {
/*
Create two vectors prefixPSum and prefixBSum, both of size N+1 and initialize all elements to 0.
Iterate through the string C from left to right, and for each character:
  a. If it is 'P', add 1 to the previous element of prefixPSum and set it to the current element.
  b. If it is 'B', add 1 to the previous element of prefixBSum and set it to the current element.
  c. Otherwise, set the current element of both prefix vectors to the previous element.

Initialize the result to 0.

Define a lambda function called bounded, 
Which takes an integer x and returns the integer max(0, min(x, N)).

Iterate through the string C from left to right, and for each character:
  a. If it is 'A', do the following:
    i. Calculate the left window start and end indices as i-Y and i-X+1 respectively, 
    and apply the bounded function to both.
    ii. Calculate the right window start and end indices as i+X and i+Y+1 respectively, 
    and apply the bounded function to both.
    iii. Calculate the leftPs as prefixPSum[leftWindowEnd] - prefixPSum[leftWindowStart], 
    and rightBs as prefixBSum[rightWindowEnd] - prefixBSum[rightWindowStart].
    iv. Add the product of leftPs and rightBs to the result.
    v. Calculate the rightPs as prefixPSum[rightWindowEnd] - prefixPSum[rightWindowStart], 
    and leftBs as prefixBSum[leftWindowEnd] - prefixBSum[leftWindowStart].
    vi. Add the product of leftBs and rightPs to the result.
Return the result.
*/
    vector<int> prefixPSum(N+1, 0);
    vector<int> prefixBSum(N+1, 0);

    for (int i = 0; i < N; i++) {
        if (C[i] == 'P') {
            prefixPSum[i+1] = prefixPSum[i] + 1;
        } else {
            prefixPSum[i+1] = prefixPSum[i];
        }
        if (C[i] == 'B') {
            prefixBSum[i+1] = prefixBSum[i] + 1;
        } else {
            prefixBSum[i+1] = prefixBSum[i];
        }
    }

    int result = 0;

    auto bounded = [N](int x) -> int {
        return max(0, min(x, N));
    };

    for (int i = 0; i < N; i++) {
        if (C[i] == 'A') {
            int leftWindowStart = bounded(i - Y);
            int leftWindowEnd = bounded(i - X + 1);
            int rightWindowStart = bounded(i + X);
            int rightWindowEnd = bounded(i + Y + 1);

            int leftPs = prefixPSum[leftWindowEnd] - prefixPSum[leftWindowStart];
            int rightBs = prefixBSum[rightWindowEnd] - prefixBSum[rightWindowStart];
            result += leftPs * rightBs;

            int rightPs = prefixPSum[rightWindowEnd] - prefixPSum[rightWindowStart];
            int leftBs = prefixBSum[leftWindowEnd] - prefixBSum[leftWindowStart];
            result += leftBs * rightPs;
        }
    }

    return result;

}
