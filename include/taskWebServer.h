#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <Update.h>
#include <esp_wifi.h>

#ifndef TASK_WEBSERVER
#define TASK_WEBSERVER

#ifdef HAS_SX127X
  #include <BG_RF95.h>
  extern BG_RF95 rf95;
#elif HAS_SX126X
  #include <RadioLib.h>
  #if defined(HELTEC_WIRELESS_TRACKER)
    extern SX1262 radio;
  #elif HAS_SX1268
    extern SX1268 radio;
  #endif
#endif

#ifdef KISS_PROTOCOL
  extern WiFiServer tncServer;
#endif
extern WiFiServer gpsServer;
typedef struct {
  String callsign;
} tWebServerCfg;

typedef struct {
  struct tm rxTime;
  String *packet;
  int RSSI;
  int SNR;
} tReceivedPacketData;

extern QueueHandle_t webListReceivedQueue;

// structure for AP Array
struct AccessPoint {
    char ssid[33];
    char pw[64];
    //uint8_t prio;
};

[[noreturn]] void taskWebServer(void *parameter);
#endif
