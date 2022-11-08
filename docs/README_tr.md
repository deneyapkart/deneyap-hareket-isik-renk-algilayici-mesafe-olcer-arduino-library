# Deneyap Hareket, Işık, Renk Algılayıcı&Mesafe Ölçer Arduino Kütüphanesi

***** Fotoğraf eklenecek ****

Deneyap Hareket, Işık, Renk Algılayıcı&Mesafe Ölçer APDS-9960 için Arduino kütüphanesidir.

## :mag_right:Özellikler 
- `Ürün ID` **M25** , **mpv1.0**
- `MCU` APDS-9960
- `Ağırlık`
- `Modul Boyutları` 
- `I2C Adres` 0x39

| Adres |  | 
| :---  | :---     |
| 0x39  | varsayılan adres |

## :closed_book:Dokümanlar
[Deneyap Hareket, Işık, Renk Algılayıcı&Mesafe Ölçer](https://docs.deneyapkart.org/en/content/contentDetail/deneyap-modul-deneyap-hareket-isk-renk-alglayc-ve)

[Deneyap Hareket, Işık, Renk Algılayıcı&Mesafe Ölçer Şematik](https://cdn.deneyapkart.org/media/upload/userFormUpload/siVrurpuG9sb9DMKQPnCD6H5vYXWXsD0.pdf)

[Deneyap Hareket, Işık, Renk Algılayıcı&Mesafe Ölçer Teknik Çizim](https://cdn.deneyapkart.org/media/upload/userFormUpload/Zi33d127Omdb0DTZ2rR3EvV1uwp4Ul5j.pdf)

[APDS-9960_datasheet](https://docs.broadcom.com/doc/AV02-4191EN)

[Arduino IDE'de Kütüphane Nasıl İndirilir](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries)

## :pushpin:Deneyap Hareket, Işık, Renk Algılayıcı&Mesafe Ölçer
Bu Arduino kütüphanesi Deneyap Hareket, Işık, Renk Algılayıcı&Mesafe Ölçer I2C çevre birimi ile kullanılmasını sağlar. Arduino ile uyumlu, I2C çevre birimine sahip herhangi bir geliştirme kartı ile bu kütüphaneyi projelerinizde kullanabilirsiniz.

## :globe_with_meridians:Repo İçeriği
- `/docs` README_tr.md ve ürün fotoğrafları
- `/examples` .ino uzantılı örnek uygulamalar
- `/src` kütüphane için .cpp ve .h uzantılı dosyalar
- `keywords.txt` Arduino IDE'de vurgulanacak anahtar kelimeler
- `library.properties` Arduino yöneticisi için genel kütüphane özellikleri

## Sürüm Geçmişi
1.0.1 - fonksiyon güncellendi(enableGesture), örnek uygulamalardaki yorum satırları güncellendi

1.0.0 - ilk sürüm

## :rocket:Donanım Bağlantıları
- Deneyap Hareket, Işık, Renk Algılayıcı&Mesafe Ölçer ile kullanılan geliştirme kartı I2C kablosu ile bağlanabilir
- veya jumper kablolar ile 3V3, GND, SDA ve SCL bağlantıları yapılabilir. 

|Hareket, Işık, Renk Algılayıcı&Mesafe Ölçer| Fonksiyon| Kart pinleri |
| :---     | :---   |   :---  |
| 3.3V     |3.3V Besleme Gerilimi| 3.3V    |
| GND      | Toprak |GND      |
| SDA      |Çift Yönlü Veri Hattı| SDA pini |
| SCL      |Veri Hattı Zaman Senkronizasyon İşareti| SCL pini|
| INT      | Kesme  |   | 

## Lisans Bilgisi 
Lisans bilgileri için [LICENSE](https://github.com/deneyapkart/deneyap-hareket-isik-renk-algilayici-mesafe-olcer-arduino-library/blob/master/LICENSE) dosyasını inceleyin.