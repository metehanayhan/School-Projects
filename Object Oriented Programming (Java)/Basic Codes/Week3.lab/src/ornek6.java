/*Kullanıcıdan alınan cümle içerisinde yine kullanıcıdan 
alınan kelimeyi arayan Java kodunu yazınız*/

import java.util.Scanner;

public class ornek6 {

	public static void main(String args[]) {
		
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("Cümle giriniz:");
		String cumle = scanner.nextLine();
		
		System.out.print("Aranacak kelime:");
		String kelime = scanner.nextLine();
		int sayac=0;
		
		for(int i=0; i< cumle.length();i++) {
			
			if(cumle.charAt(i)==kelime.charAt(0)) {
				
				for(int j=1; j<kelime.length();j++) {
					if( cumle.charAt(i+1)==kelime.charAt(j)) {
						sayac++;
					}
					
				}
			}
			else {
				continue;
			}
			
		}
		System.out.println("Kelime cümle içinde "+sayac+" defa bulundu.");
		
		scanner.close();
	}
}
