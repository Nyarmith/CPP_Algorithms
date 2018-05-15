#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

class charSet{
  private:
    int chars[26];
  public:
    charSet(){
      std::fill(chars,chars+26,0);
    }
    charSet(std::string word){
      std::fill(chars,chars+26,0);
      for (auto it=word.begin(); it!=word.end(); ++it){
        if (std::isalpha(*it)){
          ++chars[std::tolower(*it)-'a'];
        }
      }
    }
    charSet operator+(const charSet& o){
      charSet ret;
      for (int i=0; i<26; ++i){
        ret.chars[i] = chars[i] + o.chars[i];
      }
      return ret;
    }
    bool operator==(const charSet& o){
      for (int i=0; i<26; ++i)
        if (chars[i] != o.chars[i])
          return false;
      return true;
    }
};

int main(){
  std::string l1,l2,l3;
  std::cin >> l1 >> l2 >> l3;
  charSet c1(l1), c2(l2), c3(l3);
  if (c1 + c2 == c3)
    std::cout << "YES";
  else
    std::cout << "NO";
}
