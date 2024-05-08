import java.io.*;
import java.util.*;

public class Enclosure {
    private ArrayList<Animal> animals;

    public Enclosure() {
        // Inisialisasi ArrayList animals kosong
        animals = new ArrayList<Animal>();
    } 

    public int getAnimalCount() {
        // Mengembalikan jumlah hewan dalam this.animals
        return this.animals.size();
    }

    public void addAnimal(Animal animal) {
        // menambahkan seekor hewan ke dalam this.animals
        this.animals.add(animal);
    }

    public Animal getAnimalAt(int i) {
        // mengembalikan hewan dalam this.animals pada index i (tidak mengubah this.animals)
        return animals.get(i);
    }

    public void removeAnimalAt(int i) {
        // menghapus hewan pada this.animals pada index i
        animals.remove(i);
    }

    public boolean isEmpty() {
        // mengembalikan boolean yang menyatakan apakah this.animals kosong atau tidak
        return animals.size()<=0;
    }

    public void describe() {
        // Menuliskan output berikut apabila this.animals kosong:
        // Kandang ini kosong...
        // Apabila tidak kosong menuliskan output serupa dengan output berikut:
        // Kandang berisi 2 ekor hewan:
        // 1. po, spesies Pandamus Maximus, umur 5 tahun
        // 2. po2, spesies Pandamus Maximus, umur 5 tahun
        if(isEmpty()){
            System.out.println("Kandang ini kosong...");
        }else{
            System.out.println("Kandang berisi "+ animals.size() +" ekor hewan:");
            for (int i = 0; i < animals.size(); i++) {
                System.out.println((i+1) + ". " + getAnimalAt(i).getName() + ", spesies " + getAnimalAt(i).getSpecies()+ ", umur "+ getAnimalAt(i).getAge() + " tahun");    
            }
        }
    }

    public void feed() {
        // Menuliskan output berikut apabila this.animals kosong:
        // Kandang ini kosong...
        // Apabila tidak kosong maka akan memanggil method eat pada tiap animal dalam this.animals
        if(isEmpty()){
            System.out.println("Kandang ini kosong...");
        }else{
            for (Animal animal : animals) {
                animal.eat();
            }
        }
    }

    public boolean safeForPetting() {
        // mengembalikan true apabila semua hewan dalam this.animals bersifat friendly
        boolean safe = true;
        for (Animal animal : animals) {
            if(!animal.isFriendly()){
                safe = false;
            }
        } 
        return safe;
    }

    public static void main(String[] args) {
        // Enclosure enc1 = new Enclosure();
        // Panda panda1 = new Panda("po", 5);
        // Panda panda2 = new Panda("po2", 5);
        // enc1.addAnimal(panda1);
        // enc1.addAnimal(panda2);
        // enc1.describe();

        Enclosure enc1 = new Enclosure();
        enc1.describe();
    }
}