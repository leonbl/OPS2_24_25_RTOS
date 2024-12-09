#include <Arduino.h>
TaskHandle_t task1;
TaskHandle_t task2;

void blink1(void *pvParameters);
void blink2(void *pvParameters);
void sklad(void *pvParameters);

void setup() {
  xTaskCreate(blink1, "blink1", 2048, NULL, 1, &task1);
  xTaskCreate(blink2, "blink2", 2048, NULL, 1, &task2);
  xTaskCreate(sklad, "sklad", 2048, NULL, 1, NULL);
}

void loop() {
}

void blink1(void *pvParameters){
  pinMode(16, OUTPUT);
  while(1){
    digitalWrite(16, 1);
    delay(500);
    digitalWrite(16, 0);
    delay(500);
  }
}

void blink2(void *pvParameters){
    pinMode(17, OUTPUT);
  while(1){
    digitalWrite(17, 1);
    delay(300);
    digitalWrite(17, 0);
    delay(300);
  }
}

void sklad(void *pvParameters){
  Serial.begin(9600);
  while(1){
    delay(1000);
    Serial.print("Task: ");
    Serial.print(pcTaskGetName(task1));
    Serial.print(" sklad: ");
    Serial.println(uxTaskGetStackHighWaterMark(task1));
    Serial.print("Task: ");
    Serial.print(pcTaskGetName(task2));
    Serial.print(" sklad: ");
    Serial.println(uxTaskGetStackHighWaterMark(task2));
    Serial.println();
  }
}