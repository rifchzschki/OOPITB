

public class Agility extends Hero{
    public Agility(){
        super();
    }
    public Agility(int n){
        super(n);
    }
    public void printInfo(){
        System.out.printf("Agility Hero (Lvl %d)\n",level);    
    }
    public Double value(){
        return  this.getLevel() + this.getLevel()*0.3;
    }
}
