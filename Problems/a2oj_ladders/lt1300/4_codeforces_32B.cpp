#include <iostream>
#include <string>
#include <cstdint>

int main(){
  std::string outnum="";

  std::string bcode;
  std::cin >> bcode;

  uint32_t i = 0;
  while (i < bcode.length()){
    if (bcode[i] == '.'){
      outnum += '0';
      ++i;
      continue;
    }
    else if (bcode[i+1] == '-'){
      outnum += '2';
      i += 2;
      continue;
    }
    else{
      outnum += '1';
      i += 2;
      continue;
    }
  }

  std::cout << outnum << std::endl;
}
