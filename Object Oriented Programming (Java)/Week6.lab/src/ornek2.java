//ANASAYFA

import java.util.Scanner;

public class ornek2 {

	public static void main(String[] args) {
		
	Scanner scanner= new Scanner(System.in);
	Ogrenci ogrenci = new Ogrenci("nancy", "ajram");
	
	
	System.out.print("Ad:");
	String ad= scanner.nextLine();
	
	System.out.print("Soyad:");
	String soyad= scanner.nextLine();
	
	System.out.print("Sınıf:");
	int sinif= scanner.nextInt();
	
	System.out.print("Vize notu:");
	int vizenot= scanner.nextInt();
	
	System.out.print("Final notu:");
	int finalnot= scanner.nextInt();
	
	LisansOgrencisi lisans = new LisansOgrencisi(ad, soyad, sinif, vizenot, finalnot);
	
	lisans.bilgileriyazdir(ogrenci, ad, soyad);
	lisans.gecmenotuhesapla(finalnot, vizenot, ad, ogrenci.getId());
	lisans.mezuniyetyilihesapla(sinif, ad, ogrenci.getId());
	
	ogrenci.bilgileriyazdir(ogrenci, ad, soyad);
	
	
	scanner.nextLine();
	System.out.print("Ad:");
	String ad2= scanner.nextLine();
	
	System.out.print("Soyad:");
	String soyad2= scanner.nextLine();
	
	System.out.print("Sınıf:");
	String asama= scanner.nextLine();
	
	
	System.out.print("Final notu:");
	int finalnot2= scanner.nextInt();
	
	YuksekLisansOgrencisi y_lisans = new YuksekLisansOgrencisi(ad2, soyad2, asama, finalnot2);
	
	y_lisans.bilgileriyazdir(ogrenci, ad2, soyad2);
	y_lisans.harfhesapla(finalnot2);
	
	
	scanner.close();
 
	}
}
