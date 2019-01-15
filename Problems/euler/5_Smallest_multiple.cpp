#include <iostream>
#include <vector>
#include <cmath>

using ull = unsigned long long;

ull product(std::vector<ull> v)
{
  ull ret=1;
  for (auto i : v)
    ret *= i;
  return ret;
}

std::vector<ull> primeFactorize(ull n, std::vector<ull> &primes)
{
  std::vector<ull> ret;
  for (int i=0; n>1 && primes[i] <= n; ++i)
    while (n % primes[i] == 0)
    {
      ret.push_back(primes[i]);
      n /= primes[i];
    }
  return ret;
}

int main()
{
  std::vector<bool> isPrime(21,true);
  std::vector<ull> primes;
  ull i=2;
  while (i<isPrime.size())
  {
    if (isPrime[i])
    {
      for (ull j=i*2; j<isPrime.size(); j+=i)
        isPrime[j] = false;
      primes.push_back(i);
    }
    ++i;
  }

  int minComponents[21] = {0};
  //now decompose 1-20 into primes
  for (int i=2; i<=20; ++i)
  {
    int tempComponents[21] = {0};
    //break i down into primes
    auto p = primeFactorize(i,primes);
    for (auto j : p)
      ++tempComponents[j];
    //for each prime
    for (auto j : primes)
      if (tempComponents[j] > minComponents[j])
        minComponents[j] = tempComponents[j];
  }

  ull ret=1;
  for (int i=0; i<21; ++i)
    if (minComponents[i] != 0)
      ret *= std::pow(i,minComponents[i]);

  std::cout << ret << std::endl;
}
