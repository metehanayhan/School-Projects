package hafta9_ornek2;

public class jenerik<T> {

	private T data;
	
	
    public jenerik(T data) {
		super();
		this.data = data;
	}

   
    
    public void nesneBilgileriniGoruntule() {
        System.out.println("Nesne Bilgileri: " + data);
    }
}

