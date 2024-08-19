import java.util.Random;
import java.util.Scanner;

public class ornek3 {

	public static void main(String args[]) {
		
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("Kaç telefon olacak? :");
		int sayi= scanner.nextInt();
		
		SmartPhone3[] telefon = new SmartPhone3[sayi];
		
		for(int i=0;i<sayi;i++) {
			
			scanner.nextLine();
			System.out.println("\nMarka: ");
			String marka= scanner.nextLine();
	        System.out.println("Model: ");
	        String model = scanner.nextLine();
	        System.out.println("Renk: ");
	        String renk = scanner.nextLine();
	        System.out.println("Hafıza: ");
	        int hafiza= scanner.nextInt();
	        System.out.println("Hız: ");
	        int hiz= scanner.nextInt();
	        
	        telefon [i]= new SmartPhone3(marka,model,renk,hafiza, hiz);
	        	
	        //SmartPhone3.bilgileriyazdir(marka, model, renk, hiz, hafiza);
		}
		
		SmartPhone3.listele(telefon);
		
		int min = 1;
        int max = telefon.length;

        Random rand = new Random();

        int rastgeleSayi = rand.nextInt((max - min) + 1) + min;
        
        SmartPhone3.yerdegistir(telefon, rastgeleSayi);
        
        SmartPhone3.listele(telefon);

		scanner.close();
	}


	
}
