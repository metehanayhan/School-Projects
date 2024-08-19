
public class SmartPhone {

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
	
}

