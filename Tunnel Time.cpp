#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

long long getSecondsElapsed(long long C, int N, vector<long long> A, vector<long long> B, long long K) {
  // Step 1: Sort A and B in ascending order
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  // Step 2: Calculate the total length of all tunnels
  long totalTunnel = 0;
  for (int i = 0; i < N; i++) {
    totalTunnel += B[i] - A[i];
  }
  // Step 3: Calculate the number of full laps the train makes around the track
  long laps = K / totalTunnel;

  // Step 4: Calculate the remaining distance to reach the target tunnel time
  long remainder = K % totalTunnel;

  // Step 5: Handle the case where the target tunnel time is reached at the end of a lap
  if (remainder == 0) {
      return C * laps - (C - B[N - 1]);
  }
  // Step 6: Find the tunnel where the target tunnel time is reached
  int i = 0;
  while (remainder > 0) {
      remainder -= B[i] - A[i];
      i++;
  }
  // Step 7: Calculate the total time it takes for the train to reach the target tunnel time
  return C * laps + B[i - 1] + remainder;
}
