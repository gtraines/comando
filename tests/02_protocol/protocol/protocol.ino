/* A very simple commando example
 * This does NOT use protocols and in that way is a BAD example
 */
#include<commando.h>

// Initialize the commando communication stream handler
Commando com = Commando(Serial);
// setup and Echo protocol, this just sends back whatever is received
EchoProtocol echo = EchoProtocol(com);

void setup() {
  // start up the serial port
  Serial.begin(9600);
  // register the echo protocol
  com.register_protocol(0, echo);
};

void loop() {
  // handle the incoming messages
  com.handle_stream();
};
