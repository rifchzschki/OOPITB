package soal1;
public class Main {
    public static void main(String[] args) {
        // Membuat objek-objek kompleks
        Kompleks num1 = new Kompleks(3, 2);
        Kompleks num2 = new Kompleks(5, 7);
        Kompleks num3 = new Kompleks(0, 0);
        Kompleks num4 = new Kompleks(0, 1);
        // num3 = num3.plus(num4);
        // num3.setReal(20);
        num3.setImaginer(-1);
        num3.print();

        // Menambahkan dua objek kompleks
        Kompleks sum = num1.plus(num2);
        System.out.print("Penjumlahan: ");
        sum.print(); // Output: 8+9i

        // Mengurangkan dua objek kompleks
        Kompleks diff = num1.minus(num2);
        System.out.print("Pengurangan: ");
        diff.print(); // Output: -2-5i

        // Mengalikan dua objek kompleks
        Kompleks product = num1.multiply(num2);
        System.out.print("Perkalian: ");
        product.print(); // Output: 1+29i

        // Mengalikan objek kompleks dengan skalar
        Kompleks scaled = num1.multiply(2);
        System.out.print("Perkalian dengan skalar: ");
        scaled.print(); // Output: 6+4i

        // Menghitung jumlah instance dari kelas Kompleks
        System.out.println("Jumlah instance dari kelas Kompleks: " + Kompleks.countKompleksInstance()); // Output: 5
    }
}