/*######################## MAIN CONFIG ########################*/
#define LED_TYPE            WS2812B                     // You might also use a WS2811 or any other strip that is Fastled compatible 
#define DATA_PIN            D3                          // Be aware: the pin mapping might be different on boards like the NodeMCU
//#define CLK_PIN             D5                        // Only required when using 4-pin SPI-based LEDs
#define CORRECTION          UncorrectedColor            // If colors are weird use TypicalLEDStrip
#define COLOR_ORDER         GRB                         // Change this if colors are swapped (in my case, red was swapped with green)
#define MILLI_AMPS          4000                       // IMPORTANT: set the max milli-Amps of your power supply (4A = 4000mA)
#define VOLTS               5                           // Voltage of the Power Supply

//#define REMOVE_VISUALIZATION          // remove the comment to completly disable all udp-based visualization patterns

#define HOSTNAME "MillysNanoLeaf"                 // Name that appears in your network, don't use whitespaces, use "-" instead

#define DEVICE_TYPE 4                   // The following types are available
/*
    0: Generic LED-Strip: a regular LED-Strip without any special arrangement (and Infinity Mirror + Bottle Lighting Pad)
        * Easiest: 5V WS2812B LED-Strip:            https://s.click.aliexpress.com/e/_dZ1hCJ7
        * (Long Ranges) 12V WS2811 LED-Strip:       https://s.click.aliexpress.com/e/_d7Ehe3L
        * (High-Speed) 5V SK9822 LED-Strip:         https://s.click.aliexpress.com/e/_d8pzc89
        * (Expensive) 5V APA102 LED-Strip:          https://s.click.aliexpress.com/e/_Bf9wVZUD
        * (Flexible) 5V WS2812 S LED-Strip:         https://s.click.aliexpress.com/e/_d6XxPOH
        * Wemos D1 Mini:                            https://s.click.aliexpress.com/e/_dTVGMGl
        * 5V Power Supply:                          https://s.click.aliexpress.com/e/_dY5zCWt
        * Solderless LED-Connector:                 https://s.click.aliexpress.com/e/_dV4rsjF
        * 3D-Printed Wemos-D1 case:                 https://www.thingiverse.com/thing:3544576
    1: LED-Matrix: With a flexible LED-Matrix you can display the audio like a Audio Visualizer
        * Flexible WS2812 Matrix:                   https://s.click.aliexpress.com/e/_d84R5kp
        * Wemos D1 Mini:                            https://s.click.aliexpress.com/e/_dTVGMGl
        * 5V Power Supply:                          https://s.click.aliexpress.com/e/_dY5zCWt
    2: 3D-Printed 7-Segment Clock, display the time in a cool 7-segment style, syncs with a ntp of your choice
        * unfortunatly the "thing's" description isn't updated yet to the new standalone system
        * Project link, small version:              https://www.thingiverse.com/thing:3117494
        * Project link, large version:              https://www.thingiverse.com/thing:2968056
    3: 3D-Printed Desk Lamp, a Lamp that reacts to sound for your desk
        * Project link, twisted version:            https://www.thingiverse.com/thing:4129249
        * Project link, round version:              https://www.thingiverse.com/thing:3676533
    4: 3D-Printed Nanoleafs, a Nanoleaf clone that can be made for cheap
        * Project link:                             https://www.thingiverse.com/thing:3354082
    5: 3D-Printed Animated RGB Logos
        * Project link, Twenty-One-Pilots:          https://www.thingiverse.com/thing:3523487
        * Project link, Thingiverse:                https://www.thingiverse.com/thing:3531086
*/

//---------------------------------------------------------------------------------------------------------//
// Device Configuration:
//---------------------------------------------------------------------------------------------------------//
#if DEVICE_TYPE == 0                // Generic LED-Strip
    #define NUM_LEDS 24
    //#define NUM_LEDS 33
    //#define NUM_LEDS 183
    #define BAND_GROUPING    1            // Groups part of the band to save performance and network traffic
