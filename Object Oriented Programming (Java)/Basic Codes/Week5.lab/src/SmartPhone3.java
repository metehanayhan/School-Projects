
public class SmartPhone3 {
	String marka;
	String model;
	String renk;
	int hafiza;
	int hiz;
	

	public static void bilgileriyazdir(String marka,String model,String renk, int hiz,int hafiza) {
		System.out.println("\nMarka: " + marka);
        System.out.println("Model: " + model);
        System.out.println("Renk: " + renk);
        System.out.println("Hafıza: " + hafiza);
        System.out.println("Hız: " + hiz);
		
	}
	public static void hafizadegerlendir(int hafiza) {
		if(hafiza<3.2) {
			System.out.println("\nYetersiz hafıza!");
		}
			else {
				System.out.println("\nHafıza yeterli.");
		}
		
	}
	
	public SmartPhone3(String marka, String model, String renk, int hafiza, int hiz) {
		
		this.marka=marka;
		this.model=model;
		this.renk=renk;
		this.hafiza=hafiza;
		this.hiz=hiz;
	}
	
	public static void listele(SmartPhone3 telefon[]) {
		
		for(SmartPhone3 telefon1 : telefon ) {
			
			System.out.println("\nMarka:"+telefon1.marka);
			System.out.println("Model:"+telefon1.model);
			System.out.println("Renk:"+telefon1.renk);
			System.out.println("Hafıza:"+telefon1.hafiza);
			System.out.println("Hız:"+telefon1.hiz);
		  }
		}
	
	public static void yerdegistir(SmartPhone3 telefon[], int rastgeleSayi) {
		
		SmartPhone3 gecici = telefon[0];
        telefon[0] = telefon[rastgeleSayi];
        telefon[rastgeleSayi] = gecici;
		
		System.out.println("Yer değiştirildi.");
	}
}
