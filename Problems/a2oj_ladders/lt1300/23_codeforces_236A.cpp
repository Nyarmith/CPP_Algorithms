#include <cstdio>
#include <string>
#include <iostream>
#include <set>
#include <algorithm>

int main(){
  std::set<char> mySet;
  std::string name;
  std::cin >> name;
  std::for_each(name.begin(), name.end(),
      [&mySet] (char c) -> void { mySet.insert(c); });
  if (mySet.size() % 2 == 0){
    std::cout << "CHAT WITH HER!";
  } else {
    std::cout << "IGNORE HIM!";
  }
}
