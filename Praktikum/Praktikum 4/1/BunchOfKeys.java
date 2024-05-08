public class BunchOfKeys{
    private int n_keys;

    public BunchOfKeys(){
        this.n_keys = 0;
    }

    public int getNKeys(){
        return n_keys;
    }

    public void add(){
        this.n_keys +=1;
    }

    public void shake(){
        if(this.n_keys<=1){
            System.out.println("Tidak terjadi apa-apa");
        }else{
            int i;
            for(i=0; i<this.n_keys; i++){
                System.out.println("krincing");
            }
        }
    }
}