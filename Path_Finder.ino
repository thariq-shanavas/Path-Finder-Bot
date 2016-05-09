#define m1f 2
#define m1b 4
#define m1e 3
#define m2f 7
#define m2b 8
#define m2e 5
#define ir1 10
#define irf 11
#define irl 12
#define ir4 13
#define sp 200
#define turnticks 3

int x=30,y=35;

void setup() {
  pinMode(ir1,INPUT);
  pinMode(irf,INPUT);
  pinMode(irl,INPUT);
  pinMode(ir4,INPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);

  
  
  void fwd (int);
  void turnr ();

  step1:
    
  if(y<0)
  {
    turnr();
    turnr();
    y=-y;
    x=-x;
  }
}

void loop() {

  step2:
  
  while(1)
  {
    fwd(1);
    y--;
    if(y==0)
    { 
      if(x==0)
      {
        exit(0);
      }
      goto step5;
    }

    if(digitalRead(irf)==LOW)
    {
      goto step3;
    }
  }

  step3:
  {
    turnr();
    while(1)
    {
      fwd(1); x--;
      if (digitalRead(irl)==HIGH)
      {
        turnl();
        goto step2; 
      }
    }
        
  }
  step5:
  {
    if(x<0)
    {
      turnl();
      y=-x;
      x=0;
      goto step2;
    }

    else
    {
      turnr();
      y=x;
      x=0;
      goto step2;
    }
  }
}

void fwd (int a)
{
  analogWrite(m1e,200);
  analogWrite(m2e,217);
  
  digitalWrite(m1f,HIGH);
  digitalWrite(m1b,LOW);
  digitalWrite(m2f,HIGH);
  digitalWrite(m2b,LOW);
 
 for(int i=0;i<a;)
 {if(digitalRead(ir1)==HIGH)
  {
    while(digitalRead(ir1)==HIGH)
    {delay(1);}
    while(digitalRead(ir1)==LOW)
    {delay(1);} 
  }
  
  else
  {
    while(digitalRead(ir1)==LOW)
    {delay(1);}
    while(digitalRead(ir1)==HIGH)
    {delay(1);}
   }
  i++;
 }
 digitalWrite(m1f,LOW);
 digitalWrite(m2f,LOW);
  
}

void turnl ()
{

  
  analogWrite(m1e,160);
  analogWrite(m2e,195);
  delay(500);
  digitalWrite(m1f,HIGH);
  digitalWrite(m1b,LOW);
  digitalWrite(m2f,LOW);
  digitalWrite(m2b,HIGH);

  for(int i=0;i<turnticks;)
 {if(digitalRead(ir1)==HIGH)
  {
    while(digitalRead(ir1)==HIGH)
    {delay(1);}
    while(digitalRead(ir1)==LOW)
    {delay(1);}
  }
  
  else
  {
    while(digitalRead(ir1)==LOW)
    {delay(1);}
    while(digitalRead(ir1)==HIGH)
    {delay(1);}
   }
  i++;
 }

 digitalWrite(m1f,LOW);
 digitalWrite(m2b,LOW);
  delay(500);
}


void turnr ()
{

  
  analogWrite(m1e,180);
  analogWrite(m2e,185);
  delay(500);
  digitalWrite(m1f,LOW);
  digitalWrite(m1b,HIGH);
  digitalWrite(m2f,HIGH);
  digitalWrite(m2b,LOW);

  for(int i=0;i<turnticks;)
 {if(digitalRead(ir1)==HIGH)
  {
    while(digitalRead(ir1)==HIGH)
    {delay(1);}
    while(digitalRead(ir1)==LOW)
    {delay(1);}
  }
  
  else
  {
    while(digitalRead(ir1)==LOW)
    {delay(1);}
    while(digitalRead(ir1)==HIGH)
    {delay(1);}
   }
  i++;
 }

 digitalWrite(m1b,LOW);
 digitalWrite(m2f,LOW);
 delay(500);

}

