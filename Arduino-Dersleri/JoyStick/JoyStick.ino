#define relayCount (sizeof(relays)/sizeof(int))
const int button = A0;
const int relays[]{2,3,4,5,6};
int relayStates[][relayCount]={
    {0,0,0,0,0},
    {1,0,0,0,1},
    {0,1,0,0,1},
    {0,0,1,0,1},
    {0,0,0,1,1}
};
#define STOP 0
#define FORWARD 1
#define RIGHT 2
#define BACK 3
#define LEFT 4
long ct = 0;
uint8_t buttonState, lastBTNstate, index = STOP;
boolean update = false;

void setup(){
    Serial.begin(9600);
    pinMode(button, INPUT);
    for(int i = 0; i < relayCount; i++){
        pinMode(relays[i], OUTPUT);
        digitalWrite(relays[i], relayStates[index][i]); 
    }
}

void loop(){
  // Button actions
    buttonState = analogRead(button);
    
    if(buttonState != lastBTNstate){
        if(buttonState > 50 && buttonState < 100){
            index = FORWARD;
        }
        if(buttonState > 100 && buttonState < 140){
            index = RIGHT;
        }
        if(buttonState > 3 && buttonState <= 10){
            index = BACK;
        }
        if(buttonState > 140 && buttonState <= 200){
            index = LEFT;
        }
        if(buttonState < 3){
            index = STOP;
        }
        update = true;
    }
    if(update){
        for(int i = 0; i < relayCount; i++){
        digitalWrite(relays[i], relayStates[index][i]); 
        }
        update = false;
    }
  	if(millis() - ct > 500){
      Serial.print("Index: ");
      Serial.print(index);
      Serial.print("\t");
      Serial.print("BTN State: ");
      Serial.println(buttonState);
      ct = millis();
    }
    lastBTNstate = buttonState;
}