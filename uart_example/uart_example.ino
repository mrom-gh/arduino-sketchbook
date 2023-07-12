/*
  uart_example
  Reads bytes via UART and echos them back
 */

const int BUFFER_SIZE = 20;

void setup() {
  Serial.begin(9600); // Set the baud rate to 9600
}

void loop() {
  if (Serial.available()) {
    // Read data from the serial buffer into a character array
    char buffer[BUFFER_SIZE];
    int bytesRead = Serial.readBytesUntil('\n', buffer, BUFFER_SIZE);

    // Process the received data as needed
    // For example, you can print it back to the serial monitor
    Serial.print("Received data: ");
    for (int i = 0; i < bytesRead; i++) {
      Serial.print(buffer[i]);
    }
    Serial.println();    
  }
}

