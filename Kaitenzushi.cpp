#include <bits/stdc++.h>
using namespace std;

int getMaximumEatenDishCount(int N, vector<int> D, int K) {
/*
  Input Validation:
    1) The function getMaximumEatenDishCount takes three arguments: 
      the number of dishes N, a vector of dish IDs D, 
      and the maximum number of unique dishes that can be eaten K.
      
    2) If N is 0 or the size of D is 0, or D size is not equal to N,
      return 0 since there are no dishes to eat or the input is invalid.
      
  Algorithm:
    1) Create an empty queue q to store the last K dishes eaten.

    2) Create a variable EatenDish initialized to 0 to keep track of 
      the count of unique dishes eaten.
      
    3) Create an empty unordered set eaten to store the unique dishes 
    that have been eaten.
    
  Loop:
    6. Loop through each dish in the D vector, from index 0 to N-1
    
    7. Check if the dish has already been eaten by checking if it's 
      present in the eaten set using count() method
    
    8. If the dish has already been eaten, continue to the next dish
    
    9. If the dish has not been eaten, add it to the end of the queue 
      q and to the eaten set
    
    10. Increment EatenDish by 1 to reflect that a new unique dish has 
      been eaten
    
    11. If the size of the queue q is greater than K, then remove the 
      front element of the queue and remove it
      from the eaten set
    
    12. Continue to the next dish until all dishes have been considered

    Out:

    13. Return the value of EatenDish, which represents the count of 
      unique dishes eaten
*/

  if (N == 0 || D.size() == 0 || D.size() != N) {
    return 0;
  }
  queue<int> q;
  int EatenDish = 0;
  unordered_set<int> eaten;
  for (int i = 0; i < N; i++) {
    if (eaten.count(D[i]) > 0) {
      continue;
    }
    q.push(D[i]);
    eaten.insert(D[i]);
    EatenDish++;
    if (q.size() > K) {
      int front = q.front();
      eaten.erase(front);
      q.pop();
    }
  }
  return EatenDish;
}
