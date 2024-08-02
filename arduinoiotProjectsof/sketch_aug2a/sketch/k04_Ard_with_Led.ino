#define LedPin D2

bool LedIsOn;
void LED_setup() {
  pinMode(LedPin,OUTPUT);
  Led_Off();
  WifiSetup();
}

void LED_loop() {
  wifi_loop();
}

void ToggleLed(){
  if(LedIsOn){
    Led_Off();
  } else {
    Led_On();
  }
}
void Led_Off(){
  digitalWrite(LedPin,LOW);
  LedIsOn=false;
}
void Led_On(){
  digitalWrite(LedPin,HIGH);
  LedIsOn=true;
}
