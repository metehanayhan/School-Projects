import java.util.Scanner;

public class Anasayfa {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);

		System.out.print("Kaç tane Bilgisayar mühendisi olacak:");
		int bilsayi = scanner.nextInt();
		System.out.print("Kaç tane Makine mühendisi olacak:");
		int makinesayi = scanner.nextInt();
		System.out.print("Kaç tane Elektrik mühendisi olacak:");
		int elektriksayi = scanner.nextInt();
		int toplam = bilsayi + makinesayi + elektriksayi;

		Muhendis[] muhendis = new Muhendis[toplam];

		for (int i = 0; i < bilsayi; i++) {

			scanner.nextLine();
			System.out.print("\nAd:");
			String ad = scanner.nextLine();
			System.out.print("Yaş:");
			int yas = scanner.nextInt();
			System.out.print("Puan:");
			int puan = scanner.nextInt();

			muhendis[i] = new BilgisayarMuhendisi(ad, yas, puan);
			muhendis[i].bilgileriyazdir(ad, yas, puan);
			muhendis[i].puanhesapla(yas);

		}

		for (int i = bilsayi; i < makinesayi + bilsayi; i++) {

			scanner.nextLine();
			System.out.print("\nAd:");
			String ad = scanner.nextLine();
			System.out.print("Yaş:");
			int yas = scanner.nextInt();
			System.out.print("Puan:");
			int puan = scanner.nextInt();

			muhendis[i] = new MakineMuhendisi(ad, yas, puan);
			muhendis[i].bilgileriyazdir(ad, yas, puan);
			muhendis[i].puanhesapla(yas);

		}

		for (int i = makinesayi + bilsayi; i < toplam; i++) {

			scanner.nextLine();
			System.out.print("\nAd:");
			String ad = scanner.nextLine();
			System.out.print("Yaş:");
			int yas = scanner.nextInt();
			System.out.print("Puan:");
			int puan = scanner.nextInt();

			muhendis[i] = new ElektrikMuhendisi(ad, yas, puan);
			muhendis[i].bilgileriyazdir(ad, yas, puan);
			muhendis[i].puanhesapla(yas);

		}

		scanner.close();
	}

	
}
