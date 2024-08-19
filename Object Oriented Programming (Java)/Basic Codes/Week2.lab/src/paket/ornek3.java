package paket;

import java.util.Scanner;

public class ornek3 {

	
	public static void main(String args[]) {
		
		Scanner scanner = new Scanner(System.in);
		System.out.println("Sıcaklık değerini(celcius) giriniz:");
		int sicaklik = scanner.nextInt();
		
		double fahrenheit = sicaklik * 1.8 +32 ; 
		System.out.println("Sıcaklık fahrenheit değerinden:"+fahrenheit);
		
		scanner.close();
	}
}
