#include <iostream>

bool isMultiple(int n)
{
  return (n%3==0 && n%5==0);
}

int main()
{
  using ull = unsigned long long;
  ull sum=0;
  for (int i=0; i<1000; ++i)
  {
    if (isMultiple(i)) sum+=i;
  }
  std::cout << sum << std::endl;
}
