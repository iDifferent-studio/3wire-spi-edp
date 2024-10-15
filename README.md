# 3 Wire (or 9 bit) SPI e-ink display dirver
This is a e-ink display dirver for Arduino, has been tested on ESP32-C3's HWSPI driving 2.9 inch Waveshare e-ink display.

Hardware wiring:

ESP32 C3          E-ink diaplay

GPIO 10   ------  RST

GPIO 5    ------  CS

GPIO 21   ------  BUSY

GPIO 7    ------  DATA

GPIO 6    ------  CLK

Other PINs on E-ink diaplay leave float.
