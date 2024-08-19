import java.util.Scanner;

public class ornek1 {

	
	public static void main(String args[]) {
		
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("Satır sayısını girin:");
		int satir = scanner.nextInt();
		System.out.println("Sütun sayısını girin:");
		int sutun = scanner.nextInt();
		int i,j,ortalama=0,toplam;
		
		int[][] dizi= new int[satir][sutun];
		
		for(i =0;i<satir;i++) {
			
			for(j=0;j<sutun;j++) {
				
				System.out.print("Sayı gir:");
				int sayi= scanner.nextInt();
				dizi[i][j]=sayi;
				
			}
			
		}
		for(i =0;i<satir;i++) {
			toplam=0;
			for(j=0;j<sutun;j++) {
				
				toplam= toplam + dizi[i][j];
				ortalama=toplam/sutun;
				
			}
			System.out.println("Satır "+(i+1)+" ortalaması "+ortalama);
			
		}
		
		
		scanner.close();
	}
}
