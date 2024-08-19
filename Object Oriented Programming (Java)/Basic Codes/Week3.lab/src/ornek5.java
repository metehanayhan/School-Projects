/*Kullanıcıdan alınan cümle içerisindeki boşlukları silen ve 
tüm ‘a’ harflerini e harfi yapan Java kodunu yazınız*/

import java.util.Scanner;

public class ornek5 {

	
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Bir cümle girin:");
		String cumle = scanner.nextLine();
		cumle = cumle.replace(" ","");
		cumle = cumle.replace('a','e');
		System.out.println("Yeni cümle: "+cumle);
		
		scanner.close();
	}
}
