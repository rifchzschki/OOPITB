public class Strength extends Hero{
    Strength(){
        super();
    }

    Strength(Integer level){
        super(level);
    }

    @Override
    public Double value(){
        return level*1.0;
    }

    @Override
    public void printInfo(){
        System.out.println("Strength Hero (Lvl "+super.getLevel()+")");
    }

}