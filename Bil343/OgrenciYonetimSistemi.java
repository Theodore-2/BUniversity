import java.util.Scanner;

public class OgrenciYonetimSistemi {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Ogrenci[] ogrenciler = new Ogrenci[5];
        int ogrenciSayisi = 0;

        while (true) {
            System.out.println("\nÖğrenci Yönetim Sistemine Hoş Geldiniz!");
            System.out.println("1. Öğrenci Ekle");
            System.out.println("2. Tüm Öğrencileri Görüntüle");
            System.out.println("3. Ortalama Üstü Öğrencileri Görüntüle");
            System.out.println("4. Çıkış");
            System.out.print("Bir seçenek girin: ");
            int secim = scanner.nextInt();

            if (secim == 1) {
                // Öğrenci ekleme
                if (ogrenciSayisi < ogrenciler.length) {
                    scanner.nextLine(); // Satır sonu karakterini temizle
                    System.out.print("Öğrenci Adı: ");
                    String isim = scanner.nextLine();
                    System.out.print("Yaşı: ");
                    int yas = scanner.nextInt();
                    System.out.print("Not Ortalaması: ");
                    double ortalama = scanner.nextDouble();

                    ogrenciler[ogrenciSayisi] = new Ogrenci(isim, yas, ortalama);
                    ogrenciSayisi++;
                    System.out.println("Öğrenci eklendi!");
                } else {
                    System.out.println("Öğrenci dizisi dolu!");
                }

            } else if (secim == 2) {
                // Tüm öğrencileri görüntüle
                System.out.println("\nTüm Öğrenciler:");
                for (int i = 0; i < ogrenciSayisi; i++) {
                    ogrenciler[i].bilgileriYazdir();
                    System.out.println("-------------------");
                }

            } else if (secim == 3) {
                // Ortalama üstü öğrencileri görüntüle
                System.out.print("Ortalama Değeri Girin: ");
                double arananOrtalama = scanner.nextDouble();

                System.out.println("\nOrtalama Üstü Öğrenciler:");
                for (int i = 0; i < ogrenciSayisi; i++) {
                    if (ogrenciler[i].ortalama > arananOrtalama) {
                        ogrenciler[i].bilgileriYazdir();
                        System.out.println("-------------------");
                    }
                }

            } else if (secim == 4) {
                // Çıkış
                System.out.println("Sistemden çıkılıyor...");
                break;

            } else {
                System.out.println("Geçersiz bir seçenek girdiniz.");
            }
        }

        scanner.close();
    }
}