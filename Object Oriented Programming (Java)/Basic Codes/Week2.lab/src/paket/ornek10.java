package paket;

import java.util.Scanner;

public class ornek10 {

	public static void main(String args[]) {
		
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("İlk sayıyı girin:");
		int sayi1 = scanner.nextInt();
		
		System.out.println("İkinci sayıyı girin:");
		int sayi2 = scanner.nextInt();
	
		System.out.println("Üçüncü sayıyı girin:");
		int sayi3 = scanner.nextInt();
		
		
		int enkucuk;
		int enbuyuk;
		int ortanca;
		
		if(sayi1<sayi2) {
			
			if(sayi1<sayi3) {
				
				enkucuk= sayi1;
			}
			else {
					enkucuk=sayi3;
				}
			if (sayi3>sayi2) {
				enbuyuk=sayi3;
				ortanca=sayi2;
			}
			else {
				enbuyuk=sayi2;
				ortanca=sayi3;
			}
		}
		else {
			if(sayi3<sayi2) {
				enkucuk=sayi3;
			}
			else {
				enkucuk=sayi2;
			}
			
			if(sayi3>sayi1) {
				
				enbuyuk=sayi3;
				ortanca=sayi2;
			}
			else {
				enbuyuk=sayi1;
				ortanca=sayi2;
			}
		}
		
		System.out.println("\nEn büyük:" + enbuyuk + "\nOrtanca:" + ortanca + "\nEn küçük:"+ enkucuk);;
		System.out.println("Ortalama:"+(sayi1+sayi2+sayi3)/3);
		
		scanner.close();
	}
		
}