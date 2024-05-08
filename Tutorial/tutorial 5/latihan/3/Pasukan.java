import java.util.*;
public class Pasukan {
    private List<Integer> list;
    private int n;

    public Pasukan(List<Integer> list, int n){
        this.list = list;
        this.n = n;
    }

    public void reset(){
        list.clear();
        for (int i = 0; i < n; i++) {
            list.add(0);
        }
    }
    public long get(int idx){
        reset();
        long start = Util.getTime();
        int val = list.get(idx);
        long finish = Util.getTime();
        return start-finish;

    }
    public long del(int idx, int t){
        reset();
        long start = Util.getTime();
        for (int i = 0; i < t; i++) {
            list.remove(idx);
        }
        long finish = Util.getTime();
        return start-finish;
    }
}
