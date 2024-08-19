
/*Kullanıcıdan alınan üç sayıyı küçükten büyüğe doğru sıralı 
bir şekilde ekrana yazdırınız*/

package paket;

import java.util.Scanner;

public class ornek9 {

	public static void main(String args[]) {
		
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("İlk sayıyı girin:");
		int sayi1 = scanner.nextInt();
		
		System.out.println("İkinci sayıyı girin:");
		int sayi2 = scanner.nextInt();
	
		System.out.println("Üçüncü sayıyı girin:");
		int sayi3 = scanner.nextInt();
		
		
		if (sayi1 <= sayi2 && sayi2 <= sayi3) {
            System.out.println("Sıralama: " + sayi1 + " <= " + sayi2 + " <= " + sayi3);
        } else if (sayi1 <= sayi3 && sayi3 <= sayi2) {
            System.out.println("Sıralama: " + sayi1 + " <= " + sayi3 + " <= " + sayi2);
        } else if (sayi2 <= sayi1 && sayi1 <= sayi3) {
            System.out.println("Sıralama: " + sayi2 + " <= " + sayi1 + " <= " + sayi3);
        } else if (sayi2 <= sayi3 && sayi3 <= sayi1) {
            System.out.println("Sıralama: " + sayi2 + " <= " + sayi3 + " <= " + sayi1);
        } else if (sayi3 <= sayi1 && sayi1 <= sayi2) {
            System.out.println("Sıralama: " + sayi3 + " <= " + sayi1 + " <= " + sayi2);
        } else {
            System.out.println("Sıralama: " + sayi3 + " <= " + sayi2 + " <= " + sayi1);
        }

        scanner.close();
		
		}
			
		
	}

