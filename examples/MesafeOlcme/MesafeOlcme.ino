/*
 *   Yakınlık Ölçme örneği,
 *
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   Sensörden yakın mesafe yakınlık verilerini okumaktadır ve 500 milisaniyede bir yakınlık değerini seri terminale yazdırmaktadır.
 *
 *   Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır.
 *
 *   Bu kütüphane örneği Deneyap Hareket, Işık, Renk Algılayıcı, Mesafe Ölçer Algılayıcısı için oluşturulmuştur.
 *      ------>  www.....com <------ //docs
 *      ------>  https://github.com/deneyapkart/deneyap-hareket-isik-renk-algilayici-mesafe-olcer-arduino-library  <------ 
 */
#include <Deneyap_HareketIsikRenkAlgilayiciMesafeOlcer.h>       //Deneyap_HareketIsikRenkAlgilayiciMesafeOlcer.h kütüphanesi eklendi

APDS9960 Yakinlik;                                              // APDS9960 için class tanımlanması

void setup() {
    Serial.begin(115200);                                       // Seri haberleşme başlatıldı
    if (!Yakinlik.begin(0x39)) {                                // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatıldı
        delay(3000);
        Serial.println("APDS-9960 I2C bağlantısı başarısız ");  // I2C bağlantısı başarısız olursa seri terminale yazdırıldı
    }
    Yakinlik.enableProximity(true);                             // yakınlık ölçüm aktifleştirildi
}

void loop() {
    /*  mesafe sonucları
        - 0   => yakın
        - 255 => uzak
        - -1  => hata   */
    Serial.print("yakınlık :");
    Serial.println(Yakinlik.readProximity());                  //ölçüm yapılıyor ve seri terminale veri gönderiliyor
    delay(500);
}
