package paket;

import java.util.Scanner;

public class ornek6 {

	
	public static void main(String args[]) {
		
		Scanner scanner= new Scanner(System.in);
		System.out.println("Üçgenin ilk kenranını gir:");
		int kenar = scanner.nextInt();
		
		System.out.println("Üçgenin ikinci kenranını gir:");
		int kenar2 = scanner.nextInt();
		
		System.out.println("Aradaki açıyı giriniz:");
		int aci = scanner.nextInt();
		
		double alan = 0.5*kenar*kenar2* Math.sin(aci);
		System.out.println("Üçgenin alanı:"+alan);
		
		scanner.close();
		
	}
	
}
