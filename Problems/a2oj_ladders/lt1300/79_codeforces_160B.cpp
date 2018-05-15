#include <cstdio>
#include <iostream>
#include <string>
#include <cstdint>
#include <queue>

int main(){
  std::priority_queue<int> left, right;
  int n;
  std::string w;
  std::cin >> n;
  std::cin >> w;
  for (int i=0; i<n; ++i){
    left.push(w[i]-'0');
  }
  for (int i=0; i<n; ++i){
    right.push(w[n+i]-'0');
  }
  if (left.top() == right.top()){
    std::cout << "NO";
    return 0;
  }
  if (left.top() > right.top()){
    while (left.size() > 0){
      if (left.top() <= right.top()){
        std::cout << "NO";
        return 0;
      }
      left.pop();
      right.pop();
    }

  }
  else {
    while (left.size() > 0){
      if (left.top() >= right.top()){
        std::cout << "NO";
        return 0;
      }
      left.pop();
      right.pop();
    }
  }
  std::cout << "YES";
  return 0;
}
