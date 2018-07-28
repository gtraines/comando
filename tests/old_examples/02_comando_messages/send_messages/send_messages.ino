/*
 * A (pointless) example showing how by default the Commando class echos
 * any messages it receives.
 * Load this onto an arduino, then call the corresponding send_messages.py with python
 * You should see two messages sent to the arduino ("hi" and "how are you?") and those same
 * messages echoed back to the computer.
 */
#include <commando.h>

Commando cmd = Commando(Serial);
EchoProtocol echo = EchoProtocol(cmd);

void setup() {
  Serial.begin(9600);
  cmd.register_protocol(0, echo);
}

void loop() {
  cmd.handle_stream();
}
