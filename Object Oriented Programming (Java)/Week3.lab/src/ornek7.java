//Kullanıcıdan alınan cümle içerisindeki kelime sayısını bulan Java kodunu yazınız


import java.util.Scanner;

public class ornek7 {

	public static void main(String args[]) {
		
		Scanner scanner = new Scanner(System.in);
		System.out.print("Cümle giriniz:");
		String cumle = scanner.nextLine();
		int sayac=0;
		
		for(int i=0; i<cumle.length();i++) {
			
			if(cumle.charAt(i)==' ') {
				sayac++;
			}
			
		}
		System.out.println("Cümle içinde "+(sayac+1)+" tane kelime bulundu.");
		scanner.close();
	}
}
	
