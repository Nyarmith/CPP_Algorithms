#include <cstdio>
#include <iostream>
#include <string>
#include <cstdint>
#include <algorithm>
#include <set>


int arr[100][100]; //max array size = 100x100

int main(){
  std::set<int> s;
  int n,m,d;
  std::cin >> n >> m >> d;
  bool isPossible=true;
  int avg=0;
  for (int r=0; r<n; ++r){
    for (int c=0; c<m; ++c){
      std::cin >> arr[r][c];
      avg += arr[r][c];
      s.insert(arr[r][c]);
    }
  }
  avg /= n*m;
  if (avg % d != 0){
    if (avg % d < avg/2){
      avg -= avg % d;
    } else {
      avg += d - avg % d;
    }
  }


  int prev = arr[0][0];
  for (int r=0; r<n; ++r){
    for (int c=0; c<m; ++c){
      if (prev%d != arr[r][c]%d)
        isPossible = false;
    }
  }

  if (!isPossible)
    std::cout << (-1);
  else{

    int minMoves=200000000;
    for (auto it=s.begin(); it!=s.end(); ++it){
    int moves=0;
    for (int r=0; r<n; ++r){
      for (int c=0; c<m; ++c){
        moves += std::abs(arr[r][c] - *it) / d;
      }
    }
    if (moves < minMoves)
      minMoves = moves;
    }

    std::cout << minMoves;
  }
}
