/*
 * for HC-06 bluetooth module
 */

/*
 * Module commands (slave)
 * AT+BAUD<setting>
 *	Set baud rate: (bps)
 *	1 - 1200
 *	2 - 2400
 *	3 - 4800
 *	4 - 9600
 *	5 - 19200
 *	6 - 38400
 *	7 - 57600
 *	8 - 115200
 *	9 - 230400
 *	A - 460800
 *	B - 921600
 *	C - 1382400
 * AT+NAME<name>
 *	Set name (Max 20 characters)
 * AT+PIN<number>
 *	PIN (4 digit number)
 */

/*
 * Example:
 * AT
 * >OK
 * AT+VERSION
 * >OKlinvorV1.8
 * AT+BAUD4
 * >OK9600
 * AT+PIN1234
 * >setPIN
 * AT+NAMEabc
 * >setname
 */

#include <SoftwareSerial.h>

/* RX: 2, TX: 3 */
SoftwareSerial bluetooth(2, 3);

void setup()
{
	Serial.begin(9600);
	/* HC-06 module default baud is 9600bps */
	bluetooth.begin(9600);

	Serial.println("Enter AT commands: ");
}

void loop()
{
	if(bluetooth.available() > 0)
		Serial.write(bluetooth.read());
	
	if(Serial.available() > 0)
		bluetooth.write(Serial.read());
}

