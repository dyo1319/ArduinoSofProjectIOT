#define LED_R D5
#define BTN_R D6

int lastBtnVal_R;
unsigned long lastBtnReleaseTime_R;
unsigned long lastBtnPressTime_R;
int debounceTime = 50;
unsigned long pressStartTime = 0;
unsigned long pressDuration = 0;

void btn_setup() {
    pinMode(LED_R, OUTPUT);
    pinMode(BTN_R, INPUT_PULLUP);
    lastBtnVal_R = digitalRead(BTN_R);
    lastBtnReleaseTime_R = millis();
    Serial.begin(9600);
    wifiClient_Setup();
}

void btn_loop() {
    int btnCurrVal = digitalRead(BTN_R);
    measurePressDuration(btnCurrVal);
    if ((btnCurrVal == HIGH) && (lastBtnVal_R == LOW) && (millis() - lastBtnReleaseTime_R > debounceTime)) {
        lastBtnReleaseTime_R = millis();
        SendBtnPressed();
    }
    lastBtnVal_R = btnCurrVal;
}

void measurePressDuration(int btnCurrVal) {
    if (btnCurrVal == LOW) {
        if (pressStartTime == 0) {
            pressStartTime = millis();
        }
    } else {
        if (pressStartTime != 0) {
            pressDuration = millis() - pressStartTime; 
            Serial.print("Press duration: ");
            Serial.print(pressDuration);
            Serial.println(" milliseconds");
            pressStartTime = 0; 
        }
    }
}