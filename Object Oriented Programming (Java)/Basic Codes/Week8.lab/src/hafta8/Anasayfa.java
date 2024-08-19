package hafta8;

public class Anasayfa {
    public static void main(String[] args) {
        Ucgen[] ucgenDizisi = new Ucgen[2];

        ucgenDizisi[0] = new DikUcgen(6, 8);
        ucgenDizisi[1] = new IkizkenarUcgen(4, 4, 60);

        for (int i=0; i<ucgenDizisi.length; i++) {
        	
        	if(ucgenDizisi[i].getClass().getName()=="MyPackage.İkizkenarUcgen") {
        		
        		ucgenDizisi[i].UcgenTipiYazdir();
        		System.out.println("Alan: " + ((IkizkenarUcgen) ucgenDizisi[i]).AlanHesapla());
        	
        	}
        	else {
        		
        		ucgenDizisi[i].UcgenTipiYazdir();
        		System.out.println("Alan: " + ((DikUcgen) ucgenDizisi[i]).AlanHesapla());
        		System.out.println("Cevre: " + ((DikUcgen) ucgenDizisi[i]).CevreHesapla());
        	}
        	
         
    }
}}