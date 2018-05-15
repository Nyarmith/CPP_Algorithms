#include <cstdio>
#include <cstdint>
#include <cinttypes>
#include <string>
#include <iostream>
#include <regex>
#include <algorithm> 
#include <cctype>
#include <locale>

// trim from start (in place)
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

static inline void trim(std::string &s) {
  ltrim(s);
  rtrim(s);
}

using std::regex;
using std::regex_replace;
using std::string;
using std::cin;
using std::cout;

int main(){
  string w;
  cin >> w;
  regex reg1("WUB");
  string res = regex_replace(w,reg1," ");
  //trim(res);
  std::cout << res;
}
