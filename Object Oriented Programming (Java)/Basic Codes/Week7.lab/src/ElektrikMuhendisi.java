
public class ElektrikMuhendisi extends Muhendis {
	int puan;

	String brans = "Elektrik";

	public String getBrans() {
		return brans;
	}

	public void setBrans(String brans) {
		this.brans = brans;
	}

	public ElektrikMuhendisi(String ad, int yas, int puan) {
		super(ad, yas);
		this.puan = puan;
		this.brans = getBrans();
	}

	@Override
	public void bilgileriyazdir(String ad, int yas, int puan) {
		super.bilgileriyazdir(ad, yas, puan);
		System.out.println("Branş:" + this.brans);
	}

	@Override
	public void puanhesapla(int yas) {
		int puan = 5 * yas;
		System.out.println("\nPuan:" + puan);

	}

}
