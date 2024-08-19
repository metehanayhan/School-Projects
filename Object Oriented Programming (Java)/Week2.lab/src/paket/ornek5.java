package paket;

import java.util.Scanner;

public class ornek5 {

	
	public static void main(String args[]) {
		
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("Vize notu girin");
		double vize =scanner.nextDouble();
		
		System.out.println("Final notunu girin:");
		double finalnot = scanner.nextDouble();
	
		double gecmenotu= vize*0.4 + finalnot*0.6;
		String harfnotu;
		if(gecmenotu>=90) {
			harfnotu= "AA";
		}
		else if(gecmenotu>=85 && gecmenotu<90) {
			harfnotu="BA";
		}
		else if(gecmenotu<85 && gecmenotu>70){
			harfnotu="CC";
		}
		else {
			harfnotu="FF";
		}
		
		System.out.println("Geçme notunuz:"+gecmenotu);
		System.out.println("Harf notunuz:"+harfnotu);
		
		scanner.close();
	}
	
	
}
