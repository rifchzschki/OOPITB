public class Intelligence extends Hero{
    Intelligence(){
        super();
    }

    Intelligence(Integer level){
        super(level);
    }

    @Override
    public Double value(){
        return level*0.99;
    }

    @Override
    public void printInfo(){
        System.out.println("Intelligence Hero (Lvl " +this.level+ ")");
    }

}
