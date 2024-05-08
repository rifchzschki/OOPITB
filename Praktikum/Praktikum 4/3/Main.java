public class Main {
    public static void main(String[] args) {
        Agility A = new Agility(1);
        Strength B = new Strength(1);
        Intelligence C = new Intelligence(1);
    
        A.printInfo();
        B.printInfo();
        C.printInfo();

        if(Comparator.isObj1BiggerThanObj2(B,A)){
            System.out.println("true");
        }
        
        if(Comparator.isObj1EqualToObj2(B, A)){
            System.out.println("sama");
            
        }
        
        if(Comparator.isObj1LowerThanObj2(B, A)){
            System.out.println("false");

        }
    }
}