#elif DEVICE_TYPE == 1              // LED MATRIX
    #define LENGTH 32
    #define HEIGHT 8
    //#define AddLogoVisualizers          // (only 32x8) Adds Visualization patterns with logo (currently only HBz)
#elif DEVICE_TYPE == 2              // 7-Segment Clock
    #define NTP_REFRESH_INTERVAL_SECONDS 600            // 10 minutes
    const char* ntpServerName = "at.pool.ntp.org";      // Austrian ntp-timeserver
    int t_offset = 0;                                   // offset added to the time from the ntp server
    const int NTP_PACKET_SIZE = 48;
    #define NUM_LEDS 30
    #define Digit1 0
    #define Digit2 7
    #define Digit3 16
    #define Digit4 23
    // Values for the Big Clock: 58, 0, 14, 30, 44

#elif DEVICE_TYPE == 3              // Desk Lamp
    #define LINE_COUNT    8             // Amount of led strip pieces
    #define LEDS_PER_LINE 10            // Amount of led pixel per single led strip piece

#elif DEVICE_TYPE == 4              // Nanoleafs
    #define LEAFCOUNT 12                // Amount of triangles
    #define PIXELS_PER_LEAF 12          // Amount of LEDs inside 1x Tringle

#elif DEVICE_TYPE == 5              // Animated Logos
    // Choose your logo below, remove the comment in front of your design
    // Important: see "LOGO CONFIG" below

    //#define TWENTYONEPILOTS
    #define THINGIVERSE

#endif

//---------------------------------------------------------------------------------------------------------//
// Feature Configuration: Enabled by removing the "//" in front of the define statements
//---------------------------------------------------------------------------------------------------------//
    //#define ACCESS_POINT_MODE                 // the esp8266 will create a wifi-access point instead of connecting to one, credentials must be in Secrets.h

    #define ENABLE_OTA_SUPPORT                // requires ArduinoOTA - library, not working on esp's with 1MB memory (esp-01, Wemos D1 lite ...)
    #define OTA_PASSWORD "1123581321"      //  password that is required to update the esp's firmware wireless

    #define ENABLE_MULTICAST_DNS              // allows to access the UI via "http://<HOSTNAME>.local/", implemented by GitHub/WarDrake

    #define RANDOM_AUTOPLAY_PATTERN             // if enabled the next pattern for autoplay is choosen at random
    #define AUTOPLAY_IGNORE_UDP_PATTERNS        // remove visualization patterns from autoplay

    #define ENABLE_ALEXA_SUPPORT              // Espalexa library required

    //#define SOUND_SENSOR_SUPPORT              // allows to control the leds using a physical sound-sensor, configuration below

    //#define ENABLE_SERIAL_AMBILIGHT           // allows to function as an ambilight behind a monitor by using data from usb-serial (integration of adalight)

    //#define ENABLE_MQTT_SUPPORT               // allows integration in homeassistant/googlehome/mqtt, 
                                                // mqtt server required, see MQTT Configuration for more, implemented by GitHub/WarDrake

//---------------------------------------------------------------------------------------------------------//


/*############ Alexa Configuration ############*/
/* This part configures the devices that can be detected,
 * by your Amazon Alexa device. In order to Connect the device,
 * open http://ip_of_the_esp8266/alexa in your browser. Or click
 * the alexa button in the navbar.
 * Afterwards tell say "Alexa, discover devices" to your device,
 * after around 30 seconds it should respond with the new devices
 * it has detected.
 *
 * In order to be able to control mutliple parameters of the strip,
 * the code must create multiple alexa devices. However you can
 * use
 *
 * To add those extra devices remove the two "//" in front of the,
 * defines below.
 *
 * The Devices with specific pattern, require the corresponding SpecificPatternX 
 * statement, as argument you have to provide the zero-based index of the `patterns`
 * array below. (Hint: CTRL + F -> "patterns =")
 * 
 */
