import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

//Class Stack berikut merupakan suatu kelas GENERIC
//Stack disimpan dengan memanfaatkan ArrayList
//Element terakhir stack disimpan pada index paling kanan pada ArrayList
public class Stack<T> {

  private List<T> data;

  private int lastElmIdx, size;

  private final static int DEFAULT_STACK_SIZE = 500;


  //Constructor dengan size default
  public Stack(){
    data = new ArrayList<T>();
    lastElmIdx = -1;
    size = DEFAULT_STACK_SIZE;
  }
  
  //Constructore dengan size = n
  public Stack(int n){
    data = new ArrayList<T>();
    lastElmIdx = -1;
    size = n;
  }

  //Copy constructor dari stack lain
  public Stack(final Stack<T> q){
    this.size = q.size;
    this.lastElmIdx = q.lastElmIdx;
    this.data = q.data;
  }

  //Tambahkan elemen t ke dalam stack
  //Jika stack penuh, lempar exception "Stack is full"
  public void push(T t) throws Exception{
    if(isFull()){
      throw new Exception("Stack is full");
    }else{
      data.add(t);
      lastElmIdx+=1;
    }
  }

  //Hapus elemen terakhir dari stack
  //Jika stack kosong, lempar exception "Stack is empty"
  public T pop() throws Exception{
    if(isEmpty()){
      throw new Exception("Stack is empty");
    }else{
      T val = data.get(lastElmIdx);
      data.remove(lastElmIdx);
      lastElmIdx -=1;
      return val;
    }
  }

  //Cek apakah stack kosong
  public boolean isEmpty(){
    return data.size() == 0;
  }

  //Cek apakah stack penuh
  public boolean isFull(){
    return data.size() == size;
  }
}