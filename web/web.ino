int led = 13;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
    int order = getOrder();
    executeOrder(order);    
}

int getOrder() {   
  int order = 0;
  //We received the order.
  if (Serial.available() > 0) {
    order = Serial.parseInt();
  }
  
  return order;
}

void executeOrder(int order) {
    //We execute the order.
    switch(order){
      case 0:
        digitalWrite(led, 0);
        Serial.println("TURN OFF");
        break;
      case 1:
        digitalWrite(led, 1);
        Serial.println("TURN ON");
        break;
      default:
        Serial.println("Unknown order");
    }
}
