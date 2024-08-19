package hafta8_ornek2;

class İkiBasamakliSayi extends Sayilar implements SayıBasamaklarıBul {
    private int bs;

    public İkiBasamakliSayi(int sayi) {
        super(sayi);
        this.bs = 2;
    }

    @Override
    public void SayiBilgisi() {
        System.out.println("Sayı: " + sayi + " Basamak Sayısı: " + bs);
    }

    @Override
    public void SayıBaBul() {
        int birinciBasamak = sayi / 10;
        int ikinciBasamak = sayi % 10;
        System.out.println("Birinci Basamak: " + birinciBasamak + ", İkinci Basamak: " + ikinciBasamak);
    }

    @Override
    public int Topla() {
        int birinciBasamak = sayi / 10;
        int ikinciBasamak = sayi % 10;
        return birinciBasamak + ikinciBasamak;
    }
}