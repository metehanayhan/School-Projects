
public class ornek3 {

	public static void main(String args[]) {

		
		calisan calisan2 = new calisan("Metehan", 20, 2);
		
		int yenimaas= calisan.yenimaashesapla(calisan2.getMaas(),calisan2.getYas(),calisan2.getCocuksayisi());
		
		calisan.bilgileriyazdir(calisan.idsayaci, calisan2.getIsim(), calisan2.getYas(),calisan2.getCocuksayisi(),yenimaas);
		
		
		
		
		
	
	}
	
	
}
