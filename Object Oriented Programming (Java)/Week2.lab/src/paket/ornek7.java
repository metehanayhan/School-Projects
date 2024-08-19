package paket;

import java.util.Scanner;


public class ornek7 {
	
	public static void main(String args[]) {
		
		Scanner input =new Scanner(System.in);
		System.out.print("Soru sayısı girin:");
		int sorusayisi = input.nextInt();
		
		System.out.print("Doğru sayısı girin:");
		int dogrusayisi = input.nextInt();
		
		System.out.print("Yanlış sayısı girin:");
		double yanlissayisi = input.nextDouble();
		
		double bosSayisi = sorusayisi- (dogrusayisi+yanlissayisi);
		double net = dogrusayisi - (yanlissayisi/4);
		
		System.out.println("Boş sayısı:"+bosSayisi);
		System.out.println("Toplam net:"+net);
		
		input.close();
	}
	
	
}
