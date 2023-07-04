

/*
Kepçe indir a
Kepçe Kaldır b
Kapçe Sıkıştır s
Kepçe bırak j daha koda eklenmedi
Sağa dön basıldığı sürece c
Sola dön basıldığı sürece d
Sağa dön 90 e
Sola dön 90 f
Sağa dön 180 g
Sola dön 180 h
Yukarı-Joystick 1
Aşağı-Joystick 3
Sağ-Joystick 2
Sol-Joystick 4
*/


#include <Servo.h>
#include<SoftwareSerial.h>

SoftwareSerial bt_iletisim(2, 3);

#define sol_ileri 4
#define sol_geri 8


#define sag_ileri 12
#define sag_geri 13


int motorlar_hiz = 255;
byte son_islem;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

// Açı değerleri
int servo1StartAngle = 180;
int servo1EndAngle = 0;
int servo2StartAngle = 0;
int servo2EndAngle =180;

int angleStep = 5; // Açı adımı
// Delay değeri
int delayTime = 1; //ms


void setup() {
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(6);
  servo4.attach(11);
  Serial.begin(38400);
  pinMode(sol_ileri, OUTPUT);
  pinMode(sag_ileri, OUTPUT);
  pinMode(sol_geri, OUTPUT);
  pinMode(sag_geri, OUTPUT);
  

  bt_iletisim.begin(38400);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(bt_iletisim.available() > 0){
    char mesaj = bt_iletisim.read();
    

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
/*
    //Sağa dön basıldığı sürece c 
    if(mesaj == 'c'){
 

    }
    //Sola dön basıldığı sürece d
    if(mesaj == 'd'){


    }
*/
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
      ileri();
      bt_iletisim.println(mesaj);
    }
    //Aşağı-Joystick 3
    if(mesaj == '3'){
      geri();
      bt_iletisim.println(mesaj);
    }

    //Sağ-Joystick 2
    if(mesaj == '2'){
      sag();
      bt_iletisim.println(mesaj);
    }
    //Sol-Joystick 4
    if(mesaj == '4'){
      sol();
      bt_iletisim.println(mesaj);
    }
  }
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

//---------------------------------------------------------------------

void ileri()
{
  digitalWrite(sol_ileri, 1);
  digitalWrite(sag_ileri, 1);
  digitalWrite(sol_geri, 0);
  digitalWrite(sag_geri, 0);
}

void geri()
{
  digitalWrite(sol_ileri, 0);
  digitalWrite(sag_ileri, 0);
  digitalWrite(sol_geri, 1);
  digitalWrite(sag_geri, 1);
}

void sol()
{
  digitalWrite(sol_ileri, 1);
  digitalWrite(sag_ileri, 0);
  digitalWrite(sol_geri, 0);
  digitalWrite(sag_geri, 1);
}

void sag()
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