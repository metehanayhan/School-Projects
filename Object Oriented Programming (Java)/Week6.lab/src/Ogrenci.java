
public class Ogrenci {

	
    private static int sayac=1;
	private int id=1;
	String ad;
	String soyad;
	
	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}
	
	public Ogrenci(String ad, String soyad) {
		this.id = sayac++;
		this.ad = ad;
		this.soyad = soyad;
		
	}

	public void bilgileriyazdir(Ogrenci ogrenci, String ad, String soyad) {
		
		System.out.println("\nId:"+ogrenci.id);
		System.out.println("Ad:"+ad);
		System.out.println("Soyad:"+soyad);
	}
	

	public void mezuniyetyilihesapla(int sinif, String ad, int id) {
		// TODO Auto-generated method stub
		
	}

	public void mezuniyetyilihesapla() {
		// TODO Auto-generated method stub
		
	}
	
}