#ifdef ENABLE_ALEXA_SUPPORT
    #define ALEXA_DEVICE_NAME               "Milly's Nano Leaf"
    //#define AddAutoplayDevice             ((String)HOSTNAME + (String)" Autoplay")
    //#define AddStrobeDevice               ((String)HOSTNAME + (String)" Strobe")
    //#define AddSpecificPatternDeviceA     ((String)HOSTNAME + (String)" Party")
    //#define AddSpecificPatternDeviceB     ((String)HOSTNAME + (String)" Chill")
    //#define AddSpecificPatternDeviceC     ((String)HOSTNAME + (String)" Rainbow")
    //#define AddAudioDevice                ((String)HOSTNAME + (String)" Audio")
    //#define SpecificPatternA 37           // Parameter defines what pattern gets executed
    //#define SpecificPatternB 12           // Parameter defines what pattern gets executed
    //#define SpecificPatternC 0            // Parameter defines what pattern gets executed
    //#define AudioPattern 44               // Parameter defines what pattern gets executed

#endif // ENABLE_ALEXA_SUPPORT
/*########## Alexa Configuration END ##########*/



/*######################## ANIMATED RGB LOGO CONFIG ########################*/

#ifdef TWENTYONEPILOTS
    #define RING_LENGTH 24                                      // amount of pixels for the Ring (should be 24)
    #define DOUBLE_STRIP_LENGTH 2                               // amount of pixels used for the straight double line
    #define DOT_LENGTH 1                                        // amount of pixels used for the dot
    #define ITALIC_STRIP_LENGTH 2                               // amount of pixels used for the 
    #define ANIMATION_NAME "Twenty One Pilots - Animated"       // name for the Logo animation, displayed on the webserver
    #define ANIMATION_NAME_STATIC "Twenty One Pilots - Static"  // logo for the static logo, displayed on the webserver
    #define ANIMATION_RING_DURATION 30                          // longer values result into a longer loop duration
    #define STATIC_RING_COLOR CRGB(222,255,5)                   // Color for the outer ring in static mode
    #define STATIC_LOGO_COLOR CRGB(150,240,3)                   // Color for the inner logo in static mode
/*
Wiring order:
The array below will determine the order of the wiring,
  the first value is for the ring, I've hooked it up after the inner part,
  so it's the start value is the total length of all other pixels (2+1+2)
the second one is for the vertical double line
  in my case it was the first one that is connected to the esp8266,
the third one is for the dot and the fourth one for the angled double line
if you have connected the ring first it should look like this: const int twpOffsets[] = { 0,24,26,27 };
*/
// Syntax: { <RING>, <VERTICAL>, <HORIZONTAL_DOT>, <ANGLED> };
// The values represent the zero-based index on the strip of the element
    const int twpOffsets[] = { 5,0,2,3 };
#endif  // TWENTYONEPILOTS

#ifdef THINGIVERSE
    #define RING_LENGTH 24                                  // amount of pixels for the Ring (should be 24)
    #define HORIZONTAL_LENGTH 3                             // amount of pixels used for the straight double line
    #define VERTICAL_LENGTH 2                               // amount of pixels used for the straight double line
    #define ANIMATION_NAME "Thingiverse - Animated"         // name for the Logo animation, displayed on the webserver
    #define ANIMATION_NAME_STATIC "Thingiverse - Static"    // logo for the static logo, displayed on the webserver
    #define ANIMATION_RING_DURATION 30                      // longer values result into a longer loop duration
    #define STATIC_RING_COLOR CRGB(0,149,255)               // Color for the outer ring in static mode
    #define STATIC_LOGO_COLOR CRGB(0,149,255)               // Color for the inner logo in static mode
    #define RINGFIRST false                                 // change this to <true> if you have wired the ring first
    #define HORIZONTAL_BEFORE_VERTICAL true                 // change this to <true> if you have wired the horizontal strip before the vertical
#endif  // THINGIVERSE

/*###################### ANIMATED RGB LOGO CONFIG END ######################*/

/*-------- SOUND SENSOR (LEGACY) --------*/
#ifdef SOUND_SENSOR_SUPPORT
    #define SOUND_SENSOR_PIN A0       // An Analog sensor should be connected to an analog pin
    #define SENSOR_TYPE 1             // 0: Dumb Sensors, 1: MAX4466 Sound Sensor, 2: MAX9814 Sound Sensor
    // Values for MAX44666:
    int16_t audioMinVol = 135;        // minimal Voltage from Mic, higher Value = less sensitive
    int16_t audioMaxVol = 145;        // maximal Voltage from Mic, lower Value = more LED on with lower Volume
