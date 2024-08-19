//METEHAN AYHAN
//22100011024

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class AnaSayfa {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Kaç tane bölüm olacak: ");  //once bolum sayisini aliyoruz.
        int bolumsayisi = scanner.nextInt();
        Bolum[] bolumler = new Bolum[bolumsayisi];//bolumler dizisi olusturduk

        for (int i = 0; i < bolumsayisi; i++) {          //sonra bolum bilgilerini aliyoruz
            System.out.print("Bölüm numarası girin: ");
            int bolNO = scanner.nextInt();
            scanner.nextLine(); 

            System.out.print("Bölüm adı girin: ");
            String bolAD = scanner.nextLine();

            bolumler[i] = new Bolum(bolNO, bolAD);    //bolumlerim ilk elemanina girilen bilgiler constructor metod ile atandi 

            System.out.print("Kaç tane lisans öğrencisi olacak: ");
            int lisansSayisi = scanner.nextInt();
            scanner.nextLine(); //bunlari koymamin sebebi iki stringi arka arkaya alirken sorun olmasi

            System.out.print("Kaç tane Yüksek lisans öğrencisi olacak: ");
            int YlisansSayisi = scanner.nextInt();
            scanner.nextLine(); 
            
            bolumler[i].ogrenciler = new Ogrenci[lisansSayisi + YlisansSayisi];  //ogrenci sinifindan ogrenciler dizisi olusturuldu

            for (int j = 0; j < lisansSayisi; j++) {
                System.out.print("\nLisans Öğrencisi Adı: ");
                String ad = scanner.nextLine();
                System.out.print("Lisans Öğrencisi Soyadı: ");
                String soyad = scanner.nextLine();
                System.out.print("Lisans Öğrencisi Sınıfı: ");
                int sinif = scanner.nextInt();
                scanner.nextLine(); 
                bolumler[i].ogrenciler[j] = new LisansOgrencisi(bolNO, ad, soyad, sinif); //yukaricevrim.. ogrencilere ise adedince lisans bilgileri atiliyor..
            }


            for (int k = lisansSayisi; k < lisansSayisi + YlisansSayisi; k++) { //dizinin devamina yuksek lisans atiliyor..
                System.out.print("\nYüksek Lisans Öğrencisi Ad: ");
                String ad = scanner.nextLine();
                System.out.print("Yüksek Lisans Öğrencisi Soyad: ");
                String soyad = scanner.nextLine();
                bolumler[i].ogrenciler[k] = new YLOgrencisi(bolNO, ad, soyad);  // yukaricevrim.. yine ogrenciler dizisine kullanicidan alinan bilgiler yapici metodla atandi..
            }

            System.out.print("\nKaç tane ders var? ");
            int dersSayisi = scanner.nextInt();

            bolumler[i].dersler = new Ders[dersSayisi];

            for (int m = 0; m < dersSayisi; m++) {
                System.out.print("Ders Ad: ");
                String dersAd = scanner.next();
                System.out.print("Ders Kredi: ");
                int dersKredi = scanner.nextInt();
                bolumler[i].dersler[m] = new Ders(bolNO, dersAd, dersKredi);
            }
        }

        int tus;   //kullanici 6ya basana kadar menu gosteriliyor..
        do {
            System.out.println("\nMenü:");
            System.out.println("1- Tüm bölümlerin bilgilerini listele");
            System.out.println("2- Lisans ögrencilerini listele");
            System.out.println("3- Yüksek lisans ögrencilerini listele");
            System.out.println("4- Dersleri listele");
            System.out.println("5- Arama yap");
            System.out.println("6- Çıkış");

            System.out.println("Seçim: ");
            tus = scanner.nextInt();

            switch (tus) {
                case 1:
                    tumBilgiListele(bolumler);
                    break;
                case 2:
                    lisansOgrencileriniListele(bolumler);
                    break;
                case 3:
                    ylOgrencileriniListele(bolumler);
                    break;
                case 4:
                    dersleriListele(bolumler);
                    break;
                case 5:
                    aramaYap(bolumler);
                    break;
                case 6:
                    System.out.println("Çıkış yapıldı..");
                    break;
                default:
                    System.out.println("Geçersiz bir seçim!! tekrar deneyin..");
            }
        } while (tus != 6);

        scanner.close();
    }

