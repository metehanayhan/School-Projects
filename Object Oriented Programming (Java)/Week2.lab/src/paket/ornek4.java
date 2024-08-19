package paket;

import java.util.Scanner;

public class ornek4 {

	public static void main(String args[]) {
		
		int pi=3;
		Scanner scanner = new Scanner(System.in);
		System.out.println("yarıçap değerini giriniz:");
		int yaricap = scanner.nextInt();
		
	    int alan = yaricap*yaricap * pi;
		System.out.println("Dairenin alanı:"+alan);
		
		scanner.close();
	}
}
