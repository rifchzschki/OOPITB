#include "PriorityQueue.hpp"
#include <iostream>

using namespace std;

int main(){
    PriorityQueue<int> p;
    PriorityQueue<int> q;
    p.Enqueue(5);
    p.Enqueue(9);
    p.Enqueue(7);
    p.Enqueue(2);
    q.Enqueue(5);
    q.Enqueue(3);
    q.Enqueue(7);
    p.Enqueue(2);
    p.Enqueue(9);

    cout << "Priority Queue: " << p << endl;
    // cout << "T: " << p.Dequeue() << endl;

    cout << "Priority Queue: " << q << endl;
    p.MergeQueue(q);
    // cout << "Size: " << p.GetSize() << endl;
    cout << "Priority Queue: " << p << endl;

}
