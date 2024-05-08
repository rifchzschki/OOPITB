public class Intelligence extends Hero {
    public void printInfo(){
        System.out.printf("Intelligence Hero (Lvl %d)\n",level);    
    }
    public Intelligence(){
        super();
    }
    public Intelligence(int n){
        super(n);
    }
    public Double value(){
        return this.getLevel() + this.getLevel()*0.1;
    }
}
