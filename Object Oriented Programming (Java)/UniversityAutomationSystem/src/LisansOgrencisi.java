//METEHAN AYHAN
//22100011024

public class LisansOgrencisi extends Ogrenci {

	private static int ogrIDCounter = 1;
    private int ogrID;
    private int ogrSinif;
    private String durum;
    
    
	public LisansOgrencisi(int bolNo, String ogrAd, String ogrSoyad, int ogrSinif) {
		super(bolNo, ogrAd, ogrSoyad);
		this.ogrID = ogrIDCounter++;
		this.ogrSinif = ogrSinif;
		this.setDurum("Lisans");
	}


	public int getOgrID() {
		return ogrID;
	}


	public void setOgrID(int ogrID) {
		this.ogrID = ogrID;
	}


	public int getOgrSinif() {
		return ogrSinif;
	}


	public void setOgrSinif(int ogrSinif) {
		this.ogrSinif = ogrSinif;
	}


	public String getDurum() {
		return durum;
	}


	public void setDurum(String durum) {
		this.durum = durum;
	}
	
    
	
}
