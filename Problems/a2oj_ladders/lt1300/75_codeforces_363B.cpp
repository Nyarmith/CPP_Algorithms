#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cstdint>
#include <climits>


class minQueue{
  int qmaxlen_;
  int qminin_;
  int i_;
  int qsz_;
  int minsz_;
  std::list<int> seq_;
  void checkmin(){
    if ((int)seq_.size() == qmaxlen_ && qsz_ < minsz_){
      minsz_ = qsz_;
      qminin_ = i_ - qmaxlen_;
    }
  }

  public:
  void add(int a){
    ++i_;
    seq_.push_back(a);
    qsz_ += a;
    if ( (int)seq_.size() > qmaxlen_ ){
      qsz_ -=  seq_.front();
      seq_.pop_front();
    }
    checkmin();
  }
  int minseqsize(){
    return minsz_;
  }
  int minseqin(){
    return qminin_;
  }
  minQueue(int k){
    qmaxlen_ = k;
    minsz_ = INT_MAX ;
    qminin_=0;
    i_=qsz_=0;
  }
};

int main(){
  int n,k,tmp;
  std::cin >> n >> k;
  minQueue soln(k);
  for (int i=0; i<n; ++i){
    std::cin >> tmp;
    soln.add(tmp);
  }
  std::cout << soln.minseqin()+1;
}
