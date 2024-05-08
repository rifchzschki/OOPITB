public class Strength extends Hero {
    public void printInfo(){
        System.out.printf("Strength Hero (Lvl %d)\n",level);    
    }
    public Strength(){
        super();
    }
    public Strength(int n){
        super(n);
        
    }
    public Double value(){
        return this.getLevel() + this.getLevel()*0.2;
    }
}
