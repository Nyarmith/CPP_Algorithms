#include <iostream>
#include <vector>
#include <cmath>

using ull=unsigned long long;

ull n=600851475143;

int main()
{
  ull t = std::sqrt(n);
  std::vector<bool> isPrime(t+1,true);
  std::vector<ull> primes;
  ull ctr=2;
  while(ctr <= t)
  {
    if (isPrime[ctr])
    {
      for (ull i=ctr*2; i<=t; i+=ctr)
        isPrime[i] = false;
      primes.push_back(ctr);
    }

    ++ctr;
  }
  for (auto it=primes.rbegin(); it != primes.rend(); ++it)
    if (n%*it == 0)
      std::cout << *it << std::endl;
}
