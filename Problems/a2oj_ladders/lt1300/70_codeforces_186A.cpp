#include <cstdio>
#include <cstdint>
#include <string>
#include <iostream>

//two strings are considered in the "same race", if you can swap two characters to get the second dwarf's string

int main(){
  std::string w1, w2;
  std::cin >>  w1 >> w2;
  int fst = -1;
  int snd = -1;
  if (w1 == w2)
    std::cout << "YES";
  else{
    for (int i=0; i<w1.size(); ++i){
      if (w1[i] != w2[i]){
        if (fst == -1)
          fst = i;
        else {
          snd = i;
          break;
        }
      }
    }
    //swap chars and test
    char a = w1[fst];
    w1[fst] = w1[snd];
    w1[snd] = a;
    if (w1 == w2){
      std::cout << "YES";
    } else {
      std::cout << "NO";
    }
  }

}
