/*
 *   Hareket Algılama örneği, 
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   Deneyap Hareket, Işık, Renk Algılayıcı, Mesafe Ölçer Algılayıcısından gelen hareket verilerini okumaktadır ve okunan heraketleri seri port ekranına yazdırmaktadır.   
 *   Hareket yönleri
 *   - Aşağı:   DENEYAP logosundan T3 logo tarafına doğru
 *   - Yukarı:  T3 logosundan DENEYAP logo tarafına doğru
 *   - Sol:     3V3 pininden GND pin tarafına doğru
 *   - Sağ:     GND pininden 3V3 pin tarafına doğru
 *   
 *   Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır. 
 *  
 *   Bu kütüphane örneği Deneyap Hareket, Işık, Renk Algılayıcı, Mesafe Ölçer Algılayıcısı için oluşturulmuştur.
 *      --->  https://docs.deneyapkart.org/tr/content/contentDetail/deneyap-modul-deneyap-hareket-isk-renk-alglayc-ve <---
 *      --->  https://github.com/deneyapkart/deneyap-hareket-isik-renk-algilayici-mesafe-olcer-arduino-library  <--- 
*/
#include <Deneyap_HareketIsikRenkAlgilayiciMesafeOlcer.h>       // Deneyap Hareket, Işık, Renk Algılayıcı, Mesafe Ölçer Algılayıcısı kütüphanesi eklenmesi 

APDS9960 Hareket;                                               // APDS9960 için class tanımlanması

void setup() {
  Serial.begin(115200);                                         // Seri haberleşme başlatılması
  if (!Hareket.begin(0x39)) {                                   // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatılması
      delay(3000);
      Serial.println("I2C bağlantısı başarısız");               // I2C bağlantısı başarısız olursa seri port ekranına yazdırılması
  }  
  Hareket.enableGesture(true);                                  // Hareket ölçüm aktifleştirilmesi
}


void loop() {  
    uint8_t gesture = Hareket.readGesture();                    // Yapılan hareket yönünü okunması
    if(gesture == APDS9960_DOWN)  Serial.println("Asagi");      // Aşağıya doğru hareket algılanırsa seri port ekranına "Asagi" yazdırılması
    if(gesture == APDS9960_UP)    Serial.println("Yukari");     // Yukarıya doğru hareket algılanırsa seri port ekranına "Yukari" yazdırılması
    if(gesture == APDS9960_LEFT)  Serial.println("Sol");        // Sola doğru hareket algılanırsa seri port ekranına "Sol" yazdırılması
    if(gesture == APDS9960_RIGHT) Serial.println("Sag");        // Sağa doğru hareket algılanırsa seri port ekranına "Sag" yazdırılması
}