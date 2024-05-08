public class Agility extends Hero{
    Agility(){
        super();
    }
    Agility(Integer level){
        super(level);
    }

    @Override
    public Double value(){
        return level*1.01;
    }

    @Override
    public void printInfo(){
        System.out.println("Agility Hero (Lvl "+ this.level +")");
    }

}