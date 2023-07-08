
#include <BluetoothSerial.h>

#include <Servo.h>


BluetoothSerial bt_iletisim;


#include <deneyap.h>

#define sol_ileri D14
#define sol_geri D15


#define sag_ileri D12
#define sag_geri D13
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
int angleStep = 5; // Açı adımı
// Delay değeri
int delayTime = 1; //ms
void setup() {
  // put your setup code here, to run once:
  bt_iletisim.begin("AG");
    servo1.attach(D9);
  servo2.attach(D8);
  servo3.attach(D0);
  servo4.attach(D4);
  Serial.begin(2400);
  pinMode(sol_ileri, OUTPUT);
  pinMode(sag_ileri, OUTPUT);
  pinMode(sol_geri, OUTPUT);
  pinMode(sag_geri, OUTPUT);
  
}


void kepcesikistir() {
  for (int angle = 180; angle >= 0; angle -= angleStep) {
    servo1.write(angle); 
    servo2.write(180 - (angle));
    delay(delayTime);
    Serial.print("Servo1(SOL) : ");
    Serial.print(angle);
    Serial.print("  ");
    Serial.print("Servo2(SAĞ) : ");
    Serial.println(180- angle);
  }
}

void kepcekaldir() {
  for (int angle = 110; angle >= 35; angle -= angleStep) {
    servo3.write(angle); // 180,179
    servo4.write(180 - (angle));
    delay(delayTime);
    Serial.print("Servo3(SOL) : ");
    Serial.print(angle);
    Serial.print("  ");
    Serial.print("Servo4(SAĞ) : ");
    Serial.println(180- angle);
  }
}

void kepcebirak() {
  for (int angle = 0; angle <= 180; angle += angleStep) {
    servo1.write(angle);
    servo2.write(180 - (angle));
    delay(delayTime);
    Serial.print("Servo1(SOL) : ");
    Serial.print(angle);
    Serial.print("  ");
    Serial.print("Servo2(SAĞ) : ");
    Serial.println(180- angle);
 }
}


void kepceindir() {
  for (int angle = 35; angle <= 110; angle += angleStep) {
    servo3.write(angle);
    servo4.write(180 - (angle));
    delay(delayTime);
    Serial.print("Servo3(SOL) : ");
    Serial.print(angle);
    Serial.print("  ");
    Serial.print("Servo4(SAĞ) : ");
    Serial.println(180- angle);
 }
}

void loop() {
if(bt_iletisim.available() > 0){
    char mesaj = bt_iletisim.read();
    Serial.println(mesaj);
    

    //Kepçe İndir a
    if(mesaj == 'a'){
      kepceindir();
      bt_iletisim.println(mesaj);

    }
    //Kepçe Kaldır b
    if(mesaj == 'b'){
      kepcekaldir();
      bt_iletisim.println(mesaj);

    }
    //Kepçe Sıkıştır s
    if(mesaj == 's'){
      kepcesikistir();
      bt_iletisim.println(mesaj);
    }

    //Kepçe Bırak m
    if(mesaj == 'm'){
      kepcebirak();
      bt_iletisim.println(mesaj);
    }

    //Sağa dön basıldığı sürece c 
    if(mesaj == 'c'){
      dur();

    }
    //Sola dön basıldığı sürece d
    if(mesaj == 'd'){
      dur();

    }

    //Sağa dön 90 e
    if(mesaj == 'e'){
      bt_iletisim.println(mesaj);

    }
    //Sola dön 90 f
    if(mesaj == 'f'){
      bt_iletisim.println(mesaj);

    }

    //Sağa dön 180 g
    if(mesaj == 'g'){
      bt_iletisim.println(mesaj);

    }
    //Sola dön 180 h
    if(mesaj == 'h'){
      bt_iletisim.println(mesaj);

    }
    //Yukarı-Joystick 1
    if(mesaj == '1'){
      dur();
      delay(10);
      ileri();
      bt_iletisim.println(mesaj);
    }
    //Aşağı-Joystick 3
    if(mesaj == '3'){
      dur();
      delay(10);
      geri();
      bt_iletisim.println(mesaj);
    }

    //Sağ-Joystick 2
    if(mesaj == '2'){
      dur();
      delay(10);
      sag();
      bt_iletisim.println(mesaj);
    }
    //Sol-Joystick 4
    if(mesaj == '4'){
      dur();
      delay(10);
      sol();
      bt_iletisim.println(mesaj);
    }

    
  }

}

void geri()
{
  digitalWrite(sol_ileri, 1);
  digitalWrite(sag_ileri, 1);
  digitalWrite(sol_geri, 0);
  digitalWrite(sag_geri, 0);

}

void ileri()
{
  digitalWrite(sol_ileri, 0);
  digitalWrite(sag_ileri, 0);
  digitalWrite(sol_geri, 1);
  digitalWrite(sag_geri, 1);

}

void sag()
{
  digitalWrite(sol_ileri, 1);
  digitalWrite(sag_ileri, 0);
  digitalWrite(sol_geri, 0);
  digitalWrite(sag_geri, 1);

}

void sol()
{
  digitalWrite(sol_ileri, 0);
  digitalWrite(sag_ileri, 1);
  digitalWrite(sol_geri, 1);
  digitalWrite(sag_geri, 0);

}

void dur()
{
  digitalWrite(sol_ileri, 0);
  digitalWrite(sag_ileri, 0);
  digitalWrite(sol_geri, 0);
  digitalWrite(sag_geri, 0);

}
