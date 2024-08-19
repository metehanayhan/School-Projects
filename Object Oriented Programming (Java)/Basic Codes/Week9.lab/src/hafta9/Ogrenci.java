package hafta9;

class Ogrenci {
    private static int counter = 1;

    private int no;
    private String ad;
    private String soyad;
    private int vizeNot;
    private int finalNot;
    private double gecmeNotu;

    public Ogrenci(String ad, String soyad, int vizeNot, int finalNot) {
        this.no = counter++;
        this.ad = ad;
        this.soyad = soyad;
        this.vizeNot = vizeNot;
        this.finalNot = finalNot;
        gecmeNotu= vizeNot*0.4+ finalNot*0.6;
    }



    public int getNo() {
        return no;
    }

    public String getAd() {
        return ad;
    }

    public String getSoyad() {
        return soyad;
    }

    public int getVizeNot() {
        return vizeNot;
    }

    public int getFinalNot() {
        return finalNot;
    }

    public double getGecmeNotu() {
        return gecmeNotu;
    }

   
}