#endif
/*------ SOUND SENSOR (LEGACY) END ------*/


/*######################## MQTT Configuration ########################*/
#ifdef ENABLE_MQTT_SUPPORT
    const char* mqttServer = "homeassistant.local";
    const int mqttPort = 1883;
    #if DEVICE_TYPE == 0
        #define MQTT_TOPIC "homeassistant/light/ledstrip"               // MQTT Topic to Publish to for state and config (Home Assistant)
        #define MQTT_TOPIC_SET "/set"                                   // MQTT Topic to subscribe to for changes(Home Assistant)
        #define MQTT_DEVICE_NAME "Ledstrip"
    #elif DEVICE_TYPE == 1
        #define MQTT_TOPIC "homeassistant/light/ledmatrix"              // MQTT Topic to Publish to for state and config (Home Assistant)
        #define MQTT_TOPIC_SET "/set"                                   // MQTT Topic to subscribe to for changes(Home Assistant)
        #define MQTT_DEVICE_NAME "Led Matrix"
    #elif DEVICE_TYPE == 2
        #define MQTT_TOPIC "homeassistant/light/7-segment-clock"        // MQTT Topic to Publish to for state and config (Home Assistant)
        #define MQTT_TOPIC_SET "/set"                                   // MQTT Topic to subscribe to for changes(Home Assistant)
        #define MQTT_DEVICE_NAME "7 Segment Clock"
    #elif DEVICE_TYPE == 3
        #define MQTT_TOPIC "homeassistant/light/desklamp"               // MQTT Topic to Publish to for state and config (Home Assistant)
        #define MQTT_TOPIC_SET "/set"                                   // MQTT Topic to subscribe to for changes(Home Assistant)
        #define MQTT_DEVICE_NAME "Led Desk Lamp"
    #elif DEVICE_TYPE == 4
        #define MQTT_TOPIC "homeassistant/light/nanoleafs"              // MQTT Topic to Publish to for state and config (Home Assistant)
        #define MQTT_TOPIC_SET "/set"                                   // MQTT Topic to subscribe to for changes(Home Assistant)
        #define MQTT_DEVICE_NAME "Nanoleafs"
    #elif DEVICE_TYPE == 5
        #define MQTT_TOPIC "homeassistant/light/ledlogo"                // MQTT Topic to Publish to for state and config (Home Assistant)
        #define MQTT_TOPIC_SET "/set"                                   // MQTT Topic to subscribe to for changes(Home Assistant)
        #define MQTT_DEVICE_NAME "Animated Logo"
    #endif
    #define MQTT_UNIQUE_IDENTIFIER WiFi.macAddress()                    // A Unique Identifier for the device in Homeassistant (MAC Address used by default)
    #define MQTT_MAX_PACKET_SIZE 512
    #define MQTT_MAX_TRANSFER_SIZE 512
    // For the user / password check the Secrets.h file and modify your settings in there.
    // const char* mqttUser = "YourMqttUser";
    // const char* mqttPassword = "YourMqttUserPassword";

    #include <PubSubClient.h>                                           // Include the MQTT Library, must be installed via the library manager
    #include <ArduinoJson.h> 
    WiFiClient espClient;
    PubSubClient mqttClient(espClient);
#endif
/*###################### MQTT Configuration END ######################*/

/*#########################################################################################################//
-----------------------------------------------------------------------------------------------------------//
  _____ ____   _  __ ____ ____ _____    ____ _  __ ___ 
 / ___// __ \ / |/ // __//  _// ___/   / __// |/ // _ \
/ /__ / /_/ //    // _/ _/ / / (_ /   / _/ /    // // /
\___/ \____//_/|_//_/  /___/ \___/   /___//_/|_//____/ 
-----------------------------------------------------------------------------------------------------------//
###########################################################################################################*/
