#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using ull = unsigned long long;

bool isPalindrome(ull n)
{
  std::string s = std::to_string(n);
  return std::equal(s.begin(),s.end(),s.rbegin());
}

std::vector<ull> palindromes;

int main()
{

  for (ull i=999; i>=100; --i)
  {
    for (ull j=999; j>=i; --j)
    {
      ull p = i*j;
      if (isPalindrome(p))
        palindromes.push_back(p);
    }
  }

  std::cout << *std::max_element(palindromes.begin(), palindromes.end()) << std::endl;
}
