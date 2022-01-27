#include <IRremote.h>
const int irReceiverPin =13;  //D7引脚 
IRrecv irrecv(irReceiverPin); 
decode_results results;
void setup()
{
  Serial.begin(115200);     //定义波特率
  irrecv.enableIRIn();    //给红外接收模块进行使能 
}
void loop() 
{
  if (irrecv.decode(&results)) //当红外接收模块接收到信号时
  { 
    if(results.value != 0xFFFFFFFF){
      Serial.println(results.value, HEX); 
    }
    irrecv.resume(); // 接收下一个信号
  } 
}
