
public class YuksekLisansOgrencisi extends Ogrenci {

	String durum;
	String asama;
	int finalnot;
	
	
	public YuksekLisansOgrencisi(String ad, String soyad, String asama, int finalnot) {
		super( ad, soyad);
		this.durum = "Yüksek Lisans";
		this.asama = asama;
		this.finalnot = finalnot;
	}

	



	@Override
	public void bilgileriyazdir(Ogrenci ogrenci, String ad, String soyad) {
		// TODO Auto-generated method stub
		super.bilgileriyazdir(ogrenci, ad, soyad);
	}





	@Override
	public void mezuniyetyilihesapla() {
		// TODO Auto-generated method stub
		super.mezuniyetyilihesapla();
	
	}



	public void harfhesapla(int finalnot) {
		
		if(finalnot>60) {
			System.out.println("Harf notu: AA");
		}
		else {
			System.out.println("Harf notu: FF");
		}
	}
}
