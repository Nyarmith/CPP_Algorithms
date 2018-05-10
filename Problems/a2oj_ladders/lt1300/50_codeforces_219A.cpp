#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::string;

int chars[26];
int gcd(int a, int b){
  if (a==0)
    return b;
  return gcd(b%a,a);
}

int main(){
  int n;
  string w;
  cin >> n;
  cin >> w;

  for (int i=0; i<w.length(); ++i){
    ++chars[w[i]-'a'];
  }
  int i=0;
  while (chars[i] == 0)
    ++i;

  int gcd_v=chars[i];
  while(i<26){
    if (chars[i] != 0)
      gcd_v = gcd(gcd_v,chars[i]);
    ++i;
  }

  if (w.size() == 1){
    cout << w;
  } else {

  if (gcd_v != 1){
    string out="";
    for (int i=0; i<26; ++i){
      if (chars[i] == 0)
        continue;
      out += string(chars[i] / gcd_v, 'a'+i);
    }
    for (int i=0; i<gcd_v; ++i){
      cout << out;
    }
  } else {
    cout << -1;
  }
  }
}

