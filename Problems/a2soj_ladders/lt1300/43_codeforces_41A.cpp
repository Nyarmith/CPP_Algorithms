#include <iostream>
#include <string>

bool compareStrs(const std::string& s1, const std::string& s2){
  auto it = s1.begin();
  for (auto rit=s2.rbegin(); rit!=s2.rend(); ++rit){
    if (*it != *rit)
      return false;
    ++it;
  }
  return true;
}

int main(){
  std::string s1, s2;
  std::cin >> s1 >> s2;

  if (compareStrs(s1,s2))
    printf("YES");
  else
    printf("NO");
}
