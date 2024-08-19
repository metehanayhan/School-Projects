//METEHAN AYHAN
//22100011024

public class Ogrenci {

	private int bolNo;
	private String ogrAd;
	private String ogrSoyad;
	
	public Ogrenci(int bolNo, String ogrAd, String ogrSoyad) {
		super();
		this.setBolNo(bolNo);
		this.ogrAd = ogrAd;
		this.ogrSoyad = ogrSoyad;
	}

	public String getOgrAd() {
		return ogrAd;
	}

	public void setOgrAd(String ogrAd) {
		this.ogrAd = ogrAd;
	}

	public String getOgrSoyad() {
		return ogrSoyad;
	}

	public void setOgrSoyad(String ogrSoyad) {
		this.ogrSoyad = ogrSoyad;
	}

	public int getBolNo() {
		return bolNo;
	}

	public void setBolNo(int bolNo) {
		this.bolNo = bolNo;
	}
	
	
	
}
