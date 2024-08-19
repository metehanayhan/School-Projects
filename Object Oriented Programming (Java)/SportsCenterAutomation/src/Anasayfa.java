//METEHAN AYHAN
//22100011024

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;



public class Anasayfa {
    private static ArrayList<Kursiyer> Kursiyerler = new ArrayList<>(); //arraylistler
    private static ArrayList<Kurs> Kurslar = new ArrayList<>();

    public static void main(String[] args) {
    	dosyadanKurslariOku("kurs.txt"); //dosyadan okuma fonk. cagriliyor.
        dosyadanKursiyerleriOku("kursiyer.txt");
    

        while (true) {
            System.out.println("1 – Kurs Ekle\n2 – Kurs Listele\n3 – Kurs Ara\n4 – Kurs Sil\n" +
                    "5 – Kursiyer Ekle\n6 – Kursiyer Ara\n7 – Kursiyer Sil\n8 – Kursiyerleri Listele\n" +
                    "9 – Kursiyerleri Ayrıntılı Listele\n10 – Kursiyerin Ödeyeceği Tutarı Hesapla\n11 – Çıkış\nSeçim:");

            Scanner scanner = new Scanner(System.in);
            int secim = scanner.nextInt();

            switch (secim) {
                case 1:
                    KursEkle();
                    break;
                case 2:
                    kursListele();
                    break;
                case 3:
                    KursAra();
                    break;
                case 4:
                    KursSil();
                    break;
                case 5:
                    KursiyerEkle();
                    break;
                case 6:
                    KursiyerAra();
                    break;
                case 7:
                    KursiyerSil();
                    break;
                case 8:
                    KursiyerListele();
                    break;
                case 9:
                    KursiyerAyrintiliListele();
                    break;
                case 10:
                    KursiyerinOdeyecegiTutarHesapla();
                    break;
                case 11:
                    Cikis();
                    break;
                default:
                    System.out.println("Geçersiz seçim. Tekrar deneyin.");
            }
        }
    }

    
  //kursun kayitli kursu olup olmadigini kontrol ediyoruzvconstains ile
    private static boolean kursunKayitliKursiyeriVarMi(Kurs kurs) {
        for (Kursiyer kursiyer : Kursiyerler) {
            if (kursiyer.getAlinanKurslar().contains(kurs)) {
                return true;
            }
        }
        return false;
    }

    
    
    //kurs dosyasi okuma fonk
    private static void dosyadanKurslariOku(String dosyaAdi) {
    	try (Scanner scanner = new Scanner(new FileReader("kurs.txt"))) { // Burada dosya adını "kurs.txt" olarak değiştirdim
            while (scanner.hasNextLine()) {
                String lineString = scanner.nextLine();
                String[] kursVeri = lineString.split("\\+");
                int kursId = Integer.parseInt(kursVeri[0].trim());
                Kurs kurs = new Kurs(kursId, kursVeri[1].trim());
                Kurslar.add(kurs);
            }
        } catch (FileNotFoundException e) {
            System.out.println("Dosya bulunamadı. Yeni bir dosya oluşturuluyor.");
        }
    }

