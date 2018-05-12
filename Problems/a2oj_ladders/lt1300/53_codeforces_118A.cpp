#include <cstdio>
#include <cstdint>
#include <string>
#include <iostream>
#include <set>
#include <cctype>

std::set<char> vowels {'a','e','i','o','u','y'};
int main(){
  std::string w;
  std::string out = "";
  std::cin >> w;
  for (auto it=w.begin(); it!=w.end(); ++it){
    if ( vowels.find(std::tolower(*it)) == vowels.end() ){
      out += ".";
      out += std::tolower(*it);
    }
  }

  std::cout << out;
}

