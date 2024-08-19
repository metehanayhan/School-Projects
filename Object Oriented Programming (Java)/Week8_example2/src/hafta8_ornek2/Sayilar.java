package hafta8_ornek2;

abstract class Sayilar implements BasamakToplamıHesapla {
    public int sayi;

    public Sayilar(int sayi) {
        this.sayi = sayi;
    }

    public abstract void SayiBilgisi();
}