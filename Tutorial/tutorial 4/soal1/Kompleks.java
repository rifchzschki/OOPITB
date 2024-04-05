// package soal1;
public class Kompleks{
    private static int n_kompleks = 0;
    private int real;
    private int imaginer;

    public Kompleks(){
        real = 0;
        imaginer = 0;
        n_kompleks+=1;
    }

    public Kompleks(int real, int imaginer){
        this.real = real;
        this.imaginer = imaginer;
        n_kompleks +=1;
    }

    public int getReal(){
        return real;
    }

    public int getImaginer(){
        return imaginer;
    }

    public void setReal(int real){//11
        this.real = real;
    }

    public void setImaginer(int imaginer){//12
        this.imaginer = imaginer;
    }

    public Kompleks plus(Kompleks b){
        return new Kompleks(real + b.getReal(), imaginer + b.getImaginer());
    }

    public Kompleks minus(Kompleks b){
        return new Kompleks(real - b.getReal(), imaginer - b.getImaginer());
    }

    public Kompleks multiply(Kompleks b){
        return new Kompleks(real * b.getReal() - imaginer * b.getImaginer(), imaginer * b.getReal() + real * b.getImaginer());
    }
    
    public Kompleks multiply(int n){
        return new Kompleks(real * n, imaginer * n);
    }

    public static int countKompleksInstance(){
        return n_kompleks;
    }

    public void print(){
        String str;
        if(real!=0 && imaginer !=0){
            if(imaginer == 1){
                str = String.valueOf(real) + "+" + "i"; 
            }else if(imaginer == -1){
                str = String.valueOf(real) + "-" + "i"; 
            }else{
                if(imaginer>0){
                    str = String.valueOf(real) + "+" + String.valueOf(imaginer) + "i"; 
                }else{
                    str = String.valueOf(real) + String.valueOf(imaginer) + "i"; 
                }
            }
        }else{
            if(real==0){
                if (imaginer!=0){
                    if(imaginer == 1){
                        str = "i"; 
                    }else if(imaginer == -1){
                        str = "-" + "i"; 
                    }else{
                        str = String.valueOf(imaginer) + "i"; 
                    }
                }else{
                    str = "0";
                }
            }else{
                str = String.valueOf(real); 
            }
        }
        System.out.println(str);
    }
}