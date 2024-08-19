package paket;

import java.util.Scanner;

public class ornek2 {

	public static void main(String args[]) {
	
		Scanner bilgial = new Scanner(System.in);
	    System.out.println("İsminizi girin:");
	    String ad = bilgial.nextLine();
	    System.out.println("Soyisminizi girin:");
	    String soyad = bilgial.nextLine();
	    System.out.println("Yaşınızı girin:");
	    int yas = bilgial.nextInt();
	    System.out.println("Boyunuzu girin:");
	    int boy = bilgial.nextInt();
	    		
	  
		System.out.println("İsim:"+ad);
		System.out.println("Soyisim:"+soyad);
		System.out.println("Yaş:"+yas);
		System.out.println("Boy:"+boy);
		
		bilgial.close();
	}
}
