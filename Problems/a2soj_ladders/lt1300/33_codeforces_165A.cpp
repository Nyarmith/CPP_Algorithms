#include <cstdio>
#include <cstdint>
#include <vector>

using std::uint32_t;
using std::scanf;
using std::printf;


struct linkedPt{
  linkedPt *left, *right, *up, *down;
  int y,x;
  bool searched;

  linkedPt(){
    left=right=up=down=NULL;
    searched=false;
  }

  bool isSuperCenter(){
    return (left != NULL && right != NULL && up != NULL && down != NULL);
  }
  void propogate(linkedPt *pt){
    //which axis do I push you along?
    if ( pt->x == x){
      if (pt->y > y){
        if ( up == NULL ){
          pt->down = this;
          up = pt;
        }else if (up->y > pt->y){
          pt->up = up;
          pt->down = this;
          up->down = pt;
          up = pt;
        }
        else {
          up->propogate(pt);
        }
      } else {
        if ( down == NULL ){
          pt->up = this;
          down = pt;
        }else if (down->y < pt->y){
          pt->up=this;
          pt->down=down;
          down->up = pt;
          down=pt;
        } else {
          down->propogate(pt);
        }
      }
    } else if (pt->y == y){
      if (pt->x > x){
        if (right == NULL){
          pt->left = this;
          right = pt;
        } else if (right->x > pt->x){
          pt->right = right;
          pt->left = this;
          right->left = pt;
          right = pt;
        }
        else{
          right->propogate(pt);
        }
      } else {
        if (left == NULL){
          pt->right = this;
          left = pt;
        }else if (left->x < pt->x){
          pt->left=left;
          pt->right=this;
          left->right=pt;
          left=pt;
        } else {
          left->propogate(pt);
        }
      }
    }
  }

};

struct meshSpace{

  std::vector<linkedPt*> unique_x;
  std::vector<linkedPt*> unique_y;

  void insert(int y, int x){
    linkedPt *pt = new linkedPt();
    pt->y=y;
    pt->x=x;

    auto it = unique_x.begin();
    while ( it != unique_x.end()){
      if (pt->x < (*it)->x){
        unique_x.insert(it,pt);
        break;
      } else if (pt->x == (*it)->x){
        (*it)->propogate(pt);
        break;
      }
      ++it;
    }
    if (it == unique_x.end()){
      unique_x.push_back(pt);
    }

    it = unique_y.begin();
    while ( it != unique_y.end()){
      if (pt->y < (*it)->y){
        unique_y.insert(it,pt);
        break;
      } else if (pt->y == (*it)->y){
        (*it)->propogate(pt);
        break;
      }
      ++it;
    }
    if (it == unique_y.end()){
      unique_y.push_back(pt);
    }
  }
};

int count(linkedPt* elem){
  if (elem->searched)
    return 0;
  elem->searched = true;

  int cnt=0;
  if (elem->left != NULL)
    cnt += count(elem->left);
  if (elem->right != NULL)
    cnt += count(elem->right);
  if (elem->up != NULL)
    cnt += count(elem->up);
  if (elem->down != NULL)
    cnt += count(elem->down);

  if (elem->isSuperCenter())
    ++cnt;
  return cnt;
}

//so this whole thing resides on not having duplicates
int main(){
  meshSpace m;
  int n,y,x;
  scanf("%i", &n);
  for (int i=0; i<n; ++i){
    scanf("%i %i", &x, &y);
    m.insert(y,x);
  }
  int cnt=0;
  for (int i=0; i<m.unique_x.size(); ++i){
    cnt +=count(m.unique_x[i]);
  }

  printf("%i",cnt);
}
