/*Kullanıcıdan alınan bir kelimenin harflerini teker teker 
ekrana yazdıran Java kodunu yazınız*/

import java.util.Scanner;


public class ornek4 {

	public static void main(String args[]) {
		
		Scanner scanner = new Scanner(System.in);
		System.out.print("Bir kelime girin:");
		String kelime = scanner.nextLine();
		
		String[] harfler = kelime.split("");
		
		for(int i=0;i<kelime.length();i++) {
			
		System.out.println(harfler[i]);
	}
		scanner.close();
	}
	
	
}
