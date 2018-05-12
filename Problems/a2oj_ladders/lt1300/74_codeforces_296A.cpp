#include <cstdio>
#include <iostream>
#include <iterator>
#include <cstdint>
#include <vector>
#include <map>

bool swappable(std::vector<int> &v){
  std::map<int,int> szs;
  for (auto it=v.begin(); it!=v.end(); ++it){
    ++szs[*it];
  }

  int maxNum=-1;
  for (auto it=szs.begin(); it!=szs.end(); ++it){
    if (it->second > maxNum){
      maxNum = it->second;
    }
  }

  if (maxNum > (v.size()+1)/2){
    return false;
  }
  return true;
}

//cin.ignore() NOT WORKING NICE
int main(){
  int trashcan;
  std::cin >> trashcan;
  std::vector<int> vals { std::istream_iterator<int>(std::cin), {}};
  if (swappable(vals)){
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
}
