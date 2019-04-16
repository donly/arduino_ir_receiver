#include <IRremote.h>
const int sensorIn = 11;  //红外接收端

IRrecv irrecv(sensorIn);
decode_results results;
unsigned long key_value = 0;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();  //开始接收红外信号
  irrecv.blink13(true);
  Serial.println("Ready to receive IR signals");
}

void loop() {
  // 解码成功，收到一组红外线信号
  if (irrecv.decode(&results))  {
    // the repetition of the previous key.
    if (results.value == 0XFFFFFFFF) {
      results.value = key_value;
    }
    Serial.print("Code: ");
    Serial.println(results.value, HEX);
    key_value = results.value;
    irrecv.resume();              // Receive the next value
  }
}
