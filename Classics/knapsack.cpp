#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <cstdio>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <set>
#include <map>
#include <utility>
#include <queue>
#define ll long long

//you are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack


//Input:
//First line contains integer T for test-case number
// N - number of items, W, max capacity, then N integers determining value, then N integers determining weight

//constraints: N<=100, W<=100

//so we want to pick a subset of the items <= W, that maximizes the sum of teh values

//Idea: we are looking at subsequences of items
// - Given the i-th item, we are either including it or not
// * Subporoblem will have more information, index i and remaining capacity
// # subproblems = O(N*W) , number of items * capacity
// DP[i,X] =  max(DP[i+1,X], DP[i+1,X-s_i]+v_i)

int wgtArr[101];
int valArr[101];
int memo[101][101];

int maxValue(int N,int W);

int main(){
  for (int i=0; i<101; ++i){
    std::fill(memo[i],memo[i]+101,-1);
  }
  int T;
  
  std::cin >> T;

  for (int i=0; i<T; ++i){
    int N, W;
    std::cin >> N >> W;
    for (int i=0; i<N; ++i){
      std::cin >> valArr[i];
    }
    for (int i=0; i<N; ++i){
      std::cin >> wgtArr[i];
    }

    std::cout << maxValue(W,N);
  }
}


//we are operating on the N-th element
int maxValue(int W, int N)
{
  if (N == 0 || W == 0)
    return 0;

  if (memo[N][W] != -1)
    return memo[N][W];

  int objInd=N-1;
  if (wgtArr[objInd] > W)
    return maxValue(W, objInd);

  // So, now for the basic cases:
  // 1 - The item is included
  // 2 - The item is not included
  memo[N][W] = std::max(valArr[objInd] + maxValue(W-wgtArr[objInd],objInd),
                  maxValue(W,objInd));
  return memo[N][W];
}
