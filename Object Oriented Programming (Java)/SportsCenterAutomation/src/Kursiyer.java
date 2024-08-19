//METEHAN AYHAN

import java.util.ArrayList;

public class Kursiyer implements Hesaplama{
		int kursiyerId;
	    String kursiyerAdSoyad;
	    int kursiyerYas;
	    ArrayList<Kurs> alinanKurslar = new ArrayList<>();

	    public Kursiyer(int kursiyerId, String kursiyerAdSoyad, int kursiyerYas) {
	        this.kursiyerId = kursiyerId;
	        this.kursiyerAdSoyad = kursiyerAdSoyad;
	        this.kursiyerYas = kursiyerYas;
	    }

	    // Kursiyer sınıfının getter metotları
	    public int getKursiyerId() {
	        return kursiyerId;
	    }
	    
	    
	    // Borç hesaplama metodu
	    public double BorcHesapla() {
	        int toplamKursSayisi = alinanKurslar.size();
	        double haftalikUcret = 500.0;
	        double toplamUcret = toplamKursSayisi * haftalikUcret*4;  //aylik oldugu icin 4le carpiyoruz..

	        if (toplamKursSayisi == 2) {
	            // Kampanya 1: 2 kurs alanlara %20 indirim
	            toplamUcret -= haftalikUcret * 0.20*4; // %20 indirim
	            System.out.println("Kampanya 1: 2 kurs alanlara %20 indirim");
	        } else if (toplamKursSayisi == 3) {
	            // Kampanya 2: 3 kurs alanlara 3. kurs %25 indirim
	           // toplamUcret += haftalikUcret; // 3. kurs normal ücret
	            toplamUcret -= haftalikUcret * 0.25*4; // %25 indirim
	            System.out.println("Kampanya 2: 3 kurs alanlara 3. kurs %25 indirim");
	        } else if (toplamKursSayisi > 3) {
	            // Kampanya 3: 3 kurs üstü alanlara her kurs için %10 indirim
	            toplamUcret -= toplamUcret * 0.10*4; // Her kurs için %10 indirim
	            System.out.println("Kampanya 3: 3 kurs üstü alanlara her kurs için %10 indirim");
	        } else {
	            // Tek kurs alanlara kampanya uygulanmıyor.
	            System.out.println("Tek kurs alanlara kampanya uygulanmıyor.");
	        }

	        return toplamUcret;
	    }
	    public String getKursiyerAdSoyad() {
	        return kursiyerAdSoyad;
	    }

	    public int getKursiyerYas() {
	        return kursiyerYas;
	    }

	    public ArrayList<Kurs> getAlinanKurslar() {
	        return alinanKurslar;
	    }

	    
	}