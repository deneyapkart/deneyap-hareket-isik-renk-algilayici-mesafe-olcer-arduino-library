/*
 *   Hareket Algılama örneği, 
 *   
 *   Bu örnekte temel konfigürasyon ayarları yapılmaktadır.
 *   Sensörden gelen hareket verilerini okumaktadır ve algılanan heraketleri seri terminale yazdırmaktadır.   
 *   Hareket yönleri
 *   - Aşağı:   DENEYAP logosundan T3 logo tarafına doğru
 *   - Yukarı:  T3 logosundan DENEYAP logo tarafına doğru
 *   - Sol:     3V3 pininden GND pin tarafına doğru
 *   - Sağ:     GND pininden 3V3 pin tarafına doğru
 *   
 *   Bu algılayıcı I2C haberleşme protokolü ile çalışmaktadır. 
 *  
 *   Bu kütüphane örneği Deneyap Hareket, Işık, Renk Algılayıcı, Mesafe Ölçer Algılayıcısı için oluşturulmuştur.
 *      ------>  www.....com <------ //docs
 *      ------>  https://github.com/deneyapkart/deneyap-hareket-isik-renk-algilayici-mesafe-olcer-arduino-library  <------ 
*/
#include <Deneyap_HareketIsikRenkAlgilayiciMesafeOlcer.h>       // Deneyap_HareketIsikRenkAlgilayiciMesafeOlcer.h kütüphanesi eklendi 

APDS9960 Hareket;                                               // APDS9960 için class tanımlanması

void setup() {
  Serial.begin(115200);                                         // Seri haberleşme başlatıldı
  if (!Hareket.begin(0x39)) {                                   // begin(slaveAdress) fonksiyonu ile cihazların haberleşmesi başlatıldı
      delay(3000);
      Serial.println("APDS-9960 I2C bağlantısı başarısız ");    // I2C bağlantısı başarısız olursa seri terminale yazdırıldı
  }  
  Hareket.enableProximity(true);
  Hareket.enableGesture(true);                                  // Hareket ölçüm aktifleştirildi
}


void loop() {  
    uint8_t gesture = Hareket.readGesture();                    // Yapılan hareket yönünü okuma    
    if(gesture == APDS9960_DOWN)  Serial.println("Asagi");      // Aşağıya doğru hareket algılama    
    if(gesture == APDS9960_UP)    Serial.println("Yukari");     // Yukarıya doğru hareket algılama
    if(gesture == APDS9960_LEFT)  Serial.println("Sol");        // Sola doğru hareket algılama
    if(gesture == APDS9960_RIGHT) Serial.println("Sag");        // Sağa doğru hareket algılama
}
