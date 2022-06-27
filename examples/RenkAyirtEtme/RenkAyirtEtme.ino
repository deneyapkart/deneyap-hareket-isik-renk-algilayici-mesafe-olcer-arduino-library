/*
 *   Renk Ayırt Etme örneği,  
 *   
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   Sensörden renk verilerini okumaktadır ve 500 milisaniyede bir Kırmızı, Yeşil, Mavi renk değerlerini seri terminale yazdırmaktadır. 
 *   
 *   Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır.
 *    
 *   Bu kütüphane örneği Deneyap Hareket, Işık, Renk Algılayıcı, Mesafe Ölçer Algılayıcısı için oluşturulmuştur.
 *      ------>  www.....com <------ //docs
 *      ------>  https://github.com/deneyapkart/deneyap-hareket-isik-renk-algilayici-mesafe-olcer-arduino-library  <------ 
*/
#include <Deneyap_HareketIsikRenkAlgilayiciMesafeOlcer.h>     //Deneyap_HareketIsikRenkAlgilayiciMesafeOlcer.h kütüphanesi eklendi 

APDS9960 Renk;                                                //APDS9960 için class tanımlanması

void setup() {
  Serial.begin(115200);                                       //Seri haberleşme başlatıldı
  if (!Renk.begin(0x39)) {                                    // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatıldı
      delay(3000);
      Serial.println("APDS-9960 I2C bağlantısı başarısız ");  // I2C bağlantısı başarısız olursa seri terminale yazdırıldı
  }
  Renk.enableColor(true);                                     //Renk ayırt etme aktifleştirildi
}

void loop() {
  uint16_t r, g, b, c;
  while(!Renk.colorDataReady()){
    delay(5);
  }
  
  Renk.getColorData(&r, &g, &b, &c);                          // Renk verilerini alma
  Serial.print("kirmizi: ");                                  // Kırmızı değerini yazdırma
  Serial.print(r);
  
  Serial.print(" yesil: ");                                   // Yeşil değerini yazdırma
  Serial.print(g);
  
  Serial.print(" mavi: ");                                    // Mavi değerini yazdırma
  Serial.print(b);
  
  Serial.print(" ortam: ");                                   // Ortam değerini yazdırma
  Serial.println(c);
  Serial.println();
  
  delay(500);
}
