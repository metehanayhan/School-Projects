package hafta8_ornek2;

public class Anasayfa {
    public static void main(String[] args) {
        İkiBasamakliSayi ikiBasamakliSayi = new İkiBasamakliSayi(45);
        ikiBasamakliSayi.SayiBilgisi();
        ikiBasamakliSayi.SayıBaBul();
        System.out.println("Basamakların Toplamı: " + ikiBasamakliSayi.Topla());
    }
}