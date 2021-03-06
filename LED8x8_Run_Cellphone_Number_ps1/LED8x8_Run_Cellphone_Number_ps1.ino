//8x8矩陣 電話號碼跑動 可改變號碼
byte ScanPin[8]={29,26,28,35,32,33,25,23};
byte DataPin[8]={37,27,36,31,22,34,24,30};
byte RunTime=100;//跑動速度從這改(單位:ms)
int T;//計時用
byte PhoneNumber[10];//儲存電話號碼
byte number;
byte Location;
byte x[8]={0,0,0,0,0,0,0,0};
boolean Data[8][80]=             
{ {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, 
  {1,1,1,0,0,1,1,1,1,0,0,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, 
  {1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,0,1,1,0,1,1,0,1,1,0,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,0,1,1,0,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,0,1,1,0,1,1,1,0,0,0,1,1,0,1,1,0,1,1,1,1,1,0,1,0,0,0,0,0,1,1,1,1,0,1,1,0,0,0,0,0,1,1,1,1,1,0,1,1,0,1,1,0,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,0,1,1,0,1,1,1,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,0,1,1,0,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,0,0,1,1,1,1,1,1,0,1,1,0,0,0,0,1,1,1,0,0,1,1,1,1,1,0,1,1,1,0,0,0,0,1,1,1,1,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
boolean zero[8][8]=
{ {1,1,1,1,1,1,1,1}, 
  {1,1,1,0,0,1,1,1}, 
  {1,1,0,1,1,0,1,1},
  {1,1,0,1,1,0,1,1},
  {1,1,0,1,1,0,1,1},
  {1,1,0,1,1,0,1,1},
  {1,1,1,0,0,1,1,1},
  {1,1,1,1,1,1,1,1}, 
};
boolean one[8][8]=
{ {1,1,1,1,1,1,1,1}, 
  {1,1,1,1,0,1,1,1}, 
  {1,1,1,0,0,1,1,1},
  {1,1,0,1,0,1,1,1},
  {1,1,1,1,0,1,1,1},
  {1,1,1,1,0,1,1,1},
  {1,1,0,0,0,0,1,1},
  {1,1,1,1,1,1,1,1}, 
};
boolean two[8][8]=
{ {1,1,1,1,1,1,1,1}, 
  {1,1,1,0,0,1,1,1}, 
  {1,1,0,1,1,0,1,1},
  {1,1,1,1,1,0,1,1},
  {1,1,1,1,0,1,1,1},
  {1,1,1,0,1,1,1,1},
  {1,1,0,0,0,0,1,1},
  {1,1,1,1,1,1,1,1}, 
};
boolean three[8][8]=
{ {1,1,1,1,1,1,1,1}, 
  {1,1,1,0,0,1,1,1}, 
  {1,1,0,1,1,0,1,1},
  {1,1,1,1,0,1,1,1},
  {1,1,1,1,1,0,1,1},
  {1,1,0,1,1,0,1,1},
  {1,1,1,0,0,1,1,1},
  {1,1,1,1,1,1,1,1}, 
};
boolean four[8][8]=
{ {1,1,1,1,1,1,1,1}, 
  {1,1,1,1,0,1,1,1}, 
  {1,1,1,0,0,1,1,1},
  {1,1,0,1,0,1,1,1},
  {1,0,0,0,0,0,1,1},
  {1,1,1,1,0,1,1,1},
  {1,1,1,1,0,1,1,1},
  {1,1,1,1,1,1,1,1}, 
};
boolean five[8][8]=
{ {1,1,1,1,1,1,1,1}, 
  {1,1,0,0,0,0,1,1}, 
  {1,1,0,1,1,1,1,1},
  {1,1,0,0,0,1,1,1},
  {1,1,1,1,1,0,1,1},
  {1,1,0,1,1,0,1,1},
  {1,1,1,0,0,1,1,1},
  {1,1,1,1,1,1,1,1}, 
};
boolean six[8][8]=
{ {1,1,1,1,1,1,1,1}, 
  {1,1,0,0,0,0,1,1}, 
  {1,1,0,1,1,1,1,1},
  {1,1,0,0,0,0,1,1},
  {1,1,0,1,1,0,1,1},
  {1,1,0,1,1,0,1,1},
  {1,1,0,0,0,0,1,1},
  {1,1,1,1,1,1,1,1}, 
};
boolean seven[8][8]=
{ {1,1,1,1,1,1,1,1}, 
  {1,1,0,0,0,0,1,1}, 
  {1,1,0,1,1,0,1,1},
  {1,1,0,1,1,0,1,1},
  {1,1,1,1,1,0,1,1},
  {1,1,1,1,1,0,1,1},
  {1,1,1,1,1,0,1,1},
  {1,1,1,1,1,1,1,1}, 
};
boolean eight[8][8]=
{ {1,1,1,1,1,1,1,1}, 
  {1,1,1,0,0,1,1,1}, 
  {1,1,0,1,1,0,1,1},
  {1,1,1,0,0,1,1,1},
  {1,1,0,1,1,0,1,1},
  {1,1,0,1,1,0,1,1},
  {1,1,1,0,0,1,1,1},
  {1,1,1,1,1,1,1,1}, 
};
boolean nine[8][8]=
{ {1,1,1,1,1,1,1,1}, 
  {1,1,1,0,0,1,1,1}, 
  {1,1,0,1,1,0,1,1},
  {1,1,0,1,1,0,1,1},
  {1,1,1,0,0,0,1,1},
  {1,1,1,1,1,0,1,1},
  {1,1,1,1,1,0,1,1},
  {1,1,1,1,1,1,1,1}, 
};

void setup()
{
  for (int i=0 ;i<8;i++)
  {
    pinMode(ScanPin[i], OUTPUT);
    pinMode(DataPin[i], OUTPUT);
  }
  Serial.begin(9600);
  Serial.println("Hello,please enter the 10 digit phone number.");
}

void loop()
{
 //------------------------------------字體顯示程式碼----------------------------------------- 
 for (int i=0; i <8; i++)
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
      digitalWrite(DataPin[j],HIGH);//清除所有DataPin
      }
     digitalWrite(ScanPin[i] ,LOW);//關閉ScanPin
 }
 //---------------------------------------跑動程式碼------------------------------------------------
  T=T+8;                          //計時 上方迴圈耗時8ms 所以+8
  if(T>=RunTime)                  //控制跑馬&變動時間 幾ms跑動一次
  {
    for(int i=0;i<8;i++)
    {
      x[i]=Data[i][0];            //暫存
      }
      for(int i=0;i<8;i++)
      {
        for(int j=0;j<79;j++)
        {
          Data[i][j]=Data[i][j+1];//全部向左移一個位子
          }
        }
        for(int i;i<8;i++)
        {
          Data[i][79]=x[i];//暫存放回最後
          }
          T=0;             //歸零
    }
    //--------------------------------Serial Monitor輸入程式碼-------------------------------------
    if(Serial.available()) 
    {
      delay(10);               //等待資料輸入齊全
      int w=Serial.available(); //計算字元數
      if(w==10)                //判斷是否為10碼
      {
        Serial.print("Your phone number is ");
        for(int i=0;i<w;i++)
        {
          PhoneNumber[i]=asciiTOnumber(Serial.read());  //經過轉換存入PhoneNumber
          Serial.print(PhoneNumber[i]);
          number=PhoneNumber[i];
          Location=i*6;                                 //Data替換位置
          change(Location);                             //使用副程式更改Data           
          }
          for(int i=0;i<8;i++)
          {
            for(int j=60;j<80;j++)
            {
              Data[i][j]=1;                             //Data後段清空
              }
            }
          Serial.println(".");
          T=0;                                          //計時歸零
        }
        else
        {
          Serial.println("Sorry.Please enter the 10 digit phone number.");//判斷非10碼 無動作
          while(Serial.read()>=0);                      //清除串列埠緩衝區資料
          }
      }    
}
//-----------------------------------自訂副程式函式區域-----------------------------------------
int asciiTOnumber(int ascii) //ASCII轉數字
{
  byte number;
  switch(ascii)
  {
    case 48:number=0;break;
    case 49:number=1;break;
    case 50:number=2;break;
    case 51:number=3;break;
    case 52:number=4;break;
    case 53:number=5;break;
    case 54:number=6;break;
    case 55:number=7;break;
    case 56:number=8;break;
    case 57:number=9;break;
    default:break;
    }
    return number;//回傳數字
  }

  void change(int x1)                     //替換副程式
  {
    for(int x2=0;x2<8;x2++)
    {
      for(int x3=0;x3<8;x3++)
      {
         switch(number)
        {
         case 0:Data[x2][x1+x3]=zero[x2][x3];break;
         case 1:Data[x2][x1+x3]=one[x2][x3];break;
         case 2:Data[x2][x1+x3]=two[x2][x3];break;
         case 3:Data[x2][x1+x3]=three[x2][x3];break;
         case 4:Data[x2][x1+x3]=four[x2][x3];break;          //x1是Location 為Data替換位置的第一個位置
         case 5:Data[x2][x1+x3]=five[x2][x3];break;
         case 6:Data[x2][x1+x3]=six[x2][x3];break;
         case 7:Data[x2][x1+x3]=seven[x2][x3];break;
         case 8:Data[x2][x1+x3]=eight[x2][x3];break;
         case 9:Data[x2][x1+x3]=nine[x2][x3];break;
      }
        }
      } 
    }
