/*
 * wifi_app.h
 *
 *  Created on: 17 ���. 2023 �.
 *      Author: Phong
 */

#ifndef MAIN_WIFI_APP_H_
#define MAIN_WIFI_APP_H_

#include "esp_netif.h"
#include "esp_wifi_types.h"
#include "freertos/FreeRTOS.h"

// Wifi application settings
#define WIFI_AP_SSID "ESP32_AP"         // AP Name
#define WIFI_AP_PASSWORD "password"      // Ap Password
#define WIFI_AP_CHANNEL 1                // AP Channel
#define WIFI_AP_SSID_HIDDEN 0            // AP visivility
#define WIFI_AP_MAX_CONNECTIONS 5        // AP max clients connections
#define WIFI_AP_BEACON_INTERVAL 100      // AP beacon: 100 ms recommended default value
#define WIFI_AP_IP "192.168.0.1"         // AP defaule IP address
#define WIFI_AP_GATEWAY "192.168.0.1"    // AP defaule Gateway (should be then same as the IP)
#define WIFI_AP_NETMASK "255.255.255.0"  // AP netmask
#define WIFI_AP_BANDWIDTH WIFI_BW_HT20   // AP bandwith 20 MHz (40 MHz is the other option )
#define WIFI_STA_POWER_SAVE WIFI_PS_NONE // AP none power save
#define MAX_SSID_LENGTH 32               // IEEE standard maximum SSID length
#define MAX_PASSWORD_LENGTH 64           // IEEE standard maximum password length
#define MAX_CONNECTIONS_RETRIES 5        // Retry number disconnect

// netif object for the Station and Acess Point
extern esp_netif_t *esp_netif_sta;
extern esp_netif_t *esp_netif_ap;

/**
 * Message IDs for the Wifi application task
 * @note Expand this based on your application requirements
 *
 */
typedef enum wifi_app_message
{
    WIFI_APP_MSG_START_HTTP_SERVER = 0,
    WIFI_APP_MSG_CONNECTING_FROM_HTTP_SERVER,
    WIFI_APP_MSG_STA_CONNECTED_GOT_IP
} wifi_app_message_e;

/**
 * Structure for the message queue
 * @note Expand this based on your application requirements e.g. add other type and parameters as required
 */

typedef struct wifi_app_queue_message
{
    wifi_app_message_e msgID;
} wifi_app_queue_message_t;

/**
 * Sends a message to the queue
 * @param msgID message ID from the wifi_app_message_e enum.
 * @return pdTRUE if an item was successfully sent to the queue, pdFALSE otherwise.
 * @note Expand this parameter list based on your application requirements e.g. how you've expanded the wifi_app_queue_message_t.
 */
BaseType_t wifi_app_send_message(wifi_app_message_e msgID);

/**
 * Starts the WiFi RTOS task
 */
void wifi_app_start(void);

#endif /* MAIN_WIFI_APP_H_ */