    //kursiyer okuma fonk..
    private static void dosyadanKursiyerleriOku(String dosyaAdi) {
        try (BufferedReader br = new BufferedReader(new FileReader(dosyaAdi))) {
            String line;
            Kursiyer skursiyer = null;

            while ((line = br.readLine()) != null) {
                String[] kelime = line.split("\\+"); //yine +lara gore ayiriyoruz

                if (line.startsWith("*")) {  //* ile basliyorsa kursiyerdir
                    // Yeni kursiyer
                    skursiyer = new Kursiyer(Integer.parseInt(kelime[0].substring(1)), kelime[1], Integer.parseInt(kelime[2]));
                    Kursiyerler.add(skursiyer);
                    
                } else if (line.startsWith("%")) {
                    if (skursiyer != null) {
                        String[] kursVeri = line.substring(1).split("\\+"); // Ayracı düzelt
                        int kursId = Integer.parseInt(kursVeri[0].trim());
                        Kurs kurs = new Kurs(kursId, kursVeri[1].trim());
                        skursiyer.alinanKurslar.add(kurs);
                    }}
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    //ayni kurs daha onceden var mi yok mu kontrol etme
    private static Kurs kursvarmi(int id) {
        for (Kurs kurs : Kurslar) {
            if (kurs.kursId == id) {
                return kurs;
            }
        }
        return null;
    }


    //kurs ekleme fonksiyonu
    private static void KursEkle() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Kurs ID: ");
        int kursId = scanner.nextInt();

        //id'nin aynısından olup olmadığını kontrol ediyoruz
        if (kursvarmi(kursId) != null) {
            System.out.println("Bu id'ye sahip bir kurs zaten var. Başka bir id seçin.");
            return;
        }

        System.out.print("Kurs Adı: ");
        String kursAd = scanner.next();

        Kurs yeniKurs = new Kurs(kursId, kursAd);
        Kurslar.add(yeniKurs);

        System.out.println("Kurs başarıyla eklendi.");
    }


    private static void kursListele() {
        if (Kurslar.isEmpty()) {
            System.out.println("Kayıtlı kurs bulunmamakta.");
        } else {
            System.out.println("Kurs Id\t\tKurs Adı");
            System.out.println("----------------------");

            for (Kurs kurs : Kurslar) {
                System.out.println(kurs.getKursId() + "\t\t" + kurs.getKursAd());
            }
        }
    }


   
    

    //kursiyer ekleme fonksiyonu
    private static void KursiyerEkle() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Kursiyer ID: ");
        int kursiyerId = scanner.nextInt();

        // ID'nin aynisi olup olmadığını kontrol ediyoruz
        if (kursiyervarmi(kursiyerId) != null) {
            System.out.println("Bu ID'ye sahip bir kursiyer zaten mevcut. Başka bir ID seçin.");
            return;
        }
        
        //kursiyere kurs ekleme islemi
        scanner.nextLine();
        System.out.print("Kursiyer Ad Soyad: ");
        String kursiyerAdSoyad = scanner.nextLine();
        scanner.nextLine();
        System.out.print("Kursiyer Yaş: ");
        int kursiyerYas = scanner.nextInt();
        String kadString;  //kurs ad
    	int kid=0;    //kurs id
    	Kurs kurs9=null;
        Kursiyer yeniKursiyer = new Kursiyer(kursiyerId, kursiyerAdSoyad, kursiyerYas);
        int x=0;
        while(true) {
        	int kon=0;
        	
            
            System.out.println("Kurs id:");
            kid = scanner.nextInt();
            scanner.nextLine();
            System.out.println("Kurs ad:");
            kadString = scanner.nextLine();
            
            for (Kurs kurs1 : Kurslar) {
                if (kurs1.kursId == kid) {
                	kurs9=new Kurs(kid, kadString);
                     x=1;
                     break;
                }
            }
            if(x==0) {
            	
            	System.out.println("böyle bir kurs yok..\niste kurslarimiz:\n");
            	kursListele();
            }
            System.out.println("Kurs eklemek için 1'e basın. cikmak icin bir sayi tuslayin.");
        	kon=scanner.nextInt();
        	scanner.nextLine();
        	if(kon!=1) {
        		yeniKursiyer.alinanKurslar.add(kurs9);
        		break;
        		
        	}
        	
        }
        
        Kursiyerler.add(yeniKursiyer);
        
        System.out.println("Kursiyer başarıyla eklendi.");
    }
    
    private static Kursiyer kursiyervarmi(int id) {
        for (Kursiyer kursiyer : Kursiyerler) {
            if (kursiyer.getKursiyerId() == id) {
                return kursiyer;
            }
        }
        return null;
    }

    //kursiyer arama fonksiyonu
    private static void KursiyerAra() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Aranacak Kursiyer Ad Soyad: ");
        String arananKursiyerAdSoyad = scanner.next();

        boolean aranan = false;

        for (Kursiyer kursiyer : Kursiyerler) {
            if (kursiyer.getKursiyerAdSoyad().equalsIgnoreCase(arananKursiyerAdSoyad)) {
            	aranan = true;
                System.out.println("Kursiyer Bulundu:");
                System.out.println("Kursiyer ID: " + kursiyer.getKursiyerId());
                System.out.println("Kursiyer Ad Soyad: " + kursiyer.getKursiyerAdSoyad());
                System.out.println("Kursiyer Yaş: " + kursiyer.getKursiyerYas());
                break;
            }
        }

        if (!aranan) {
            System.out.println("Kursiyer bulunamadı.");
        }
    }

    private static void KursiyerSil() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Silinecek Kursiyer ID: ");
        int silinecekKursiyerId = scanner.nextInt();

        boolean kursiyerVarMi = false;

        for (Kursiyer kursiyer : Kursiyerler) {
            if (kursiyer.getKursiyerId() == silinecekKursiyerId) {
                kursiyerVarMi = true;
                Kursiyerler.remove(kursiyer);
                System.out.println("Kursiyer başarıyla silindi.");
                break;
            }
        }

