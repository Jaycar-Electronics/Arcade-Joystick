#include <Keyboard.h>

#define PINCOUNT 8
byte pins[PINCOUNT]={2,3,4,5,6,7,8,9};
byte keys[PINCOUNT]={
  KEY_UP_ARROW,
  KEY_RIGHT_ARROW,
  KEY_DOWN_ARROW,
  KEY_LEFT_ARROW,
  KEY_LEFT_CTRL,
  KEY_LEFT_ALT,
  '1',
  '5',
};
byte keystate[PINCOUNT];
byte newstate[PINCOUNT];

void setup() {
  for(int i=0;i<PINCOUNT;i++){        //set to inputs with pullups
    pinMode(pins[i],INPUT_PULLUP);  
  }
  delay(1000);        //wait a bit so that keyboard doesn't take over
  for(int i=0;i<PINCOUNT;i++){
    keystate[i]=digitalRead(pins[i]); //read initial state
  }
  Keyboard.begin();
}

void loop() {
  for(int i=0;i<PINCOUNT;i++){
    newstate[i]=digitalRead(pins[i]); //read states
  }
  for(int i=0;i<PINCOUNT;i++){
    if((newstate[i]==LOW)&&(keystate[i]==HIGH)){    //key pressed
      Keyboard.press(keys[i]);
    }
    if((newstate[i]==HIGH)&&(keystate[i]==LOW)){    //key released
      Keyboard.release(keys[i]);
    }
  }
  for(int i=0;i<PINCOUNT;i++){
    keystate[i]=newstate[i];                      //change old status
  }
}

