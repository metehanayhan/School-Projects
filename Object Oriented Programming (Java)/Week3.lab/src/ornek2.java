/*Kullanıcıdan alınan bir sayının basamakları toplamını ve basamak 
sayısını ekrana yazdıran Java kodunu yazınız*/

import java.util.Scanner;

public class ornek2 {

	public static void main(String args[]) {
		
		Scanner scanner = new Scanner(System.in);
		System.out.print("Sayı girin:");
		int sayi = scanner.nextInt();
		
		int basamaktoplamı=0;
		int basamaksayisi=0;
		
		while(sayi!=0) {
			basamaktoplamı+=sayi%10;
			basamaksayisi++;
			sayi/=10;
		}
		System.out.println("\nBasamak sayısı:"+basamaksayisi+"\nBasamak toplamı:"+basamaktoplamı);
		
		scanner.close();
  }
}
