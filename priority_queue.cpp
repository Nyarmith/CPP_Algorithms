#include <iostream>

using namespace std;

//PRIORITY QUEUE
//Basic Definition:
// - Can insert new item
// - Can remove item with the largest key

//Naive array Implementation without sorting. God awful

template <class Item>
class PQ
{
    private:
        Item *pq; // generic array type we declare
        int N;
    public:
        PQ(int maxN)
        { pq = new Item[maxN]; N = 0; }
        int empty() const
        { return N == 0;}
        void insert(Item item)
        {pq[N++] = item;}
        Item getmax()
        { int max = 0;
            for (int j=1; j<N; j++)
                if (pq[max] < pq[j]) max = j;
            Item temp = pq[max];
            pq[max]=pq[N-1];
            pq[N-1]=temp;

            return pq[--N];
        }
};

int main()
{
    PQ<int> myQueue(200);
    myQueue.insert(3);
    myQueue.insert(4);
    myQueue.insert(2);
    myQueue.insert(1);
    myQueue.insert(100);
    cout<<myQueue.getmax();
}
