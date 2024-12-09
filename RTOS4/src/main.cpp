#include <Arduino.h>

SemaphoreHandle_t semafor;

void blink1(void *pvParameters);
void blink2(void *pvParameters);
void blink3(void *pvParameters);
void blink4(void *pvParameters);
void setup() {
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  semafor = xSemaphoreCreateCounting(6,6);
  xTaskCreate(blink1, "blink1", 2048, NULL, 1, NULL);
  xTaskCreate(blink2, "blink2", 2048, NULL, 1, NULL);
  xTaskCreate(blink3, "blink3", 2048, NULL, 1, NULL);
    xTaskCreate(blink4, "blink3", 2048, NULL, 1, NULL);
  xSemaphoreGive(semafor);
}

void loop() {

}

void blink1(void *pvParameters){
  int le1 = 0;
  while(1){
    le1 = random(16,20);
    xSemaphoreTake(semafor,portMAX_DELAY);
    for(int n = 0; n<random(1,4); n++){
      digitalWrite(le1, 1);
      delay(100*random(1,10));
      digitalWrite(le1, 0);
      delay(100*random(1,10));
    }
    xSemaphoreGive(semafor);
    delay(10);
  }
}

void blink2(void *pvParameters){
  int le2 = 0;
  while(1){
    le2 = random(16,20);
    xSemaphoreTake(semafor,portMAX_DELAY);
    for(int n = 0; n<random(1,4); n++){
      digitalWrite(le2, 1);
      delay(100*random(1,10));
      digitalWrite(le2, 0);
      delay(100*random(1,10));
    }
    xSemaphoreGive(semafor);
    delay(10);
  }
}

void blink3(void *pvParameters){
  int le3 = 0;
  while(1){
    le3 = random(16,20);
    xSemaphoreTake(semafor,portMAX_DELAY);
    for(int n = 0; n<random(1,4); n++){
      digitalWrite(le3, 1);
      delay(100*random(1,10));
      digitalWrite(le3, 0);
      delay(100*random(1,10));
    }
    xSemaphoreGive(semafor);
    delay(10);
  }
}

void blink4(void *pvParameters){
  int le3 = 0;
  while(1){
    le3 = random(16,20);
    xSemaphoreTake(semafor,portMAX_DELAY);
    for(int n = 0; n<random(1,4); n++){
      digitalWrite(le3, 1);
      delay(100*random(1,10));
      digitalWrite(le3, 0);
      delay(100*random(1,10));
    }
    xSemaphoreGive(semafor);
    delay(10);
  }
}