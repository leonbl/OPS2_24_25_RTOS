#include <Arduino.h>
TaskHandle_t task1;
TaskHandle_t task2;

void blink1(void *pvParameters);
void blink2(void *pvParameters);

void setup() {
  xTaskCreate(blink1, "blink1", 2048, NULL, 1, &task1);
  xTaskCreate(blink2, "blink2", 2048, NULL, 1, &task2);
}

void loop() {

}

void blink1(void *pvParameters){
  pinMode(16, OUTPUT);
  while(1){
    digitalWrite(16, 1);
    delay(50);
    digitalWrite(16, 0);
    delay(50);
  }
}

void blink2(void *pvParameters){
  while(1){
    vTaskSuspend(task1);
    delay(2000);
    vTaskResume(task1);
    delay(2000);
  }
}