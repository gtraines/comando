/* A very simple commando example
 * This does NOT use protocols and in that way is a BAD example
 */
#include<commando.h>

// Initialize the commando communication stream handler
Commando com = Commando(Serial);

// define a message callback
void echo() {
  // return the message received by the arduino
  com.send_message(com.get_bytes(), com.get_n_bytes());
};

void setup() {
  // start up the serial port
  Serial.begin(9600);
  // register the defined callback
  com.register_message_callback(echo);
};

void loop() {
  // handle the incoming messages
  com.handle_stream();
};
