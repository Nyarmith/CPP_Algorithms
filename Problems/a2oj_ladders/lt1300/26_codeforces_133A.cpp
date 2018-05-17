#include <iostream>
#include <cstdio>
#include <cstdint>

int main(){
  std::string w;
  std::cin >> w;
  for (auto it = w.begin(); it != w.end(); ++it){
    if (*it == 'H' || *it == 'Q' || *it == '9'){
      std::cout << "YES";
      return 0;
    }
  }

  std::cout << "NO";
}
