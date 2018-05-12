#include <iostream>
#include <string>
#include <cstdio>
#include <cstdint>


int main(){
  std::string w="";
  char c=std::getchar();
  bool deld=false;
  while (c != EOF){
    if (!deld && c == '0'){
      //skip
      deld=true;
    } else {
      w += c;
    }
    c = getchar();
  }
  if (!deld){ //they are all ones
    w.erase(0,1);
  }
  std::cout << w;
}
