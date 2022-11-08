/*
 *   Yakınlık Ölçme örneği,
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   Deneyap Hareket, Işık, Renk Algılayıcı, Mesafe Ölçer Algılayıcısından yakın mesafe yakınlık verilerini okumaktadır ve okunan yakınlık değerini seri port ekranına yazdırmaktadır.
 *
 *   Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır. 
 *  
 *   Bu kütüphane örneği Deneyap Hareket, Işık, Renk Algılayıcı, Mesafe Ölçer Algılayıcısı için oluşturulmuştur.
 *      --->  https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-modul-deneyap-hareket-isk-renk-alglayc-ve <---
 *      --->  https://github.com/deneyapkart/deneyap-hareket-isik-renk-algilayici-mesafe-olcer-arduino-library  <--- 
*/
#include <Deneyap_HareketIsikRenkAlgilayiciMesafeOlcer.h>       // Deneyap Hareket, Işık, Renk Algılayıcı, Mesafe Ölçer Algılayıcısı kütüphanesi eklenmesi 

APDS9960 Yakinlik;                                              // APDS9960 için class tanımlanması

void setup() {
    Serial.begin(115200);                                       // Seri haberleşme başlatılması
    if (!Yakinlik.begin(0x39)) {                                // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatılması
        delay(3000);
        Serial.println("I2C bağlantısı başarısız");             // I2C bağlantısı başarısız olursa seri port ekranına yazdırılması
    }
    Yakinlik.enableProximity(true);                             // Yakınlık ölçüm aktifleştirilmesi
}

void loop() {
    /*  255 => yakın
        0   => uzak
        -1  => hata   */
    Serial.print("yakınlık :");
    Serial.println(Yakinlik.readProximity());                  // Okunan yakınlık değerinin seri port ekranına yazdırılması
    delay(500);
}
