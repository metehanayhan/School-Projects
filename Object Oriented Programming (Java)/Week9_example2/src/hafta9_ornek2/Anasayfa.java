package hafta9_ornek2;

public class Anasayfa {
    public static void main(String[] args) {
        
    	
    	 jenerik<Integer> integerSinifi = new jenerik<>(21);
    	 jenerik<String> stringSinifi = new jenerik<>("Metehan Ayhan");
    	 jenerik<Double> doubleSinifi = new jenerik<>(88.67);
    	 
       
        integerSinifi.nesneBilgileriniGoruntule();
        stringSinifi.nesneBilgileriniGoruntule();
        doubleSinifi.nesneBilgileriniGoruntule();
    }
}
