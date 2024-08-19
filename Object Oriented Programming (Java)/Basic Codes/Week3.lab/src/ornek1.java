/*Kullanıcıdan alınan bir sayının pozitif bölenlerini ekrana
yazdıran Java kodunu yazınız */


import java.util.Scanner;

public class ornek1 {

	public static void main(String args[]) {
		
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("Sayı girin:");
		int sayi = scanner.nextInt();
		int sayac=0;
		
		for(int i=2; i<sayi/2; i++) {
		
			if(sayi%i==0) {
				sayac++;
				System.out.println("Pozitif böleni:"+i);
			}
			
		}
		if(sayac==0) {
			System.out.println("Pozitif böleni yok.");
		}
		
		
		scanner.close();
	}
}
