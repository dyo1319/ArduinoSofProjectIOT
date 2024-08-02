#define SETTING_PIN D3

void setup() {
 pinMode(SETTING_PIN,INPUT_PULLUP);
  btn_setup();
}

void loop() {

  btn_loop();
}