int LED_DIGIT_1 = 2;
int LED_DIGIT_2 = 3;
int LED_DIGIT_4 = 4;
int LED_DIGIT_8 = 5;
int MAX_DISPLAY_VALUE = 15;
//int true = 1;
//int false = 0;

void setup() {
	allDigitsOff();
}

void loop() {
  displayByte(1);
  displayByte(2);
  displayByte(3);
  displayByte(4);
  displayByte(5);
  displayByte(6);
  displayByte(7);
  displayByte(8);
  displayByte(9);
  displayByte(10);
  displayByte(11);
  displayByte(12);
  displayByte(13);
  displayByte(14);
  displayByte(15);
}

void displayByte(unsigned int number) {
	if (number >= MAX_DISPLAY_VALUE) {
		allDigitsOn();
		return;
	}

	for (int i = 8; i >= 1; i / 2) {
		if (number - i >= 0) {
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
	digitOn(LED_DIGIT_1);
	digitOn(LED_DIGIT_2);
	digitOn(LED_DIGIT_4);
	digitOn(LED_DIGIT_8);
}

void allDigitsOff() {
	digitOff(LED_DIGIT_1);
	digitOff(LED_DIGIT_2);
	digitOff(LED_DIGIT_4);
	digitOff(LED_DIGIT_8);
}
