#include <string>
#include <iostream>
#include <algorithm>

//little girl and game

/*
//dynamic programming to find distance from anagram
//then see if it's divisible by 2

int memo[1000][1000];

int pDels(const std::string &s, int l, int r){
  if (r <= l)
    return 0;

  if (memo[l][r] != -1)
    return memo[l][r];

  if (s[l] == s[r])
    return pDels(s,l+1,r-1);

  int ldel = pDels(s,l  ,r-1) + 1;
  int rdel = pDels(s,l+1,r  ) + 1;


  if (ldel < rdel)
    memo[l][r] = ldel;
  else
    memo[l][r] = rdel;

  return memo[l][r];
}
*/

bool letters[26] = {0};

int main(){
  std::string in;
  std::cin >> in;
  for (int i=0; i<in.length(); ++i){
    if (in[i] <= 'Z' && in[i] >= 'A'){
      in[i] -='a'-'A';
    }
    letters[in[i]-'a'] = !letters[in[i]-'a'];
  }

  int z=0;
  for (int k=0; k<26; ++k){
    z += letters[k];
  }

  if (z % 2 == 1 || z == 0){
    std::cout << "First";
  } else {
    std::cout << "Second";
  }
}
