import java.util.Scanner;

public class ornek1 {

public static void main(String args[]) {
		
		Scanner scanner = new Scanner(System.in);
		
		samsung telefon = new samsung();
		
		samsung[] telefonlar= new samsung[1]; 
		
		
		
		System.out.println("Id:");
		telefon.id= scanner.nextInt();
	    scanner.nextLine();
		System.out.println("Marka:");
		telefon.marka= scanner.nextLine();
		System.out.println("Model:");
		telefon.model= scanner.nextLine();
		System.out.println("Hafıza:");
		telefon.hafiza= scanner.nextInt();
		System.out.println("Hız:");
		telefon.hiz= scanner.nextInt();
		System.out.println("Kamera:");
		telefon.kamera= scanner.nextInt();
		
		telefonlar[0]= new samsung(telefon.id, telefon.marka, telefon.model, telefon.hafiza, telefon.hiz, telefon.kamera);
		
		telefon.bilgileriyazdir();
		
		//telefon.hafizadegerlendir(telefon.hafiza);
		
		//telefon.kameradegerlendir(telefon.kamera);
		
		//telefon.hizdegerlendir(telefon.hiz);
		
		samsung telefon3 = new samsung();
		telefon3.bilgileriyazdir();
		
		scanner.close();
}


}
