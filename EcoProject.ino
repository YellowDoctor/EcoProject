const byte PinSensor = 2; // указываем номер цифрового вывода arduino, к которому подключён датчик движения RCWL-0516
const uint8_t PinAlarm = 13; // указываем номер цифрового вывода arduino, к которому подключён светодиод
int LDR = 5;                 // пин к которому подключен датчик освещения
int val = 0;                 // переменная для значения с датчика освещения
int valS = 0;                // присваеваем значение с датчика присутстваия
unsigned long time;

void setup() {
  Serial.begin(9600);
  pinMode(LDR, INPUT);
  pinMode(PinSensor, INPUT); // конфигурируем цифровой вывод датчика как вход
  pinMode(PinAlarm, OUTPUT); // конфигурируем цифровой вывод светодиода как выход
  pinMode(PinSensor, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PinSensor), ECO, HIGH);
}
void loop() {

}

void ECO() {
  valS = analogRead(PinSensor);//считываем значение и записываем значения
  if (!valS) {
    //digitalWrite(PinAlarm, digitalRead(PinSensor)); // управляем светодиодом
    val = digitalRead(LDR);
    if (val >= 512) {
      if (millis() - time > 10000) {  //10 секунд ждём
        time = millis();
        Serial.println ("Выключи свет");
      }
    }
  }
}

