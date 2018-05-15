#include <iostream>
#include <string>
#include <map>

int main(){
  std::string w;
  std::map<int,int> nums;
  std::cin >> w;
  for (auto it=w.begin(); it!=w.end(); ++it){
    if (*it != '+'){
      ++nums[*it - '0'];
    }
  }
  //print
  std::string out="";
  for (auto it=nums.begin(); it!=nums.end(); ++it){
    std::string append=std::to_string(it->first);
    for (int i=1; i<it->second; ++i){
      append += "+" + std::to_string(it->first);
    }
    out += "+" + append;
  }

  std::cout << out.substr(1);
}
