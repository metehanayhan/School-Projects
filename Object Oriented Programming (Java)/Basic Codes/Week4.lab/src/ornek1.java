/*İki sayının en büyüğünü ve üç sayının en büyüğünü bulan metotları 
overloading yapacak şekilde Java kodunu yazınız*/

import java.util.Scanner;

public class ornek1 {
		
	public static int enbuyukbul( int sayi1, int sayi2) {
		
		return sayi1>sayi2 ? sayi1: sayi2;
	}
	
	public static int enbuyukbul( int sayi3, int sayi1,int sayi2) {
		
		int enBuyuk = sayi1;
        if (sayi2 > enBuyuk) {
            enBuyuk = sayi2;
        }
        if (sayi3 > enBuyuk) {
            enBuyuk = sayi3;
        }
        return enBuyuk;
	}
	
	

 public static void main(String args[]) {
		
	 Scanner scanner = new Scanner(System.in);
		
		System.out.print("İlk sayıyı girin:");
		int sayi1 = scanner.nextInt();
		
		System.out.print("İkinci sayıyı girin:");
		int sayi2 = scanner.nextInt();
	
		
	  int enbuyuk = enbuyukbul(sayi1,sayi2);
	  
	  System.out.println("İkisi arasında en büyük sayı:"+enbuyuk);
		
	  System.out.print("Üçüncü sayıyı girin:");
		int sayi3 = scanner.nextInt();
		
		
		int enbuyuk2 = enbuyukbul(sayi3, sayi1, sayi2);
		System.out.println("Üçü arasında en büyük sayı:"+enbuyuk2);
		
		
	  scanner.close();
	}
	
}
