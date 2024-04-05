
class TempatTinggal {
    private int luas;
    private double hargaBahanBangunan;

    public TempatTinggal(int luas, double hargaBahanBangunan){
        this.luas = luas;
        this.hargaBahanBangunan = hargaBahanBangunan;
    }

    public double hitungBiayaBangun(){
        return luas*hargaBahanBangunan;
    }

    public void setLuas(int luas){
        this.luas = luas;
    }

    public void setHargaBahanBangunan(double hargaBahanBangunan){
        this.hargaBahanBangunan = hargaBahanBangunan;
    }

    public int getLuas(){
        return luas;
    }
    
    public double getHargaBahanBangunan(){
        return hargaBahanBangunan;
    }
}

class Rumah extends TempatTinggal{
    public Rumah(int luas, double hargaBahanBangunan){
        super(luas, hargaBahanBangunan);
    }
    
    public Rumah(int lebar, int panjang, double hargaBahanBangunan){
        super(lebar*panjang, hargaBahanBangunan);
    }

    
    public double hitungBiayaBangun(double biayaOrmas){
        return hitungBiayaBangun()+biayaOrmas;
    }

    public void setLuas(int panjang, int lebar){
        setLuas(panjang*lebar);
    }
}

interface Kendaraan{
    float hitungJarakTempuh();
}

class Karavan extends TempatTinggal implements Kendaraan{
    private float bensin;
    private float pemakaianBensin;

    public Karavan(){
        super(0, 0);
        this.bensin = 0;
        this.pemakaianBensin = 0;
    }

    @Override
    public double hitungBiayaBangun(){
        return super.hitungBiayaBangun()*3;
    }

    public float hitungJarakTempuh(){
        return bensin * pemakaianBensin;
    } 

    public void setBensin(float bensin){
        this.bensin = bensin;
    }

    public void setPemakaianBensin(float pemakaianBensin){
        this.pemakaianBensin = pemakaianBensin;
    }

    public float getBensin(){
        return bensin;
    }

    public float getPemakaianBensin(){
        return pemakaianBensin;
    }
}