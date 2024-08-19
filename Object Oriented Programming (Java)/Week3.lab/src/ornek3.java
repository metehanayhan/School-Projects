//Kullanıcıdan alınan bir sayıyı tersine çeviren Java kodunu yazınız

import java.util.Scanner;

public class ornek3 {

	public static void main(String args[]) {
		
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("Sayı girin:");
		int sayi = scanner.nextInt();
		int ters=0;
		
		while (sayi!=0) {
			int basamak = sayi % 10;
            ters = ters * 10 + basamak;
            sayi /= 10;
		}
		
		System.out.println("\nSayının tersi:"+ters);
		
		scanner.close();
	}
}
