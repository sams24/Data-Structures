#include<iostream>
using namespace std;

void swap(int& a, int& b)
{
    int t;
    t=a;
    a=b;
}
class heap
{
    private:
        int max_nodes;         //Max size of heap
        int n;   //Current number of nodes
        int * data;     //data is an array from 1 to length
        int parent(int i);
        int lchild(int i);
        int rchild(int i);
        void heapup(int node);
        void heapdown(int node);
    public:
        heap(int size);
        ~heap();
        void enq(int item);
        int deq(void);
        void display(void);
        void build_heap(void);
        void sort(void);

};

heap::heap(int size)
{
    data = new int[size];
}

heap::~heap()
{
    delete[] data;
}

inline int heap::parent(int i)
{
    return (i/2);
}

inline int heap::lchild(int i)
{
    return 2*i;
}

inline int heap::rchild(int i)
{
    return 2*i+1;
}

void heap::heapdown(int node)
{
    int maxc;// its larger child
    int l,r;
    l=lchild(node);
    r=rchild(node);

    if(l>max_nodes)
    {
        return;
    }
    else if(r>max_nodes)
    {
        maxc=l;
    }
    else if(data[l]>data[r])
    {
        maxc=l;
    }
    else
    {
        maxc=r;
    }
    swap(maxc,node);
    heapdown(maxc);
}

void heap::build_heap(void)
{
    int i;
    for(i=heap_size/2;i>=1;i--)
    {
        heapdown(i);
    }
    return;
}
