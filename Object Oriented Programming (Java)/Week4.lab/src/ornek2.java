import java.util.Scanner;

public class ornek2 {

	public static void main(String args[]) {
		
		Scanner scanner = new Scanner(System.in);
		
		  SmartPhone nesne1 = new SmartPhone();
			nesne1.marka= "Samsung";
			nesne1.model= "S21 FE";
			nesne1.renk= "Yeşil";
			nesne1.hiz= 2;
			nesne1.hafiza= 128;
		   SmartPhone.bilgileriyazdir(nesne1.marka, nesne1.model, nesne1.renk, nesne1.hiz, nesne1.hafiza);
		   SmartPhone.hafizadegerlendir(nesne1.hafiza);
		   
		   SmartPhone nesne2 = new SmartPhone();
		   
		   System.out.println("\nNesne 2 Bilgilerini Girin:");
	        System.out.print("Marka: ");
	        nesne2.marka = scanner.nextLine();
	        System.out.print("Model: ");
	        nesne2.model = scanner.nextLine();
	        System.out.print("Renk: ");
	        nesne2.renk = scanner.nextLine();
	        System.out.print("Hafıza (GB): ");
	        nesne2.hafiza = scanner.nextInt();
	        System.out.print("Hız (GHz): ");
	        nesne2.hiz = scanner.nextInt();
	        SmartPhone.bilgileriyazdir(nesne2.marka, nesne2.model, nesne2.renk, nesne2.hiz, nesne2.hafiza);
	        SmartPhone.hafizadegerlendir(nesne2.hafiza);
	      

	        SmartPhone nesne3 = new SmartPhone();
	        
	        System.out.println("\nNesne 3 Bilgilerini Girin:");
	        System.out.print("Marka: ");
	        nesne3.marka = scanner.nextLine();
	        System.out.print("Model: ");
	        nesne3.model = scanner.nextLine();
	        System.out.print("Renk: ");
	        nesne3.renk = scanner.nextLine();
	        System.out.print("Hafıza (GB): ");
	        nesne3.hafiza = scanner.nextInt();
	        System.out.print("Hız (GHz): ");
	        nesne3.hiz = scanner.nextInt();
            SmartPhone.bilgileriyazdir(nesne3.marka, nesne3.model, nesne3.renk, nesne3.hiz, nesne3.hafiza);
	        SmartPhone.hafizadegerlendir(nesne3.hafiza);
	        
			scanner.close();
	}
	
}
	
	
