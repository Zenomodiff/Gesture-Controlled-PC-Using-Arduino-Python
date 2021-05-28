/*feel free to contact
 * sreeramaj53@gmail.com
 * www.youtube.com/ZenoModiff
 * last updated - time 12:32 AM - date 29 may 2021
 Github Link :-- https://github.com/Zenomodiff/Gesture-Controlled-PC-Using-Arduino-Python
 */

const int trigPin1 = 12;
const int echoPin1 = 11;   
const int trigPin2 = 6; 
const int echoPin2 = 5; 

long duration;                               
int distance1, distance2; 
float r;
unsigned long temp=0;
int temp1=0;
int l=0;

void find_distance (void);

void find_distance (void)                   
{ 
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

duration = pulseIn(echoPin1, HIGH, 5000); 
 r = 3.4 * duration / 2;                    
 distance1 = r / 100.00;
 
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  duration = pulseIn(echoPin2, HIGH, 5000);
  r = 3.4 * duration / 2;     
  distance2 = r / 100.00;
  delay(100);
}

void setup() 
{
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  delay (1000);
    
}

void loop()
{
  find_distance(); 
                
  
  if(distance2<=35 && distance2>=15) 
  { 
    temp=millis();                  
    while(millis()<=(temp+300))    
    find_distance();
    if(distance2<=35 && distance2>=15)
    {
     temp=distance2;                       
     while(distance2<=50 || distance2==0)  
     {
       find_distance();                    
       if((temp+6)<distance2)               
       {
       Serial.println("down");         
       }
       else if((temp-6)>distance2)         
       {
        Serial.println("up");                
       }
     }
    }
    else                                     
    {
      Serial.println("next");           
    }
  }

  else if(distance1<=35 && distance1>=15)  
  { 
  
    temp=millis();                           
  
    while(millis()<=(temp+300))             
    {
       find_distance();
       if(distance2<=35 && distance2>=15)  
       {
         Serial.println("change");      
         l=1;                           
         break;                          
       }
    }
    
    if(l==0)                           .
    {
 Serial.println("previous");        
 while(distance1<=35 && distance1>=15)
 find_distance();                      
 }
 l=0;             
} 
}
