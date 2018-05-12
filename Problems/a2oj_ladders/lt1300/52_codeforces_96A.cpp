#include <cstdio>
#include <cstdint>
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;

//situation is dangerous there are at least 7 playesr of some team standing one after another

int main(){
  string w;
  int danger=0;
  bool dngr=false;
  cin >> w;
  auto it=w.begin();
  char s=*it;
  while(it != w.end()){
    if (*it == s){
      ++danger;
    } else {
      danger=1;
      s = *it;
    }
    ++it;
    if (danger == 7){
      dngr = true;
    }
  }
  if (dngr){
    cout << "YES";
  } else {
    cout << "NO";
  }
}
