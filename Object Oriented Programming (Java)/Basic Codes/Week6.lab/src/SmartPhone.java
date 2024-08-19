
public class SmartPhone {

	private int id;
	String marka;
	String model;
	int hafiza;
	
	
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	


	public void bilgileriyazdir() {
		System.out.println("Id: " + this.id);
		System.out.println("Marka: " + this.marka);
        System.out.println("Model: " + this.model);
        System.out.println("Hafıza: " + this.hafiza);
       
	}
	
	//final old icin override edilemez..
	public final void hafizadegerlendir(int hafiza) {
		if(hafiza<128) {
			System.out.println("\nYetersiz hafıza!");
		}
			else {
				System.out.println("\nHafıza yeterli.");
		}
		
	}
	
	//yapici metod
	public SmartPhone(int id,String marka,String model,int hafiza ) {
		
		this.id=id;
		this.marka=marka;
		this.model=model;
		this.hafiza=hafiza;
	
	}
	
}
