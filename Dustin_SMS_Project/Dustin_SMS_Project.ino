

#include <Bridge.h>
#include <Temboo.h>
#include "TembooAccount.h" // contains Temboo account information
                           // as described in the footer comment below
#define TEMBOO_ACCOUNT "accountNumber"  // your Temboo account name 
#define TEMBOO_APP_KEY_NAME "accontName"  // your Temboo app key name
#define TEMBOO_APP_KEY  "appKey"  // your Temboo app key
int button1 = 11;  // button1 put into pin 11
int button2 = 10;  // button1 put into pin 10
int button3 = 9;  // button1 put into pin 9
int button4 = 8;  // button1 put into pin 8
int button5 = 7;  // button1 put into pin 7
int button6 = 6;  // button1 put into pin 6
int ledRed = 13;  // led put into pin 12
int ledGreen = 12;  // led pit into pin 13
int buttonState1 = 0; 
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;
int buttonState6 = 0;



/*** SUBSTITUTE YOUR VALUES BELOW: ***/

// Note that for additional security and reusability, you could
// use #define statements to specify these values in a .h file.

// the Account SID from your Twilio account
const String TWILIO_ACCOUNT_SID = "youAccountInfoHere";

// the Auth Token from your Twilio account
const String TWILIO_AUTH_TOKEN = "authoTokenHere";

// your Twilio phone number, e.g., "+1 555-222-1212"
const String TWILIO_NUMBER = "+1 ***-***-****";

// the number to which the SMS should be sent, e.g., "+1 555-222-1212"
const String RECIPIENT_NUMBER = "+1 youNumberHere";

// a flag to indicate whether we've attempted to send the SMS yet or not
boolean attempted = false; 
boolean attempted1 = false;
boolean attempted2 = false;
boolean attempted3 = false;
boolean attempted4 = false;
boolean attempted5 = false;