//tum bilgileri listeleme fonksiyonu
    public static void tumBilgiListele(Bolum[] bolumler) {
        for (Bolum bolum : bolumler) {
            System.out.println("Bölüm No: " + bolum.getBolNo() + " Bölüm Ad: " + bolum.getBolAd());

            int i=1;
            System.out.println("\nLisans Öğrencileri:");
            for (Ogrenci ogrenci : bolum.getOgrenciler()) {
                if (ogrenci instanceof LisansOgrencisi) {//instanceof ile ogrenci nesnesi lisans sinifina ait mi deil mi diye kontrol ediliyor..
                    LisansOgrencisi lisansOgrencisi = (LisansOgrencisi) ogrenci;
                    System.out.println(i+". Öğrenci: " + lisansOgrencisi.getOgrID() + " " +
                            lisansOgrencisi.getOgrAd() + " " +
                            lisansOgrencisi.getOgrSoyad() + " " +
                            lisansOgrencisi.getOgrSinif());
                    i++;
                }
            }
            
            int j=1;
            System.out.println("\nYüksek Lisans Öğrencileri:");
            for (Ogrenci ogrenci : bolum.getOgrenciler()) {
                if (ogrenci instanceof YLOgrencisi) {   //yine ayni islem
                    YLOgrencisi ylOgrencisi = (YLOgrencisi) ogrenci;
                    System.out.println(j+". Öğrenci: " + ylOgrencisi.getOgrId() + " " +
                            ylOgrencisi.getOgrAd() + " " +
                            ylOgrencisi.getOgrSoyad());
                    j++;
                }
            }

            int k=1;
            System.out.println("Dersler:");
            for (Ders ders : bolum.getDersler()) {
                System.out.println(k+". Ders: " + ders.getDersID() + " " +
                        ders.getDersAd() + " " +
                        ders.getDersKredi());
                k++;
            }

            System.out.println();
        }
    }

    public static void lisansOgrencileriniListele(Bolum[] bolumler) { //tumu listelenecegi icin bolumler dizisini parametre olarak gonderdik
        System.out.println("Tüm Bölümlerdeki Lisans Öğrencileri:");
        for (Bolum bolum : bolumler) {  //sirayla tum bolumleri ve onun icindeki ogrencileri geziyor
            for (Ogrenci ogrenci : bolum.getOgrenciler()) {
                if (ogrenci instanceof LisansOgrencisi) {
                    LisansOgrencisi lisansOgrencisi = (LisansOgrencisi) ogrenci;
                    System.out.println(lisansOgrencisi.getOgrSinif() + ". Sınıf Öğrencileri:");
                    System.out.println(lisansOgrencisi.getOgrID() + " " +
                            lisansOgrencisi.getOgrAd() + " " +
                            lisansOgrencisi.getOgrSoyad());
                }
            }
        }
    }

    public static void ylOgrencileriniListele(Bolum[] bolumler) {
        System.out.println("Tüm Bölümlerdeki Yüksek Lisans Öğrencileri:");
        for (Bolum bolum : bolumler) {
            for (Ogrenci ogrenci : bolum.getOgrenciler()) {
                if (ogrenci instanceof YLOgrencisi) {
                    YLOgrencisi ylOgrencisi = (YLOgrencisi) ogrenci;
                    System.out.println(ylOgrencisi.getOgrId() + " " +
                            ylOgrencisi.getOgrAd() + " " +
                            ylOgrencisi.getOgrSoyad());
                }
            }
        }
    }

    public static void dersleriListele(Bolum[] bolumler) {
        
        Ders[] tumdersler = new Ders[0];// tum bölümlerin derslerini tek bir diziye topluyoruz

        for (Bolum bolum : bolumler) {
            int eskiuzunluk = tumdersler.length;
            int bolumDersSayisi = bolum.getDersler().length;
            tumdersler = Arrays.copyOf(tumdersler, eskiuzunluk + bolumDersSayisi);
            System.arraycopy(bolum.getDersler(), 0, tumdersler, eskiuzunluk, bolumDersSayisi);
        }

        // Dersleri krediye göre sıralıyoruz
        Arrays.sort(tumdersler, Comparator.comparingInt(Ders::getDersKredi));

        // Tüm dersleri listeleyerek ekrana yazdırıyoruz
        int k = 1;
        System.out.println("Tüm Bölümlerdeki Dersler (En az krediden en çok krediye sıralı):");
        for (Ders ders : tumdersler) {
            System.out.println(k + ". ders: " + ders.getDersID() + " " +
                    ders.getDersAd() +" "+
                    ders.getDersKredi());
            k++;
        }
    }

