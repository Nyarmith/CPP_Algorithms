#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <cstdio>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <set>
#include <map>
#include <utility>
#include <queue>
#define ll long long


void myMergeSort(std::vector<int>& arr, int i, int j)
{
  if (i+1 >= j){
    return;
  }

  int middle = (i+j)/2;

  //sort left
  myMergeSort(arr, i, middle);
  //sort right
  myMergeSort(arr, middle, j);


  //merge results
  ll t_i=i;
  ll t_j=middle;
  std::vector<int> results;
  results.reserve(j-i);
  while(t_i < middle && t_j < j){
    if (arr[t_j] < arr[t_i]){
      results.push_back(arr[t_j]);
      ++t_j;
    } else {
      results.push_back(arr[t_i]);
      ++t_i;
    }
  }
  //see where we ended
  if (t_i == middle){
    std::copy(arr.begin()+t_j, arr.begin()+j, std::back_inserter(results));
  } else {
    std::copy(arr.begin()+t_i, arr.begin()+middle, std::back_inserter(results));
  }

  ll loc = 0;
  //commit the sort
  while(i<j){
    arr[i] = results[loc];
    ++i;
    ++loc;
  }
}

int main(int argc, char** argv)
{
  if (argc < 2){
    std::cout << "Give me an int array, e.g. 1 2 3 4\n";
  }
  //merge-sort stdin
  std::vector<int> arr;
  for (int i=0; i<argc; ++i){
    arr.push_back(std::atoi(argv[i]));
  }

  myMergeSort(arr,0,argc);

  std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout," "));
}
