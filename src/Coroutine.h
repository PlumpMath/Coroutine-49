#ifndef Coroutine_H
#define Coroutine_H
#include <stdint.h>

#define startCoroutine() \
            switch( self->state ){   \
            case 0:
#define endCoroutine()          \
            }
            
#define yield()    self->state = __LINE__; \
                    return; \
                    case __LINE__:
#define FALSE 0
#define TRUE (!FALSE)

#define IS_RELEASED 0
#define IS_PRESSED  (!IS_RELEASED)

#define IS_OFF 0
#define IS_ON  (!IS_OFF)
typedef struct{
  int state;
  int i;
  
}CoroutineInfo;


typedef struct{
 int state;
}LED_t,Button_t;

            
typedef struct{
  int state;
  int buttonHasRelease;
  uint32_t prevTime;
  uint32_t interval;
  uint32_t LedState;
  LED_t* whichLED;
  Button_t* whichButton;
}ButtonAndLEDInfo;      



            
#endif // Coroutine_H