void setup() {
  Serial.begin(9600);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
  pinMode(button6, INPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  
  Serial.print("setUpComplete");

  // for debugging, wait until a serial console is connected
  delay(4000);
  while(!Serial);

  Bridge.begin();
}

void loop()
{
  
  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);
  buttonState3 = digitalRead(button3);
  buttonState4 = digitalRead(button4);
  buttonState5 = digitalRead(button5);
  buttonState6 = digitalRead(button6);
  
  digitalWrite(ledRed, HIGH);
  
   if(buttonState1 == HIGH) {
      Serial.println("Starting SMS 1");
      digitalWrite(ledRed, LOW);
        // only try to send the SMS if we haven't already sent it successfully
        if (attempted = true) {

    Serial.println("Running SendAnSMS...");
    
    // we need a Process object to send a Choreo request to Temboo
    TembooChoreo SendSMSChoreo;
    digitalWrite(ledRed, HIGH);

    // invoke the Temboo client
    // NOTE that the client must be reinvoked and repopulated with
    // appropriate arguments each time its run() method is called.
    SendSMSChoreo.begin();
    
    // set Temboo account credentials
    SendSMSChoreo.setAccountName(TEMBOO_ACCOUNT);
    SendSMSChoreo.setAppKeyName(TEMBOO_APP_KEY_NAME);
    SendSMSChoreo.setAppKey(TEMBOO_APP_KEY);
    digitalWrite(ledRed, LOW);

    // identify the Temboo Library choreo to run (Twilio > SMSMessages > SendSMS)
    SendSMSChoreo.setChoreo("/Library/Twilio/SMSMessages/SendSMS");

    // the first input is a your AccountSID
    SendSMSChoreo.addInput("AccountSID", TWILIO_ACCOUNT_SID);
    
    // next is your Auth Token
    SendSMSChoreo.addInput("AuthToken", TWILIO_AUTH_TOKEN);
 
    // next is your Twilio phone number
    SendSMSChoreo.addInput("From", TWILIO_NUMBER);
    
    // next, what number to send the SMS to
    SendSMSChoreo.addInput("To", RECIPIENT_NUMBER);

    // finally, the text of the message to send
    SendSMSChoreo.addInput("Body", "Message 1");
    digitalWrite(ledRed, HIGH);
    
    // tell the Process to run and wait for the results. The 
    // return code (returnCode) will tell us whether the Temboo client 
    // was able to send our request to the Temboo servers
    unsigned int returnCode = SendSMSChoreo.run();

    // a return code of zero (0) means everything worked
    if (returnCode == 0) {
        Serial.println("Success! SMS sent!");
        digitalWrite(ledRed, LOW);
        digitalWrite(ledGreen, HIGH);
        delay(3500);
        digitalWrite(ledGreen, LOW);
        digitalWrite(ledRed, HIGH);
        buttonState1 = LOW;
        
    } else {
      // a non-zero return code means there was an error
      // read and print the error message
      while (SendSMSChoreo.available()) {
        char c = SendSMSChoreo.read();
        Serial.print(c);
      }
    } 
    SendSMSChoreo.close();
    
    // set the flag indicatine we've tried once.
    attempted=true;
  }
   }
   
    if(buttonState2 == HIGH) {
      Serial.println("Starting SMS 2");
      digitalWrite(ledRed, LOW);
        // only try to send the SMS if we haven't already sent it successfully
        if (attempted1 = true) {

    Serial.println("Running SendAnSMS...");
    
    // we need a Process object to send a Choreo request to Temboo
    TembooChoreo SendSMSChoreo1;
    digitalWrite(ledRed, HIGH);

    // invoke the Temboo client
    // NOTE that the client must be reinvoked and repopulated with
    // appropriate arguments each time its run() method is called.
    SendSMSChoreo1.begin();
    
    // set Temboo account credentials
    SendSMSChoreo1.setAccountName(TEMBOO_ACCOUNT);
    SendSMSChoreo1.setAppKeyName(TEMBOO_APP_KEY_NAME);
    SendSMSChoreo1.setAppKey(TEMBOO_APP_KEY);
    digitalWrite(ledRed, LOW);

    // identify the Temboo Library choreo to run (Twilio > SMSMessages > SendSMS)
    SendSMSChoreo1.setChoreo("/Library/Twilio/SMSMessages/SendSMS");

    // the first input is a your AccountSID
    SendSMSChoreo1.addInput("AccountSID", TWILIO_ACCOUNT_SID);
    
    // next is your Auth Token
    SendSMSChoreo1.addInput("AuthToken", TWILIO_AUTH_TOKEN);
 
    // next is your Twilio phone number
    SendSMSChoreo1.addInput("From", TWILIO_NUMBER);
    
    // next, what number to send the SMS to
    SendSMSChoreo1.addInput("To", RECIPIENT_NUMBER);

    // finally, the text of the message to send
    SendSMSChoreo1.addInput("Body", "Message 2");
    digitalWrite(ledRed, HIGH);
    
    // tell the Process to run and wait for the results. The 
    // return code (returnCode) will tell us whether the Temboo client 
    // was able to send our request to the Temboo servers
    unsigned int returnCode = SendSMSChoreo1.run();

    // a return code of zero (0) means everything worked
    if (returnCode == 0) {
        Serial.println("Success! SMS sent!");
        digitalWrite(ledRed, LOW);
        digitalWrite(ledGreen, HIGH);
        delay(3500);
        digitalWrite(ledGreen, LOW);
        digitalWrite(ledRed, HIGH);
        buttonState2 = LOW;
    } else {
      // a non-zero return code means there was an error
      // read and print the error message
      while (SendSMSChoreo1.available()) {
        char c = SendSMSChoreo1.read();
        Serial.print(c);
      }
    } 
    SendSMSChoreo1.close();
    
    // set the flag indicatine we've tried once.
    attempted1=true;
  }
   }
   
   if(buttonState3 == HIGH) {
      Serial.println("Starting SMS 3");
      digitalWrite(ledRed, LOW);
        // only try to send the SMS if we haven't already sent it successfully
        if (attempted2 = true) {

    Serial.println("Running SendAnSMS...");
    
    // we need a Process object to send a Choreo request to Temboo
    TembooChoreo SendSMSChoreo2;
    digitalWrite(ledRed, HIGH);

    // invoke the Temboo client
    // NOTE that the client must be reinvoked and repopulated with
    // appropriate arguments each time its run() method is called.
    SendSMSChoreo2.begin();
    
    // set Temboo account credentials
    SendSMSChoreo2.setAccountName(TEMBOO_ACCOUNT);
    SendSMSChoreo2.setAppKeyName(TEMBOO_APP_KEY_NAME);
    SendSMSChoreo2.setAppKey(TEMBOO_APP_KEY);
    digitalWrite(ledRed, LOW);

    // identify the Temboo Library choreo to run (Twilio > SMSMessages > SendSMS)
    SendSMSChoreo2.setChoreo("/Library/Twilio/SMSMessages/SendSMS");

    // the first input is a your AccountSID
    SendSMSChoreo2.addInput("AccountSID", TWILIO_ACCOUNT_SID);
    
    // next is your Auth Token
    SendSMSChoreo2.addInput("AuthToken", TWILIO_AUTH_TOKEN);
 
    // next is your Twilio phone number
    SendSMSChoreo2.addInput("From", TWILIO_NUMBER);
    
    // next, what number to send the SMS to
    SendSMSChoreo2.addInput("To", RECIPIENT_NUMBER);

    // finally, the text of the message to send
    SendSMSChoreo2.addInput("Body", "Message 3");
    digitalWrite(ledRed, HIGH);
    
    // tell the Process to run and wait for the results. The 
    // return code (returnCode) will tell us whether the Temboo client 
    // was able to send our request to the Temboo servers
    unsigned int returnCode = SendSMSChoreo2.run();

    // a return code of zero (0) means everything worked
    if (returnCode == 0) {
        Serial.println("Success! SMS sent!");
        digitalWrite(ledRed, LOW);
        digitalWrite(ledGreen, HIGH);
        delay(3500);
        digitalWrite(ledGreen, LOW);
        digitalWrite(ledRed, HIGH);
        buttonState3 = LOW;
    } else {
      // a non-zero return code means there was an error
      // read and print the error message
      while (SendSMSChoreo2.available()) {
        char c = SendSMSChoreo2.read();
        Serial.print(c);
      }
    } 
    SendSMSChoreo2.close();
    
    // set the flag indicatine we've tried once.
    attempted2=true;
  }
   }
   
   if(buttonState4 == HIGH) {
      Serial.println("Starting SMS 4");
      digitalWrite(ledRed, LOW);
        // only try to send the SMS if we haven't already sent it successfully
        if (attempted3 = true) {

    Serial.println("Running SendAnSMS...");
    
    // we need a Process object to send a Choreo request to Temboo
    TembooChoreo SendSMSChoreo3;
    digitalWrite(ledRed, HIGH);

    // invoke the Temboo client
    // NOTE that the client must be reinvoked and repopulated with
    // appropriate arguments each time its run() method is called.
    SendSMSChoreo3.begin();
    
    // set Temboo account credentials
    SendSMSChoreo3.setAccountName(TEMBOO_ACCOUNT);
    SendSMSChoreo3.setAppKeyName(TEMBOO_APP_KEY_NAME);
    SendSMSChoreo3.setAppKey(TEMBOO_APP_KEY);
    digitalWrite(ledRed, LOW);

    // identify the Temboo Library choreo to run (Twilio > SMSMessages > SendSMS)
    SendSMSChoreo3.setChoreo("/Library/Twilio/SMSMessages/SendSMS");

    // the first input is a your AccountSID
    SendSMSChoreo3.addInput("AccountSID", TWILIO_ACCOUNT_SID);
    
    // next is your Auth Token
    SendSMSChoreo3.addInput("AuthToken", TWILIO_AUTH_TOKEN);
 
    // next is your Twilio phone number
    SendSMSChoreo3.addInput("From", TWILIO_NUMBER);
    
    // next, what number to send the SMS to
    SendSMSChoreo3.addInput("To", RECIPIENT_NUMBER);

    // finally, the text of the message to send
    SendSMSChoreo3.addInput("Body", "Message 4");
    digitalWrite(ledRed, HIGH);
    
    // tell the Process to run and wait for the results. The 
    // return code (returnCode) will tell us whether the Temboo client 
    // was able to send our request to the Temboo servers
    unsigned int returnCode = SendSMSChoreo3.run();

    // a return code of zero (0) means everything worked
    if (returnCode == 0) {
        Serial.println("Success! SMS sent!");
        digitalWrite(ledRed, LOW);
        digitalWrite(ledGreen, HIGH);
        delay(3500);
        digitalWrite(ledGreen, LOW);
        digitalWrite(ledRed, HIGH);
        buttonState4 = LOW;
    } else {
      // a non-zero return code means there was an error
      // read and print the error message
      while (SendSMSChoreo3.available()) {
        char c = SendSMSChoreo3.read();
        Serial.print(c);
      }
    } 
    SendSMSChoreo3.close();
    
    // set the flag indicatine we've tried once.
    attempted3=true;
  }
   }
   
   if(buttonState5 == HIGH) {
      Serial.println("Starting SMS 5");
      digitalWrite(ledRed, LOW);
        // only try to send the SMS if we haven't already sent it successfully
        if (attempted4 = true) {

    Serial.println("Running SendAnSMS...");
    
    // we need a Process object to send a Choreo request to Temboo
    TembooChoreo SendSMSChoreo4;
    digitalWrite(ledRed, HIGH);

    // invoke the Temboo client
    // NOTE that the client must be reinvoked and repopulated with
    // appropriate arguments each time its run() method is called.
    SendSMSChoreo4.begin();
    
    // set Temboo account credentials
    SendSMSChoreo4.setAccountName(TEMBOO_ACCOUNT);
    SendSMSChoreo4.setAppKeyName(TEMBOO_APP_KEY_NAME);
    SendSMSChoreo4.setAppKey(TEMBOO_APP_KEY);
    digitalWrite(ledRed, LOW);

    // identify the Temboo Library choreo to run (Twilio > SMSMessages > SendSMS)
    SendSMSChoreo4.setChoreo("/Library/Twilio/SMSMessages/SendSMS");

    // the first input is a your AccountSID
    SendSMSChoreo4.addInput("AccountSID", TWILIO_ACCOUNT_SID);
    
    // next is your Auth Token
    SendSMSChoreo4.addInput("AuthToken", TWILIO_AUTH_TOKEN);
 
    // next is your Twilio phone number
    SendSMSChoreo4.addInput("From", TWILIO_NUMBER);
    
    // next, what number to send the SMS to
    SendSMSChoreo4.addInput("To", RECIPIENT_NUMBER);

    // finally, the text of the message to send
    SendSMSChoreo4.addInput("Body", "Message 5");
    digitalWrite(ledRed, HIGH);
    
    // tell the Process to run and wait for the results. The 
    // return code (returnCode) will tell us whether the Temboo client 
    // was able to send our request to the Temboo servers
    unsigned int returnCode = SendSMSChoreo4.run();

    // a return code of zero (0) means everything worked
    if (returnCode == 0) {
        Serial.println("Success! SMS sent!");
        digitalWrite(ledRed, LOW);
        digitalWrite(ledGreen, HIGH);
        delay(3500);
        digitalWrite(ledGreen, LOW);
        digitalWrite(ledRed, HIGH);
        buttonState5 = LOW;
    } else {
      // a non-zero return code means there was an error
      // read and print the error message
      while (SendSMSChoreo4.available()) {
        char c = SendSMSChoreo4.read();
        Serial.print(c);
      }
    } 
    SendSMSChoreo4.close();
    
    // set the flag indicatine we've tried once.
    attempted4=true;
  }
   }
   
   if(buttonState6 == HIGH) {
      Serial.println("Starting SMS 6");
      digitalWrite(ledRed, LOW);
        // only try to send the SMS if we haven't already sent it successfully
        if (attempted5 = true) {

    Serial.println("Running SendAnSMS...");
    
    // we need a Process object to send a Choreo request to Temboo
    TembooChoreo SendSMSChoreo5;
    digitalWrite(ledRed, HIGH);

    // invoke the Temboo client
    // NOTE that the client must be reinvoked and repopulated with
    // appropriate arguments each time its run() method is called.
    SendSMSChoreo5.begin();
    
    // set Temboo account credentials
    SendSMSChoreo5.setAccountName(TEMBOO_ACCOUNT);
    SendSMSChoreo5.setAppKeyName(TEMBOO_APP_KEY_NAME);
    SendSMSChoreo5.setAppKey(TEMBOO_APP_KEY);
    digitalWrite(ledRed, LOW);

    // identify the Temboo Library choreo to run (Twilio > SMSMessages > SendSMS)
    SendSMSChoreo5.setChoreo("/Library/Twilio/SMSMessages/SendSMS");

    // the first input is a your AccountSID
    SendSMSChoreo5.addInput("AccountSID", TWILIO_ACCOUNT_SID);
    
    // next is your Auth Token
    SendSMSChoreo5.addInput("AuthToken", TWILIO_AUTH_TOKEN);
 
    // next is your Twilio phone number
    SendSMSChoreo5.addInput("From", TWILIO_NUMBER);
    
    // next, what number to send the SMS to
    SendSMSChoreo5.addInput("To", RECIPIENT_NUMBER);

    // finally, the text of the message to send
    SendSMSChoreo5.addInput("Body", "Message 6");
    digitalWrite(ledRed, HIGH);
    
    // tell the Process to run and wait for the results. The 
    // return code (returnCode) will tell us whether the Temboo client 
    // was able to send our request to the Temboo servers
    unsigned int returnCode = SendSMSChoreo5.run();

    // a return code of zero (0) means everything worked
    if (returnCode == 0) {
        Serial.println("Success! SMS sent!");
        digitalWrite(ledRed, LOW);
        digitalWrite(ledGreen, HIGH);
        delay(3500);
        digitalWrite(ledGreen, LOW);
        digitalWrite(ledRed, HIGH);
        buttonState6 = LOW;
    } else {
      // a non-zero return code means there was an error
      // read and print the error message
      while (SendSMSChoreo5.available()) {
        char c = SendSMSChoreo5.read();
        Serial.print(c);
      }
    } 
    SendSMSChoreo5.close();
    
    // set the flag indicatine we've tried once.
    attempted5=true;
  }
   }
}

