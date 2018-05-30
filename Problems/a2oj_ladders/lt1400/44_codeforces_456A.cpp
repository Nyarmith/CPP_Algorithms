#include <cstdio>
#include <string>
#include <cstdint>
#include <algorithm>
#include <utility>
#include <iostream>
#include <vector>

int main(){
  std::vector<std::pair<int,int>> qualPair;
  int n;
  std::cin >> n;
  for (int i=0; i<n; ++i){
    int quality, price;
    std::cin >> price >> quality;
    qualPair.push_back(std::make_pair(quality,price));
  }

  std::sort(qualPair.begin(), qualPair.end());

  for (int i=1; i<n; ++i){
    if (qualPair[i].first > qualPair[i-1].first && 
        qualPair[i].second < qualPair[i-1].second){
      std::cout << "Happy Alex";
      return 0;
    }
  }
  std::cout << "Poor Alex";
}
