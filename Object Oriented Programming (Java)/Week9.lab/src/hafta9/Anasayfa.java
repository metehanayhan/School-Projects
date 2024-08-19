package hafta9;

import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

class Anasayfa {
    private ArrayList<Ogrenci> ogrenciListesi = new ArrayList<>();
    private Scanner scanner = new Scanner(System.in);
    private String dosyaAdi = "ogrenciler.txt";

   
    public Anasayfa() {
        dosyadanOku();
    }

    public void anaMenu() {
        int secim;
        do {
            System.out.println("\nÖğrenci Otomasyonu:");
            System.out.println("1. Ekleme");
            System.out.println("2. Listeleme");
            System.out.println("3. Arama");
            System.out.println("4. Silme");
            System.out.println("5. Çıkış");
            System.out.print("Seçim: ");
            secim = scanner.nextInt();

            switch (secim) {
                case 1:
                    ogrenciEkle();
                    break;
                case 2:
                    ogrenciListele();
                    break;
                case 3:
                    ogrenciAra();
                    break;
                case 4:
                    ogrenciSil();
                    break;
                case 5:
                    System.out.println("Programdan çıkılıyor...");
                    dosyayaYaz(); 
                    break;
                default:
                    System.out.println("Geçersiz bir seçim yaptınız. Tekrar deneyiniz.");
            }
        } while (secim != 5);
    }

    private void ogrenciEkle() {
        System.out.print("Adı: ");
        String ad = scanner.next();
        System.out.print("Soyadı: ");
        String soyad = scanner.next();
        System.out.print("Vize Notu: ");
        int vizeNot = scanner.nextInt();
        System.out.print("Final Notu: ");
        int finalNot = scanner.nextInt();

        Ogrenci yeniOgrenci = new Ogrenci(ad, soyad, vizeNot, finalNot);
        ogrenciListesi.add(yeniOgrenci);
        System.out.println("Öğrenci eklendi. No: " + yeniOgrenci.getNo());
    }

    private void ogrenciListele() {
        System.out.println("\n***** Öğrenci Listesi *****");
        System.out.printf("%-5s%-15s%-15s%-10s%-10s%-10s\n",
                "No", "Ad", "Soyad", "Vize", "Final", "Geçme");
        for (Ogrenci ogrenci : ogrenciListesi) {
            System.out.println(ogrenci);
        }
    }

    private void ogrenciAra() {
        System.out.print("Aranacak öğrenci no giriniz: ");
        int arananNo = scanner.nextInt();
        boolean bulundu = false;

        for (Ogrenci ogrenci : ogrenciListesi) {
            if (ogrenci.getNo() == arananNo) {
                System.out.println("\n***** Aranan Öğrenci *****");
                System.out.printf("%-5s%-15s%-15s%-10s%-10s%-10s\n",
                        "No", "Ad", "Soyad", "Vize", "Final", "Geçme");
                System.out.println(ogrenci);
                bulundu = true;
                break;
            }
        }

        if (!bulundu) {
            System.out.println("Belirtilen no'ya sahip öğrenci bulunamadı.");
        }
    }

    private void ogrenciSil() {
        System.out.print("Silinecek öğrenci no giriniz: ");
        int silinecekNo = scanner.nextInt();
        boolean silindi = false;

        for (Ogrenci ogrenci : ogrenciListesi) {
            if (ogrenci.getNo() == silinecekNo) {
                ogrenciListesi.remove(ogrenci);
                System.out.println("Öğrenci silindi. No: " + silinecekNo);
                silindi = true;
                break;
            }
        }

        if (!silindi) {
            System.out.println("Belirtilen no'ya sahip öğrenci bulunamadı.");
        }
    }

    private void dosyayaYaz() {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(dosyaAdi))) {
            oos.writeObject(ogrenciListesi);
            System.out.println("Veriler dosyaya yazıldı: " + dosyaAdi);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void dosyadanOku() {
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(dosyaAdi))) {
            ogrenciListesi = (ArrayList<Ogrenci>) ois.readObject();
            System.out.println("Veriler dosyadan okundu: " + dosyaAdi);
        } catch (IOException | ClassNotFoundException e) {
            
            System.out.println("Dosya bulunamadı veya okuma hatası. Yeni bir dosya oluşturuluyor: " + dosyaAdi);
        }
    }
    public static void main(String[] args) {
        Anasayfa anasayfa = new Anasayfa();
        anasayfa.anaMenu();
    
}


}


  

