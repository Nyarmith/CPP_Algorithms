#include <iostream>
#include <string>
#include <map>

int main(){
  std::map<std::string, int> teams;
  std::string cw;
  int n;

  std::cin >> n;
  for (int i=0; i<n; ++i){
    std::cin>>cw;
    teams[cw]++;
  }

  n=-1;
  for (auto itr = teams.begin(); itr != teams.end(); ++itr){
    if (itr->second > n){
      n = itr->second;
      cw = itr->first;
    }
  }

  std::cout << cw;
}

