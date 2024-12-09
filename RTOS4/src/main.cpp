#include <Arduino.h>

SemaphoreHandle_t semafor;

void blink1(void *pvParameters);
void blink2(void *pvParameters);

void setup() {
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);

  semafor = xSemaphoreCreateBinary();
  xTaskCreate(blink1, "blink1", 2048, NULL, 1, NULL);
  xTaskCreate(blink2, "blink2", 2048, NULL, 1, NULL);
}

void loop() {

}

void blink1(void *pvParameters){
  while(1){
    for(int n = 0; n<5; n++){
      digitalWrite(16, 1);
      delay(100);
      digitalWrite(16, 0);
      delay(100);
    }
    xSemaphoreGive(semafor);
    for(int n = 0; n<5; n++){
      digitalWrite(16, 1);
      delay(50);
      digitalWrite(16, 0);
      delay(50);
    }
    delay(10);
  }
}

void blink2(void *pvParameters){
  while(1){
    xSemaphoreTake(semafor, portMAX_DELAY);
    for(int n = 0; n<5; n++){
      digitalWrite(17, 1);
      delay(100);
      digitalWrite(17, 0);
      delay(100);
    }
    
    delay(10);
  }
}