//arama yapma metodu
    public static void aramaYap(Bolum[] bolumler) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Aranacak kelimeyi girin: ");  //kullanicidan aranacak kelimeyi aliyoruz..
        String aranacakKelime = scanner.nextLine();

        boolean ogrenciBulundu = false;
        boolean dersBulundu = false;

        for (Bolum bolum : bolumler) { //tum bolumlerin icinde ogrenciler ve dersler aranacak.. for icinde 2 for..
            for (Ogrenci ogrenci : bolum.getOgrenciler()) {
                if (ogrenci != null && (ogrenci.getOgrAd().contains(aranacakKelime) || ogrenci.getOgrSoyad().contains(aranacakKelime))) {
                //constains metodu ile arama islemi yaptım..
                    ogrenciBulundu = true;

                    if (ogrenci instanceof LisansOgrencisi) {   //lisansta bulunuyor ise normal listeleme islemi yapiyoruz..
                        LisansOgrencisi lisansOgrencisi = (LisansOgrencisi) ogrenci;
                        System.out.println("Öğrenci bulundu: " + lisansOgrencisi.getOgrID() + " " +
                                lisansOgrencisi.getOgrAd() + " " +
                                lisansOgrencisi.getOgrSoyad() + " " +
                                lisansOgrencisi.getOgrSinif() +
                                " - Bölüm: " + bolum.getBolAd());
                    } else if (ogrenci instanceof YLOgrencisi) { // değilse ve yüksek lisansta bulunuyor ise onun bilgilerini listeliyoruz
                        YLOgrencisi ylOgrencisi = (YLOgrencisi) ogrenci;
                        System.out.println("Öğrenci bulundu: " + ylOgrencisi.getOgrId() + " " +
                                ylOgrencisi.getOgrAd() + " " +
                                ylOgrencisi.getOgrSoyad() +
                                " - Bölüm: " + bolum.getBolAd());
                    }
                }
            }

            for (Ders ders : bolum.getDersler()) {   //ayrı bir for içinde derslerde de o kelimeyi arıyoruz
                if (ders.getDersAd().contains(aranacakKelime)) {
                    dersBulundu = true; //bulundu ise true dönecekk ve bilgileri yazdirilcak
                    System.out.println("Ders bulundu: " + ders.getDersID() + " " +
                            ders.getDersAd() + " " +
                            ders.getDersKredi() +
                            " - Bölüm: " + bolum.getBolAd());
                }
            }
        }

        if (!ogrenciBulundu) {   //true dönmediyse bulunamadı mesaji veriyoruz
            System.out.println("Bu isimde öğrenci bulunamadı.");
        }

        if (!dersBulundu) {
            System.out.println("Bu isimde ders bulunamadı.");
        }
       
    }
    



}
