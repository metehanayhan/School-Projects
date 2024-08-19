//METEHAN AYHAN
//22100011024

public class Ders {

	private static int dersIdsayaci =1;
	 private int bolNo;
	 private int dersID;
	 private String dersAd;
	 private int dersKredi;
	 
	 
	public Ders(int bolNo, String dersAd, int dersKredi) {
		super();
		this.setBolNo(bolNo);
		this.dersAd = dersAd;
		this.dersKredi = dersKredi;
		this.dersID= dersIdsayaci++;
	}


	public int getDersID() {
		return dersID;
	}


	public void setDersID(int dersID) {
		this.dersID = dersID;
	}


	public String getDersAd() {
		return dersAd;
	}


	public void setDersAd(String dersAd) {
		this.dersAd = dersAd;
	}


	public int getDersKredi() {
		return dersKredi;
	}


	public void setDersKredi(int dersKredi) {
		this.dersKredi = dersKredi;
	}


	public int getBolNo() {
		return bolNo;
	}


	public void setBolNo(int bolNo) {
		this.bolNo = bolNo;
	}
	
	
}
