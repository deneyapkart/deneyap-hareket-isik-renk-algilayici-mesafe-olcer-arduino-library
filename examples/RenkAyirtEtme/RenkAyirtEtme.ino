/*
 *   Renk Ayırt Etme örneği,  
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   Deneyap Hareket, Işık, Renk Algılayıcı, Mesafe Ölçer Algılayıcısıdan renk verilerini okumaktadır ve okunan kırmızı, yeşil, mavi ve ortam renk değerlerini seri port ekranına yazdırmaktadır. 
 *   
 *   Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır. 
 *  
 *   Bu kütüphane örneği Deneyap Hareket, Işık, Renk Algılayıcı, Mesafe Ölçer Algılayıcısı için oluşturulmuştur.
 *      --->  https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-modul-deneyap-hareket-isk-renk-alglayc-ve <---
 *      --->  https://github.com/deneyapkart/deneyap-hareket-isik-renk-algilayici-mesafe-olcer-arduino-library  <---
*/
#include <Deneyap_HareketIsikRenkAlgilayiciMesafeOlcer.h>     // Deneyap Hareket, Işık, Renk Algılayıcı, Mesafe Ölçer Algılayıcısı kütüphanesi eklenmesi 

APDS9960 Renk;                                                // APDS9960 için class tanımlanması

uint16_t r, g, b, c;

void setup() {
  Serial.begin(115200);                                       // Seri haberleşme başlatılması
  if (!Renk.begin(0x39)) {                                    // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatılması
      delay(3000);
      Serial.println("I2C bağlantısı başarısız");             // I2C bağlantısı başarısız olursa seri port ekranına yazdırılması
  }
  Renk.enableColor(true);                                     // Renk ayırt etme aktifleştirilmesi
}

void loop() {
  Renk.getColorData(&r, &g, &b, &c);                          // Renk verilerinin okunması
  Serial.print("kirmizi: ");                                  // Okunan kırmızı renk değerinin yazdırılması
  Serial.print(r);
  
  Serial.print(" yesil: ");                                   // Okunan yeşil renk değerinin yazdırılması
  Serial.print(g);
  
  Serial.print(" mavi: ");                                    // Okunan mavi renk değerinin yazdırılması
  Serial.print(b);
  
  Serial.print(" ortam: ");                                   // Okunan ortam renk değerinin yazdırılması
  Serial.println(c);
  Serial.println();
  delay(500);
}
