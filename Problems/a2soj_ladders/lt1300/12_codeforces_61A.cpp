#include <string>
#include <iostream>
#include <cstdint>
#include <bitset>

int main(){
  std::string s1, s2;
  std::cin >> s1 >> s2;

  std::bitset<100> b1(s1);
  std::bitset<100> b2(s2);

  std::cout << (b1 ^ b2).to_string().substr(100-s1.size());
}
