public class Ogrenci {
    String isim;
    int yas;
    double ortalama;

    // Constructor
    public Ogrenci(String isim, int yas, double ortalama) {
        this.isim = isim;
        this.yas = yas;
        this.ortalama = ortalama;
    }

    // Bilgileri yazdıran metot
    public void bilgileriYazdir() {
        System.out.println("Öğrenci Adı: " + isim);
        System.out.println("Yaşı: " + yas);
        System.out.println("Not Ortalaması: " + ortalama);
    }
}