        if (!kursiyerVarMi) {
            System.out.println("Silinecek kursiyer bulunamadı.");
        }
    }

    //kurs silme fonksiyonu
    private static void KursSil() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Silinecek Kurs Adı: ");
        String silinecekKursAd = scanner.next();

        boolean kursVarMi = false;

        for (Kurs kurs : Kurslar) {
            if (kurs.getKursAd().equalsIgnoreCase(silinecekKursAd)) {
                kursVarMi = true;

                // Kursu silebilir mi kontrolü
                if (kursunKayitliKursiyeriVarMi(kurs)) {
                    System.out.println("Bu kursa kayıtlı kursiyer olduğu için silme işlemi yapılamaz.");
                } else {
                    Kurslar.remove(kurs);
                    System.out.println("Kurs başarıyla silindi.");
                }

                break;
            }
        }

        if (!kursVarMi) {
            System.out.println("Silinecek kurs bulunamadı.");
        }
    }
    //LISTELEME FONKSİYONLARİ
    private static void KursiyerListele() {
        System.out.println("Tüm Kursiyerler");
        System.out.println("Kursiyer ID\tKursiyer Ad Soyad\tKursiyer Yaş");
        System.out.println("----------------------------------------------------");

        for (Kursiyer kursiyer : Kursiyerler) {
            System.out.println(kursiyer.getKursiyerId() + "\t\t" + kursiyer.getKursiyerAdSoyad() + "\t\t\t" + kursiyer.getKursiyerYas());
        }
    }

    private static void KursiyerAyrintiliListele() {
        System.out.println("Tüm Kursiyerler ve Aldıkları Kurslar");
        for (Kursiyer kursiyer : Kursiyerler) {
            System.out.println(kursiyer.getKursiyerId() + " "
                    + kursiyer.getKursiyerAdSoyad() + " "
                    + kursiyer.getKursiyerYas());
            for (Kurs kurs : kursiyer.getAlinanKurslar()) {
                if (kurs != null) { // Null kontrolü ekleyelim
                    System.out.println("   "
                            + kurs.getKursId() + " "
                            + kurs.getKursAd());
                }
            }
        }
    }

    
    private static void KursiyerinOdeyecegiTutarHesapla() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Ödeme yapacak Kursiyer ID: ");
        int odemeYapacakKursiyerId = scanner.nextInt();

        Kursiyer odemeYapacakKursiyer = null;
        for (Kursiyer kursiyer : Kursiyerler) {
            if (kursiyer.getKursiyerId() == odemeYapacakKursiyerId) {
                odemeYapacakKursiyer = kursiyer;
                break;
            }
        }

        if (odemeYapacakKursiyer != null) {
            double toplamUcret = odemeYapacakKursiyer.BorcHesapla();
            System.out.println("Ödeme yapacak Kursiyer ID: " + odemeYapacakKursiyerId);
            System.out.println("Toplam Ödeme Tutarı: " + toplamUcret);
        } else {
            System.out.println("Kursiyer bulunamadı.");
        }
    }
    
    //kurs arama fonksiyonu
    private static void KursAra() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Aranacak Kurs Adı: ");
        String arananKursAd = scanner.next();

        int bulundu = 1999;

        for (Kurs kurs : Kurslar) {
            if (kurs.getKursAd().equalsIgnoreCase(arananKursAd)) { //equals ile buyuk kucuk harf ayrimi
                bulundu = 2000;
                System.out.println("Kurs Bulundu:");
                System.out.println("Kurs ID: " + kurs.getKursId());
                System.out.println("Kurs Adı: " + kurs.getKursAd());
                break;
            }
        }

        if (bulundu!=2000) {
            System.out.println("Kurs bulunamadı.");
        }
    }


    private static void Cikis() {
        // Kursiyer bilgilerini dosyaya yazdiriyoruz
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("kursiyer.txt"))) {
            for (Kursiyer kursiyer : Kursiyerler) {
            	//kursiyerleri basinda * olacak sekilde +ile ayirarak yaziyoruz
                writer.write("*" + kursiyer.getKursiyerId() + "+" + kursiyer.getKursiyerAdSoyad() + "+" + kursiyer.getKursiyerYas());
                writer.newLine();

                for (Kurs kurs : kursiyer.getAlinanKurslar()) {
                    writer.write("%"+kurs.getKursId()+"+"+kurs.getKursAd());
                    writer.newLine();
                }
            }
        } catch (IOException e) {
            System.out.println("Dosya yazmada hata!!: kursiyer.txt");
        }

        // Kurs bilgilerini dosyaya yaz
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("kurs.txt"))) {
            for (Kurs kurs : Kurslar) {
                writer.write(kurs.getKursId() + "+" + kurs.getKursAd());
                writer.newLine();
            }
        } catch (IOException e) {
            System.out.println("Dosya yazmada hata: kurs.txt");
        }

        System.out.println("Dosyaya yazma işlemi tamamlandı. Program sonlandırılıyor...");
        System.exit(0);
    }
}

