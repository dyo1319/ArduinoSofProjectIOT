 //#define LED_G D3
	#define LED_R D5
	#define BTN_R D6
	//#define BTN_G D4
	
	bool R_LedIsOn = true;
	
	int lastBtnVal_R;
	unsigned long lastBtnReleaseTime_R;
	int debouceTime = 50;
	
	void setup() {
	    //pinMode(LED_G, OUTPUT);
	    pinMode(LED_R, OUTPUT);
	    pinMode(BTN_R, INPUT_PULLUP);
	   // pinMode(BTN_G, INPUT_PULLUP);
	
	    digitalWrite(LED_R, HIGH);
	
	    lastBtnVal_R = digitalRead(BTN_R);
	    lastBtnReleaseTime_R = millis();
	}
	
	void loop() {
	    if (digitalRead(BTN_R) == LOW) {
	        digitalWrite(LED_R, HIGH);
	    } else {
	        digitalWrite(LED_R, LOW);
	    }
	
	    int btnCurrVal = digitalRead(BTN_R);
	    if ((btnCurrVal == HIGH) && (lastBtnVal_R == LOW) && (millis() - lastBtnReleaseTime_R > debouceTime)) {
	        lastBtnReleaseTime_R = millis();
	        toggle_R_led();
	    }
	    lastBtnVal_R = btnCurrVal;
	}
	void toggle_R_led() {
	    if (R_LedIsOn) {
	        R_ledOff();
	    } else {
	        R_ledOn();
	    }
	}
	void R_ledOff() {
	    digitalWrite(LED_R, LOW);
	    R_LedIsOn = false;
	}
	void R_ledOn() {
	    digitalWrite(LED_R, HIGH);
	    R_LedIsOn = true;
	}
    