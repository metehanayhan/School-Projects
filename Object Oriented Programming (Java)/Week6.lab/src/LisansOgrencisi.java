
public class LisansOgrencisi extends Ogrenci{
	
	String durum;
	int sinif;
	int vizenot;
	int finalnot;
	
	
	public LisansOgrencisi(String ad, String soyad, int sinif, int vizenot, int finalnot) {
		super(ad, soyad);
		this.durum = "Lisans";
		this.sinif = sinif;
		this.vizenot = vizenot;
		this.finalnot = finalnot;
	}


	

	@Override
	public void bilgileriyazdir(Ogrenci ogrenci, String ad, String soyad) {
		// TODO Auto-generated method stub
		super.bilgileriyazdir(ogrenci, ad, soyad);
		System.out.println("Durum:"+durum);
		System.out.println("Sınıf:"+sinif);
		System.out.println("Vize not:"+vizenot);
		System.out.println("Final not:"+finalnot);
	}





	@Override
	public void mezuniyetyilihesapla(int sinif, String ad, int id) {
		int yil= 4-sinif;
		int m_yili= 2024+yil;
		System.out.println("\nId:"+id+ " Ad:"+ad+" |Mezuniyet yılı:" + m_yili );
	}

	

	public void gecmenotuhesapla(int finalnot , int vizenot, String ad, int id) {
		
		int gecmenotu = (int) ((finalnot*0.6)+ (vizenot*0.4));
		System.out.println("\nId:"+ id + " |Ad:"+ ad + " |Geçme notu:" + gecmenotu );
	}

}
