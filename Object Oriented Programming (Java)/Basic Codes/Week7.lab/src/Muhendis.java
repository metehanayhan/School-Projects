
public class Muhendis {

	public String ad;
	public int yas;
	public String brans;
	public int puan;
	
	
	public Muhendis(String ad, int yas) {
		this.ad = ad;
		this.yas = yas;
	}
	
	public void bilgileriyazdir(String ad, int yas, int puan){
		System.out.println("\nAd:"+ad);
		System.out.println("Yaş:"+yas);
		System.out.println("Puan:"+puan);
		
	}
	
	public void puanhesapla(int yas) {
		int puan= 3*yas;
		System.out.println("\nPuan:"+puan);
		
	}
	
}
