#include "Coroutine.h"
#include <malloc.h>
void turnLED(LED_t* whichLED,int state){
  whichLED->state = state;
}
void ConfigLEDAndButton(ButtonAndLEDInfo* self,int interval){
  self->LedState = IS_ON;
  self->whichLED = malloc(sizeof(LED_t)); 
  self->whichButton = malloc(sizeof(Button_t));
  self->whichLED->state = IS_ON;
  self->whichButton->state = IS_ON;
  self->interval = interval;
  self->prevTime = 0;  
  self->state = 0;
}

void ButtonAndLED(ButtonAndLEDInfo* self){
    startCoroutine();
    
    while(1){
      self->buttonHasRelease = FALSE;
      turnLED(self->whichLED,IS_OFF);
      while( readButton() == IS_RELEASED){yield();}
      
      turnLED(self->whichLED,IS_ON);
      while(readButton() == IS_PRESSED ){
        if( getTime()  - self->prevTime >= self->interval){
         if(self->LedState){
           turnLED(self->whichLED,IS_ON);
           self->LedState = ~self->LedState;
         }else{
           turnLED(self->whichLED,IS_OFF);
           self->LedState = ~self->LedState;
         }
        }
        yield();
      }
       self->buttonHasRelease = TRUE;
     while(readButton() == IS_RELEASED &&  self->buttonHasRelease == TRUE){
        if( getTime() - self->prevTime >= self->interval){
         if(self->LedState){
           turnLED(self->whichLED,IS_ON);
           self->LedState = ~self->LedState;
         }else{
           turnLED(self->whichLED,IS_OFF);
           self->LedState = ~self->LedState;
         }
        }
        yield();
     }
     
     
    }
    
    endCoroutine();
}
      
      
      
      
      
      
    
    
    
    


