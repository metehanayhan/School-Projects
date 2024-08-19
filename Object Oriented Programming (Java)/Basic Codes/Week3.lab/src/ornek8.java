//Kullanıcıdan alınan cümle içerisindeki sesli harfleri sayan Java kodunu yazınız

import java.util.Scanner;

public class ornek8 {

	public static void main(String args[]) {
		
		Scanner scanner = new Scanner(System.in);
		System.out.print("Cümle giriniz:");
		String cumle = scanner.nextLine();
		int sayac=0;
		
		for(int i=0; i<cumle.length();i++) {
			
			if(cumle.charAt(i)=='a'|| cumle.charAt(i)=='e'|| cumle.charAt(i)=='ı'|| cumle.charAt(i)=='i'|| cumle.charAt(i)=='o'|| cumle.charAt(i)=='ö'|| cumle.charAt(i)=='u'|| cumle.charAt(i)=='ü') 
			{
				sayac++;
			}
			
		}
		System.out.println("Cümle içinde "+sayac+" tane sesli harf bulundu.");
		scanner.close();
	}
}