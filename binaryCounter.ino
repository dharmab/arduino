int LED_DIGIT_1 = 2;
int LED_DIGIT_2 = 3;
int LED_DIGIT_4 = 4;
int LED_DIGIT_8 = 5;
int BUTTON_UP = 7;
int BUTTON_DOWN = 9;
int MAX_DISPLAY_VALUE = 15;
int MIN_DISPLAY_VALUE = 0;

int counter = MIN_DISPLAY_VALUE;

void setup() {
	allDigitsOff();
}

void loop() {
	
	if (isButtonOn(BUTTON_UP)) {
		counter++;
		if(counter > MAX_DISPLAY_VALUE) {
			counter = MIN_DISPLAY_VALUE;
		}
		displayByte(counter);
		} else if(isButtonOn(BUTTON_DOWN)) {
			counter--;
			if(counter < MIN_DISPLAY_VALUE) {
				counter = MIN_DISPLAY_VALUE;
			}
			displayByte(counter);
		}
		delay(150);
	}

	void displayByte(unsigned int number) {
		if (number >= MAX_DISPLAY_VALUE) {
			allDigitsOn();
			return;
		}

		for (unsigned int i = 8; i > 0; i = i / 2) {
			if (number >= i) {
				digitOn(i);
				number = number - i;
				} else {
					digitOff(i);
				}
			}
		}

		void digitOn(unsigned int digit) {
			switch (digit) {
				case 1:
				digitalWrite(LED_DIGIT_1, HIGH);
				break;
				case 2:
				digitalWrite(LED_DIGIT_2, HIGH);
				break;
				case 4:
				digitalWrite(LED_DIGIT_4, HIGH);
				break;
				case 8:
				digitalWrite(LED_DIGIT_8, HIGH);
				break;
			}
		}

		void digitOff(unsigned int digit) {
			switch (digit) {
				case 1:
				digitalWrite(LED_DIGIT_1, LOW);
				break;
				case 2:
				digitalWrite(LED_DIGIT_2, LOW);
				break;
				case 4:
				digitalWrite(LED_DIGIT_4, LOW);
				break;
				case 8:
				digitalWrite(LED_DIGIT_8, LOW);
				break;
			}
		}

		void allDigitsOn() {
			digitOn(1);
			digitOn(2);
			digitOn(4);
			digitOn(8);
		}

		void allDigitsOff() {
			digitOff(1);
			digitOff(2);
			digitOff(4);
			digitOff(8);
		}

		boolean isButtonOn(int button) {
			if (digitalRead(button) == HIGH) {
				return true;
			} 
			else {
				return false;
			}
		}
