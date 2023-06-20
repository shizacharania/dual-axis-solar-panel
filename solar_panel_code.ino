//L293D
//Motor A
const int motorPin1  = 5;  
const int motorPin2  = 6;  
//Motor B
const int motorPin3  = 10; 
const int motorPin4  = 9; 

int north;
int south;
int west;
int east;
int min_ldr1;
int min_ldr2;
int min_ldr;
int position = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  //Readings on each LDR's respective to their position on the solar panel
  north = analogRead(A0); //Green wire
  south = analogRead(A1); //Red wire
  west = analogRead(A2); //White wire
  east = analogRead(A3); //Blue wire


  // ldrs = {north, south, west, east};

  int west_east = abs(west - east);
  int west_north = abs(west - north);
  int west_south = abs(west - south);
  int east_north = abs(east - north);
  int east_south = abs(east - south);
  int south_north = abs(south - north);


  if (west_east < 100 && west_north < 100 && west_south < 100 && east_north < 100 && east_south < 100 && south_north < 100) {
    Serial.println("balanced");
  }
  else {
    Serial.print("NORTH (A0): ");
    Serial.println(north);


    Serial.print("SOUTH (A1): ");
    Serial.println(south);


    Serial.print("WEST (A2): ");
    Serial.println(west);


    Serial.print("EAST (A4): ");
    Serial.println(east);
    Serial.println("not balanced");
    min_ldr1 = min(north, south);
    min_ldr2 = min(east, west);
    min_ldr = min(min_ldr1, min_ldr2);
    
    if (min_ldr == north) {
      Serial.println("POINTING AT NORTH");
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, HIGH);
      delay(50);
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, LOW);
    }
    
    if (min_ldr == south) {
      Serial.println("POINTING AT SOUTH");
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin3, HIGH);
      digitalWrite(motorPin4, LOW);
      delay(50);
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, LOW);
    }
    
    if (min_ldr == west) {
      Serial.println("POINTING AT WEST");
      digitalWrite(motorPin1, HIGH);
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, LOW);
      delay(150);
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, LOW);

      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin3, HIGH);
      digitalWrite(motorPin4, LOW);
      delay(50);
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, LOW);
    }
    
    if (min_ldr == east) {
      Serial.println("POINTING AT EAST");
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, HIGH);
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, LOW);
      delay(150);
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, LOW);

      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, HIGH);
      delay(50);
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, LOW);
    }
  }
}
