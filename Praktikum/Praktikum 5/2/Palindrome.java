public class Palindrome<T> {
    //Method untuk mengecek apakah Deque dq merupakan palindrome
    //Deque dq merupakan palindrome jika elemen-elemen pada Deque dq dapat dibaca sama dari depan dan belakang
    public boolean isPalindrome(Deque<T> dq){
        boolean isPal = true;
        while(!dq.isEmpty()){
            try {
                T first = dq.popFront();
                if(!dq.isEmpty()){
                    T last = dq.popBack();
                    if(first!=last){
                        isPal = false;
                    }
                }
                
            } catch (Exception e) {
                // TODO: handle exception
            }
            
        }
        return isPal;

    }

    // public static void main(String[] args) {
    //     Deque<Integer> d = new Deque<Integer>();
        
    //     try {
    //         d.pushBack(1);
    //         d.pushBack(2);
    //         d.pushBack(3);
    //         d.pushBack(4);
    //         d.pushBack(5);
    //         // System.out.println(d.popBack());
    //         // System.out.println(d.popBack());
    //         // System.out.println(d.popBack());
    //         // System.out.println(d.popBack());
    //         d.reverse();
    //         Deque<Integer> q = new Deque<Integer>(d);

    //         while (!d.isEmpty()) {
    //             System.out.println(d.popFront());
    //             System.out.println(q.popFront());

    //         }
    //     } catch (Exception e) {
    //         // TODO: handle exception
    //         System.out.println(e.getMessage());
    //     }
    // }
}
