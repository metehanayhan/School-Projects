
public class calisan {

	public static int idsayaci=0;
	private int id=0;
	private String isim;
	private int yas;
	private int cocuksayisi;
	private int maas=500;
	
	
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
	
	public int getId() {
		return id++;
	}
	
	public void setId(int yeniId) {
		
		this.id= yeniId;
	}
	
	public String getIsim() {
		return isim;
	}
	
	public void setIsim(String yeniIsim) {
		
		this.isim= yeniIsim;
	}
	
	public int getYas() {
		return yas;
	}
	
	public void setYas(int yeniyas) {
		
		this.yas= yeniyas;
	}
	
	public int getCocuksayisi() {
		return cocuksayisi;
	}
	
	public void setCocuksayisi(int yeniCocuksayisi) {
		
		this.cocuksayisi= yeniCocuksayisi;
	}
	
	public int getMaas() {
		return maas;
	}
	
	public void setMaas(int yeniMaas) {
		
		this.maas= yeniMaas;
	}
	
	public calisan(int idsayaci, String isim, int yas) {
		
		calisan.idsayaci+=1;
		this.isim = isim;
		this.yas=yas; 
	}
	
public calisan(String isim, int yas, int cocuksayisi) {
		
		this.isim = isim;
		this.yas=yas; 
		this.cocuksayisi=cocuksayisi;
	}
}
