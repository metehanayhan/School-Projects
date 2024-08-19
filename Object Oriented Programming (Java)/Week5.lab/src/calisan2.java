
public class calisan2 {
	public int id=0;
	public String isim="";
	public int yas;
	public int cocuksayisi;
	public int maas=500;
	
	
	public static void bilgileriyazdir(int id, String isim, int yas, int cocuksayisi, double maas) {
		
		System.out.println("ID:"+id);
		System.out.println("İsim:"+isim);
		System.out.println("Yaş:"+yas);
		System.out.println("Çocuk sayısı:"+cocuksayisi);
		System.out.println("Maaş:"+maas);
		
	}
	
	public static int yenimaashesapla(int maas,int yas, int cocuksayisi) {
		
		if(maas<15000) {
			
			maas+=maas*0.05;
		}
		else {
			
			if(cocuksayisi>0) {
				
				maas+=cocuksayisi*0.015;
				
			}
			else if(yas>40) {
				
				maas+=maas*0.035;
			}
			else {
				maas+=maas*0.25;
			}
		}
		return maas;
	}
	
public calisan2(int id, String isim, int yas, int cocuksayisi, int maas) {
		
		this.id=id;
		this.isim = isim;
		this.yas=yas; 
		this.cocuksayisi=cocuksayisi;
		this.maas=maas;
	}
	
	
}
