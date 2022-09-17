#include <Arduino.h>
#include <Servo.h>

// #include <WiFi.h>
// #include <Firebase_ESP_Client.h>
// // Provide the token generation process info.
// #include "addons/TokenHelper.h"
// // Provide the RTDB payload printing info and other helper functions.
// #include "addons/RTDBHelper.h"

// // Insert your network credentials
// #define WIFI_SSID "Computer Lab"
// #define WIFI_PASSWORD "2020_2024"

// // Insert Firebase project API Key
// #define API_KEY "AIzaSyDg4s787iggM3YUxvnrdDpkh1f_4fEpWPs"

// // Insert RTDB URLefine the RTDB URL */
// #define DATABASE_URL "https://canteenvending-d71be-default-rtdb.asia-southeast1.firebasedatabase.app/"

// // Define Firebase Data object
// FirebaseData fbdo;

// FirebaseAuth auth;
// FirebaseConfig config;

static const int servoPin1 = 22;
static const int servoPin2 = 23;

const int buttonPin = 40;
const int bled = 53;
const int sled = 52;
int buttonState = 0;
Servo servo1;
Servo servo2;
// int balance;
// int price;
// int stock;
// float floatValue;
// bool signupOK = false;

void pin_setup()
{
  pinMode(buttonPin, INPUT);
  pinMode(servoPin1, OUTPUT);
  pinMode(servoPin2, OUTPUT);
  pinMode(bled, OUTPUT);
  pinMode(sled, OUTPUT);
}

// void firebase_setup()
// {
//   /* Assign the api key (required) */
//   config.api_key = API_KEY;

//   /* Assign the RTDB URL (required) */
//   config.database_url = DATABASE_URL;

//   /* Sign up */
//   if (Firebase.signUp(&config, &auth, "", ""))
//   {
//     Serial.println("ok");
//     signupOK = true;
//   }
//   else
//   {
//     Serial.printf("%s\n", config.signer.signupError.message.c_str());
//   }

//   /* Assign the callback function for the long running token generation task */
//   config.token_status_callback = tokenStatusCallback; // see addons/TokenHelper.h

//   Firebase.begin(&config, &auth);
//   Firebase.reconnectWiFi(true);
// }

// void connect_wifi()
// {
//   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
//   Serial.println("Connecting to Wi-Fi");
//   while (WiFi.status() != WL_CONNECTED)
//   {
//     Serial.print(".");
//     delay(300);
//   }
//   Serial.print("Connected with IP: ");
//   Serial.println(WiFi.localIP());
//   Serial.println();
// }

void init_servo()
{
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo1.write(0);
  servo2.write(0);
}

void setup()
{
  // Start serial monitor
  Serial.begin(9600);

  // Initialize servo objects
  init_servo();

  // Initialize pins
  pin_setup();

  // Connect to wifi
  // connect_wifi();

  // Initialize firebase
  // firebase_setup();
}

// bool running = false;

void loop()
{

  String msg = Serial.readString();
  if (msg == "connected")
  {
    digitalWrite(bled, HIGH);
  }
  else
  {
    digitalWrite(bled, LOW);
  }
  Serial.println(msg);

  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH)
  {
    Serial.print("get_balance");
    while(msg != "number"){
      msg = Serial.readString();
    }
    
  }

  // if (Firebase.ready() && signupOK && buttonState == 1 && !running)
  // {
  //   running = true;

  //   if (Firebase.RTDB.getInt(&fbdo, "cadets/2129/balance"))
  //   {

  //     balance = fbdo.intData();
  //     Serial.println("Balance: ");
  //     Serial.println(balance);

  //     if (Firebase.RTDB.getInt(&fbdo, "products/lacchi/price"))
  //     {

  //       price = fbdo.intData();
  //       Serial.println("Price: ");
  //       Serial.println(price);

  //       if (balance > price)
  //       {

  //         if (Firebase.RTDB.getInt(&fbdo, "products/lacchi/quantity"))
  //         {

  //           stock = fbdo.intData();
  //           Serial.println("Stock: ");
  //           Serial.println(stock);
  //           if (stock > 0)
  //           {

  //             if (Firebase.RTDB.setInt(&fbdo, "cadets/2129/balance", balance - price))
  //             {
  //               Serial.println("Value Set Successfully\n ");
  //               Serial.println("PATH: " + fbdo.dataPath());
  //               Serial.println("TYPE: " + fbdo.dataType());
  //             }
  //             if (Firebase.RTDB.setInt(&fbdo, "products/lacchi/quantity", stock - 1))
  //             {
  //               Serial.println("Stock updated Successfully\n ");
  //               Serial.println("PATH: " + fbdo.dataPath());
  //               Serial.println("TYPE: " + fbdo.dataType());
  //             }

  //             else
  //             {
  //               Serial.println(fbdo.errorReason());
  //             }

  //             for (int posDegrees = 0; posDegrees <= 60; posDegrees++)
  //             {

  //               servo1.write(posDegrees);
  //               // Serial.println(posDegrees);
  //               delay(15);
  //             }

  //             delay(1000);

  //             for (int posDegrees = 60; posDegrees >= 0; posDegrees--)
  //             {
  //               servo1.write(posDegrees);
  //               // Serial.println(posDegrees);
  //               delay(15);
  //             }

  //             delay(150);

  //             for (int posDegrees = 0; posDegrees <= 90; posDegrees++)
  //             {
  //               servo2.write(posDegrees);
  //               // Serial.println(posDegrees);
  //               delay(15);
  //             }

  //             delay(1000);

  //             for (int posDegrees = 90; posDegrees >= 0; posDegrees--)
  //             {
  //               servo2.write(posDegrees);
  //               Serial.println(posDegrees);
  //               delay(15);
  //             }

  //             delay(20);
  //           }

  //           else
  //           {
  //             digitalWrite(sled, HIGH);
  //             delay(2000);
  //             digitalWrite(sled, LOW);
  //           }
  //         }
  //       }

  //       else
  //       {
  //         digitalWrite(bled, HIGH);
  //         delay(2000);
  //         digitalWrite(bled, LOW);
  //       }
  //     }
  //   }

  //   running = false;
  // }
  // else if (!Firebase.ready())
  // {

  //   Serial.println("Error: ");
  //   Serial.println(fbdo.errorReason());
  // }
}