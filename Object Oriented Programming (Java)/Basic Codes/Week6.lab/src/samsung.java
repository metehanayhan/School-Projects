public class samsung extends SmartPhone {

	int id;
	int hiz;
	int kamera;
	
	

	public samsung(int id, String marka, String model, int hafiza, int hiz, int kamera) {
		super(id, marka, model, hafiza);
		this.hiz=hiz;
		this.kamera=kamera;
	}

	public samsung() {
		
		super(2, "apple", "İPhone", 4);
	}

	
	@Override
	public void bilgileriyazdir() {
        super.bilgileriyazdir();
        System.out.println("Hız: " + this.hiz);
        System.out.println("Kamera: " + this.kamera);
	}


	public static void hizdegerlendir(int hiz) {
		if(hiz<3.2) {
			System.out.println("\nYetersiz hız!");
		}
			else {
				System.out.println("\nHız yeterli.");
		}
		
	}
	
	public static void kameradegerlendir(int kamera) {
		if(kamera<32) {
			System.out.println("\nYetersiz kamera!");
		}
			else {
				System.out.println("\nKamera yeterli.");
		}
		
	}
	

	
}
