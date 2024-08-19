package hafta8;

class IkizkenarUcgen extends Ucgen implements Alan {
    public int aci;

    public IkizkenarUcgen(int kenar1, int kenar2, int aci) {
        super(kenar1, kenar2);
        this.aci= aci;
    }

    @Override
    public void UcgenTipiYazdir() {
        System.out.println("İkizkenar Üçgen");
    }

    @Override
    public double AlanHesapla() {
        return 0.5 * kenar1 * kenar2 *Math.toRadians(aci);
    }

	@Override
	public double CevreHesapla() {
		// TODO Auto-generated method stub
		return 0;
	}


	
}