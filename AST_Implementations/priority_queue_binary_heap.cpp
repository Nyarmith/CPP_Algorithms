#include <iostream>

using namespace std;

//PRIORITY QUEUE
//Basic Definition:
// - Can insert new item
// - Can remove item with the largest key

//Array heap implmentation of priority queue

template <class Item> class PQ
{
    private:
        Item *pq; // generic array type we declare
        int N;
    public:
        PQ(int maxN)
        { pq = new Item[maxN]; N = 0; }

        int empty() const
        { return N == 0;}

        void swap(int a, int b) //swap elements in index a and b of array
        {
            Item temp = pq[a];
            pq[a] = pq[b];
            pq[b] = temp;
        }

        void insert(Item item)
        {
            pq[N] = item;
            N++;
            heapify();
        }

        Item getmax()
        { 
            swap(0,--N);    //swap last valid element in our array with our max
            heapify();      //we need to resort the heap
            return pq[N];
        }

        void heapify()
        {
            int i=N-1;
            while(i>0 && pq[i/2]<pq[i])
            {
                swap(i/2,i);
                i/=2;
            }
        }
};

//maintains relationship of val[index*2+1]<val[index], val[index*2]<val[index]
int main()
{
    PQ<int> myQueue(200);
    myQueue.insert(3);
    myQueue.insert(4);
    myQueue.insert(2);
    myQueue.insert(100);
    myQueue.insert(1);
    cout<<myQueue.getmax();
}
