//8x8矩陣 電話號碼跑動 可改變號碼 增加功能:Serial Monitor 設定跑動,停止,速度設定
byte ScanPin[8]={29,26,28,35,32,33,25,23};
byte DataPin[8]={37,27,36,31,22,34,24,30};
int RunTime=100;//跑動速度從這改(單位:ms)
int T;//計時用
byte PhoneNumber[10];//儲存電話號碼
boolean runandstop=1;//跑動模式(預設1跑動;0停止)
boolean mod=1;//(模式1正常;0速度輸入模式 禁止修改預設值)
byte number;
byte Location;
byte x[8]={0,0,0,0,0,0,0,0};
//----------------------顯示資料(預設:0965414304)-------------------------
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
//-------------------------數字資料-------------------------
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
  if(runandstop==1)
 {
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
  }
    //-----------------------------------Serial Monitor輸入程式碼-------------------------------------
    if(mod==1)                   //模式非速度輸入模式
    {    
      if(Serial.available()) 
    {
      delay(10);                   //等待資料輸入齊全
      int w=Serial.available();     //計算字元數
      if(w==3 || w==4 ||w==5)      //run,stop,speed 時使用
      {
        String s;
        for(int i=0;i<w;i++)
        {
          s+=asciiTOcharacter(Serial.read()); 
          }
          if(s=="run")
          {
            runandstop=1;             //開始跑動
            Serial.println("Now the state is: Running");            
            }
          else if(s=="stop")
          {
            runandstop=0;             //停止跑動
            Serial.println("Now the state is: Stop");            
            }
            else if(s=="speed")
            {
              Serial.println("Speed setting.Please enter a value.");
              mod=0;                  //進入速度輸入模式
              }
              else Serial.println("Sorry.Please enter the 10 digit phone number.");
            }
            //--------------更改電話號碼----------------
            else if(w==10)
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
         //----------速度設定(mod=0 速度輸入模式)---------------
       if(Serial.available()) 
       {
        delay(10);
        String s;
        int w=Serial.available();
        for(int i=0;i<w;i++)
        {
          s=s+asciiTOnumber(Serial.read());
          } 
          RunTime=s.toInt();                          //String 轉 Int
          Serial.print("Cycle:");
          Serial.print(RunTime);
          Serial.println("ms.");
          mod=1;                                      //速度輸入模式關閉
        }

}
//-----------------------------------自訂副程式函式區域-----------------------------------------
int asciiTOnumber(int ascii)//ASCII轉數字
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

char asciiTOcharacter(int ascii)//ASCII轉英文
{
  char Character;
  switch(ascii)
  {
    case 100:Character='d';break;
    case 101:Character='e';break;
    case 110:Character='n';break;
    case 111:Character='o';break;
    case 112:Character='p';break;
    case 114:Character='r';break;
    case 115:Character='s';break;
    case 116:Character='t';break;
    case 117:Character='u';break;
    default:break;
    }
    return Character;
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
