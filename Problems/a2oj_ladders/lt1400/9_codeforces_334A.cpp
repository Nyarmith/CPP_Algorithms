#include <iostream>
#include <string>
#include <cstdio>

int main(){
  int n;
  std::cin >> n;
  int nsq = n*n;
  int bot = 1;
  for (int i=0; i<n; ++i){
  for (int i=0; i<n/2; ++i){
    std::cout << bot << " " << nsq << " ";
    ++bot;
    --nsq;
  }
  std::cout << "\n";
  }
}
