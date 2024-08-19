package hafta8;

class DikUcgen extends Ucgen implements Alan, Cevre {//coklu kalitim burda...
    public int aci;

    public DikUcgen(int kenar1, int kenar2) {
        super(kenar1, kenar2);
        this.kenar3 = (int) Math.sqrt(kenar1 * kenar1 + kenar2 * kenar2);
        aci=90;
    }

    @Override
    public void UcgenTipiYazdir() {
        System.out.println("Dik Üçgen");
    }

    @Override
    public double AlanHesapla() {
        return 0.5 * kenar1 * kenar2;
    }

    @Override
    public double CevreHesapla() {
        return kenar1 + kenar2 + kenar3;
    }

	
}