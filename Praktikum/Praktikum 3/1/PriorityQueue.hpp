#ifndef PRIO_QUEUE_HPP
#define PRIO_QUEUE_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

template<class T>
class PriorityQueue {
    private:
        int size;
        std::vector<T> content;
    public:
    /*
        Default constructor, size = 0
    */
    PriorityQueue():size(0){}
    /*
        Destructor
    */
    ~PriorityQueue(){
        while(content.size()!=0){
            content.pop_back();
        }
        size = 0;
    }   
    /*
        Menambahkan nilai T ke dalam content
    */   
    void Enqueue(T value){
        // 5,3,7,2,9
        // 9,7,5,3,2
        if (content.empty()) {
            content.push_back(value);
        } else {
            int i = content.size() - 1;
            content.push_back(value);
            while (i >= 0 && value > content[i]) {
                content[i + 1] = content[i];
                i--;
            }
            content[i + 1] = value;
        }
        size++;
    }

    /*
        Mengembalikan nilai pada posisi paling depan dari queue dan menghapus nilai tersebut
        Dijamin PrioriryQueue tidak kosong
    */
    T Dequeue(){
        T temp = Front();
        for(int i=0; i<content.size()-1; i++){
            content[i]=content[i+1];
        }
        content.pop_back();
        size-=1;
        // cout<<size<<endl;
        return temp;
    }

    /*
        Mengembalikan nilai pada posisi paling depan dari queue
        Dijamin PriorityQueue tidak kosong
    */
    T Front(){
        return content[0];
    }

    /*
        Menambahkan elemen pada priority queue pq ke dalam content
    */
    void MergeQueue(const PriorityQueue<T>& pq){
        for(int i =0; i< pq.GetSize(); i++){
            Enqueue(pq.content[i]);
        }
    }

    /*
        Mengembalikan banyak data dari priority queue ini
    */
    int GetSize() const{
        return size;
    }

    /*
        Operator overloading untuk mencetak isi priority queue
        Contoh: (3, 2, 1)
        Apabila kosong, tampilkan ()
    */
    friend ostream& operator<<(ostream& os, PriorityQueue<T> other){
        os << "(" ; 
        while(other.GetSize()>0){
            os << other.Dequeue();
            if(other.GetSize()>0){
                os << ", ";
            }

        }
        os << ")" << endl ; 
        return os;
    }


};



#endif