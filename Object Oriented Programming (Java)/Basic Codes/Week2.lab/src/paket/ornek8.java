
/*Kullanıcıdan alınan iki sayının toplam, fark, bölüm, çarpım, üs ve mod 
değerlerini hesaplayıp ekrana yazdırınız. İlk sayının ikinci sayıdan 
büyük olma kontrolünü yapınız*/


package paket;

import java.util.Scanner;

public class ornek8 {

	public static void main(String args[]) {
		
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("İlk sayıyı girin:");
		int sayi1 = scanner.nextInt();
		
		System.out.println("İkinci sayıyı girin:");
		int sayi2 = scanner.nextInt();
		
		int toplam= sayi1+ sayi2;
		int fark= sayi1- sayi2;
		double bolum= sayi1/ sayi2;
		int carpim = sayi1* sayi2;
		int us= (int) Math.pow(sayi1,sayi2);
	    double mod= sayi1%sayi2;
	    
	    if(sayi1>sayi2) {
	    	System.out.println("ilk sayı daha büyük.");
	    }
	    else {
			System.out.println("ikinci sayı daha büyük.");
		}
	    
	    if(fark<0) {
	    	
	    	int temp= (fark*2)*(-1);
	    	fark=fark+temp;
	    	
	    }
	    System.out.println("Toplam:"+toplam);
	    System.out.println("Fark:"+fark);
	    System.out.println("Bölüm:"+bolum);
	    System.out.println("Çarpım:"+carpim);
	    System.out.println("Üs:"+us);
	    System.out.println("Mod:"+mod);
	
	    scanner.close();
	}
	
}
