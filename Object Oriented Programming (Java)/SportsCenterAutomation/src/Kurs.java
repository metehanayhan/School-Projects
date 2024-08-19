//METEHAN AYHAN

public class Kurs {
    int kursId;
    String kursAd;

    public Kurs(int kursId, String kursAd) {
        this.kursId = kursId;
        this.kursAd = kursAd;
    }

    // Kurs sınıfının getter metotları
    public int getKursId() {
        return kursId;
    }

    public String getKursAd() {
        return kursAd;
    }
}