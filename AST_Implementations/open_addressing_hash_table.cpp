#include <iostream>
#include <string>
#include <stdexcept>

template <class K, class V>
struct HashNode
{
    K key;
    V val;
};

template <class K, class V>
class HashTable
{
public:
    using Node=HashNode<K,V>;

    HashTable(unsigned capacity): cap_(capacity)
    {
        arr_ = new Node*[cap_];
        for (unsigned i=0; i<cap_; ++i)
            arr_[i] = nullptr;
    }

    HashTable() : HashTable(defaultSize_) {}

    void Insert(K key, V val)
    {
        auto i = hash(key);
        auto j=i;
        Node *tmp = new Node{key,val};
        while(arr_[i] != nullptr && arr_[i]->key != key)
        {
            ++i;
            i %= cap_;
            if (i == j) throw std::runtime_error("hashtable full!");
        }
        
        if(arr_[i] == nullptr)
            ++size_;

        arr_[i] = tmp;
    }
    
    V remove(unsigned key)
    {
        auto i = hash(key);
        while(arr_[i])
        {
            if(arr_[i]->key == key)
            {
                V tmp = arr_[i]->val;
                delete arr_[i];
                arr_[i] = nullptr;
                --size_;
                return tmp;
            }
            ++i;
            i %= cap_;
        }
        return {};
    }

    V get(K key)
    {
        auto i = hash(key);
        unsigned ctr = 0;

        while(arr_[i])
        {
            if (ctr++ > cap_) return {};

            if (arr_[i]->key == key)
                return arr_[i]->val;
            ++i;
            i %= cap_;
        }
        return {};
    }

    template<class I, class J>
    friend std::ostream& operator<<(std::ostream  &os, const HashTable<I,J> &dt);
private:
    static constexpr unsigned defaultSize_ = 20;
    unsigned hash(K key) { return key % cap_; }

    Node **arr_;
    unsigned cap_;
    unsigned size_;
};

template<class K, class V>
std::ostream& operator<<(std::ostream &os, const HashTable<K,V> &dt)
{
    for (unsigned i=0; i<dt.cap_; ++i)
    {
        if (i != 0)
            os << ", ";
        os << i << ":" << (dt.arr_[i] == nullptr ? 0 : dt.arr_[i]->val);
    }
    os << "\n";
    return os;
}

int main()
{
    HashTable<int,int> ht;
    ht.Insert(1,2);
    ht.Insert(18,19);
    std::cout << ht << "\n";
    ht.Insert(20,21);
    ht.Insert(21,22);
    std::cout << ht << "\n";
    std::cout << "removed: " << ht.remove(1) << "\n";
    std::cout << ht << "\n";
    std::cout << "get: " << ht.get(18) << "\n";
}
