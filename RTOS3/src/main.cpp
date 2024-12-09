#include <Arduino.h>
TaskHandle_t task1;
TaskHandle_t task2;

void blink1(void *pvParameters);
void blink2(void *pvParameters);

void setup() {
  Serial.begin(9600);
  xTaskCreatePinnedToCore(blink1, "blink1", 2048, NULL, 1, &task1, 0);
  xTaskCreatePinnedToCore(blink2, "blink2", 2048, NULL, 1, &task2, 1);
}

void loop() {

}

void blink1(void *pvParameters){
  while(1){
    Serial.print("Task teče na jedru: ");
    Serial.println(xPortGetCoreID());
    delay(1000);
  }
}

void blink2(void *pvParameters){
  while(1){
    Serial.print("Task teče na jedru: ");
    Serial.println(xPortGetCoreID());
    delay(1000);
  }
}