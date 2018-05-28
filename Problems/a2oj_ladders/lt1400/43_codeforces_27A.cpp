#include <cstdio>
#include <cstdint>
#include <iostream>
#include <string>
#include <algorithm>

bool ids[3001];

int main(){
  int n,tmp;
  std::cin >> n;
  for (int i=0; i<n; ++i){
    std::cin >> tmp;
    ids[tmp-1]=true;
  }

  for (int i=0; i<3001; ++i){
    if (!ids[i]){
      std::cout << i+1;
      return 0;
    }
  }
}
