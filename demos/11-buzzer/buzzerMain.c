#include <msp430.h>
#include "libTimer.h"
#include"buzzer.h"


int main(){
  configureClocks();
  
  buzzer_init();
  int period = 0;
  
  switch(period){
   case 0:
     buzzer_set_period(689);
  
     buzzer_set_period(689);
     period++;
     
   case 1:
     buzzer_set_period(640);
     
     buzzer_set_period(689);
     period=0;
  }
  
  or_sr(0x18);

}
