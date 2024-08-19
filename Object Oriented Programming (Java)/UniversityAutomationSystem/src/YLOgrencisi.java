//METEHAN AYHAN

public class YLOgrencisi extends Ogrenci {

	private static int ogrIdCounter=1;
	private int ogrId;
	private String durum;
	
	
	public YLOgrencisi(int bolNo, String ogrAd, String ogrSoyad) {
		super(bolNo, ogrAd, ogrSoyad);
		this.ogrId = ogrIdCounter++;
		this.durum = "Yüksek Lisans";
	}


	public int getOgrId() {
		return ogrId;
	}


	public void setOgrId(int ogrId) {
		this.ogrId = ogrId;
	}


	public String getDurum() {
		return durum;
	}


	public void setDurum(String durum) {
		this.durum = durum;
	}
	

	
}
