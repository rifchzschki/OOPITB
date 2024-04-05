import java.lang.Comparable;

class MataKuliah implements Comparable<MataKuliah> {
    private float rating;
    private String nama;
    private int kodeJurusan;
    private int tahunPengambilan;

    public MataKuliah(String nama, int kodeJurusan, int tahunPengambilan, float rating){
        this.nama = nama;
        this.kodeJurusan = kodeJurusan;
        this.tahunPengambilan = tahunPengambilan;
        this.rating = rating;
    }

    public MataKuliah(float rating) {
        this.rating = rating;
    }

    public String getNama(){
        return nama;
    }

    public int getKodeJurusan(){
        return kodeJurusan;
    }

    public int getTahunPengambilan(){
        return tahunPengambilan;
    }

    public float getRating(){
        return rating;
    }

    public int compareTo(MataKuliah b) {
        /*
        1. MataKuliah A disebut kurang dari MataKuliah B bila:
            kode jurusan MataKuliah A lebih kecil dari MataKuliah B
            kode jurusan MataKuliah A sama dengan MataKuliah B, tapi tahun pengambilannya lebih kecil
            kode jurusan dan tahun pengambilan MataKuliah A sama dengan MataKuliah B, tapi rating nya lebih kecil

        2. MataKuliah A sama dengan MataKuliah B bila kode jurusan, tahun pengambilan, dan rating kedua MataKuliah bernilai sama

        3. Selain itu, MataKuliah A disebut lebih dari MataKuliah B
        */
        if(this.kodeJurusan==b.getKodeJurusan() && this.tahunPengambilan==b.getTahunPengambilan() && this.rating == b.getRating()){
            return 0;
        }else{
            if(this.kodeJurusan<b.getKodeJurusan()){
                return -1;
            }else if(this.kodeJurusan==b.getKodeJurusan()){
                if(this.tahunPengambilan<b.getTahunPengambilan()){
                    return -1;
                }else if(this.tahunPengambilan==b.getTahunPengambilan()){
                    if(this.rating<b.getRating()){
                        return -1;
                    }else{
                        return 1;
                    }
                }else{
                    return 1;
                }
            }else{
                return 1;
            }
        }
        
        // // compareTo mengembalikan:
        // // 0 bila this sama dengan m
        // // 1 bila this lebih dari m
        // // -1 bila this kurang dari m
        // if (this.rating == m.rating) {
        //     return 0;
        // } else if (this.rating > m.rating) {
        //     return 1;
        // } else {
        //     return -1;
        // }
    }
}