// #include <bits/stdc++.h>
// using namespace std;
// // Write any include statements here

// long long getMaxAdditionalDinersCount(long long N, long long K, int M, vector<long long> S) {
//   // Write your code here
//   sort(S.begin(), S.end());
//   long long ans = 0;
//   for(int i = 1; i < M; i++) {
//     long long p = S[i]; // this is our pivot
//     long long left_empty = p-1; 
//     long long right_empty = N-p;
//     long long left_add = min(left_empty, K); // diners we can put to left
//     long long right_add = min(right_empty, K); // diners we can put to right
    
//     if(left_add == K && right_add == K) {
//       ans += 2*K;
//     } else {
//       long long add = left_add + right_add; // Total additional diners
//       if (left_add < K && right_add < K && left_empty + right_empty >= 2*K) {
//         add = 2*K;
//       } 
//       ans += add;
//     }
//   }
//   return ans;
// }

#include <bits/stdc++.h>
using namespace std;

long long getMaxAdditionalDinersCount(long long N, long long K, int M, vector<long long> S) {
    // Sort the existing diners' positions in ascending order
    sort(S.begin(), S.end());
    
    // Initialize variables
    long long extraSpace = 0; // Tracks the number of required additional diners
    long long firstOpenSeat = 1; // Tracks the first available seat
    
    // Iterate through each existing diner's seat position
    for (long long takenSeat : S) {
        // Calculate the number of available seats to the left of the current diner
        long long openSeats = takenSeat - K - firstOpenSeat;
        // If there are any available seats to the left of the current diner, calculate the number of required additional diners and add it to the total
        if (openSeats > 0) {
            extraSpace += ceil((double)openSeats / (K + 1));
        }
        // Update the first available seat to the right of the current diner
        firstOpenSeat = takenSeat + K + 1;
    }
    
    // Calculate the number of available seats to the right of the last diner
    long long openSeats = N + 1 - firstOpenSeat;
    // If there are any available seats to the right of the last diner, calculate the number of required additional diners and add it to the total
    if (openSeats > 0) {
        extraSpace += ceil((double)openSeats / (K + 1));
    }
    
    // Return the total number of required additional diners
    return extraSpace;
}
