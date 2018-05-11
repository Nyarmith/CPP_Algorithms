#include <iostream>
#include <string>

int lower[26];
int upper[26];

int main(){
  std::string w1,w2;
  std::getline(std::cin, w1);
  std::getline(std::cin, w2);
  for (auto it=w1.begin(); it!=w1.end(); ++it){
    if ('a'<=*it && *it<='z')
      ++lower[*it-'a'];
    if ('A'<=*it&&*it<='Z')
      ++upper[*it-'A'];
  }
  bool canMake=true;
  for (auto it=w2.begin(); it!=w2.end(); ++it){
    if ('a'<=*it && *it<='z')
      --lower[*it-'a'];
    if ('A'<=*it&&*it<='Z')
      --upper[*it-'A'];
  }
  for(int i=0; i<26; ++i){
    if(lower[i] < 0)
      canMake=false;
    if(upper[i] < 0)
      canMake=false;
  }
  if (canMake)
    std::cout << "YES";
  else
    std::cout << "NO";
}
