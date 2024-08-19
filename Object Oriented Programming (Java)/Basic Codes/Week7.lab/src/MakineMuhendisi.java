
public class MakineMuhendisi extends Muhendis {

	String brans = "Makine";

	public MakineMuhendisi(String ad, int yas, int puan) {
		super(ad, yas);
		this.puan = puan;
		this.brans = getBrans();
	}

	public String getBrans() {
		return brans;
	}

	public void setBrans(String brans) {
		this.brans = brans;
	}

	@Override
	public void bilgileriyazdir(String ad, int yas, int puan) {
		super.bilgileriyazdir(ad, yas, puan);
		System.out.println("Branş:" + this.brans);
	}

}
