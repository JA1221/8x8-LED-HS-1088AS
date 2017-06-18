//8x8矩陣 字體跑動
byte ScanPin[8]={29,26,28,35,32,33,25,23};
byte DataPin[8]={37,27,36,31,22,34,24,30};
int T;
byte x;
boolean Data[8][8]=
{ {1,1,1,1,0,1,1,1}, 
  {1,1,0,1,1,0,1,1}, 
  {1,0,1,1,1,1,0,1},
  {0,1,1,0,1,1,1,0},
  {1,1,0,1,1,1,1,1},
  {1,0,1,1,1,0,1,1},
  {1,1,0,0,0,1,0,1},
  {1,1,1,1,1,1,1,1}, 
};
void setup()
{
  for (int i=0 ;i<8;i++)
  {
    pinMode(ScanPin[i], OUTPUT);
    pinMode(DataPin[i], OUTPUT);
  }
}
void loop()
{
 for (int i=0; i <8; i++)             //顯示字
  {    
    digitalWrite(ScanPin[i],HIGH);
    for (int j=0; j <8; j++)
    {
      
      if(Data[i][7-j]==0)
      {
        digitalWrite(DataPin[j],LOW);          
      }
      else
      {
        digitalWrite(DataPin[j],HIGH);
      }
     }  
     delay(1);
     for(int j=0;j<8;j++)
     {
      digitalWrite(DataPin[j],HIGH);
      }
     digitalWrite(ScanPin[i] ,LOW);
 }
  T=T+8;                                      //計時 上方迴圈耗時8ms 所以+8
  if(T>=1000)                                 //控制跑馬&變動時間 單位ms
  {
    x=DataPin[0];                                 //DataPin橫向跑動 ScanPin縱向跑動
    for(int i=0;i<7;i++)DataPin[i]=DataPin[i+1];
    DataPin[7]=x;
    T=0;         //計時歸零
    }
}
