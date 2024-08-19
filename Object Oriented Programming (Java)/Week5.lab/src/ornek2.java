import java.util.Scanner;

public class ornek2 {

    public static void main(String args[]) {
		
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("Çalışan sayısını girin:");
		int calisan_sayi = scanner.nextInt();
		
		calisan2[] calisandizi = new calisan2[calisan_sayi];

		for(int i=0;i<calisan_sayi;i++) {
			
			System.out.print("Çalışan id'si giriniz:");
			int id= scanner.nextInt();
			System.out.print("Çalışan ismi giriniz:");
			scanner.nextLine();
			String isim= scanner.nextLine();
			System.out.print("Çalışan yaşı giriniz:");
			int yas= scanner.nextInt();
			System.out.print("Çalışan çocuk sayısı giriniz:");
			int cocuksayisi= scanner.nextInt();
			System.out.print("Çalışan maaşı giriniz:");
			int maas= scanner.nextInt();
			
			
			calisandizi[i] = new calisan2(id,isim,yas,cocuksayisi,maas);
			
		}
		
		
			
			for(int i=0;i<calisan_sayi;i++) {
				
			System.out.println("\nÇalışan id'si:"+calisandizi[i].id);
			System.out.println("Çalışan ismi:"+calisandizi[i].isim);
			System.out.println("Çalışan yaşı:"+calisandizi[i].yas);
			System.out.println("Çalışan çocuk sayısı:"+calisandizi[i].cocuksayisi);
			System.out.println("Çalışan maaşı:"+calisandizi[i].maas+"\n");
			
			
		}
		
		scanner.close();
    }
}
