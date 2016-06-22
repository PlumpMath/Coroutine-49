#include "mock_MockFunction.h"
#include "Coroutine.h"
#include "unity.h"


int timeTable[] = {0,80,100,150,250,300,500};

uint32_t* timePoint = ((void *)0);

uint32_t* buttonStatePointer = ((void *)0);



int fake_readButton(){

  int state = *buttonStatePointer;

  buttonStatePointer++;

  return state;

}



uint32_t fake_getTime(){

  uint32_t time = *timePoint;

  timePoint++;

  return time;

}



void setButtonPointerTable(int state[]){

  buttonStatePointer = state;

}



void resetTime(void){

  timePoint = timeTable;

}



void setUp(void)

{

  getTime_StubWithCallback(fake_getTime);

  readButton_StubWithCallback(fake_readButton);

}



void tearDown(void)

{

}



void foo(CoroutineInfo *self){

  switch( self->state ){ case 0:;

  while(1){

  self->i +=10;

  self->state = 44; return; case 44:;

  self->i +=2;

  self->state = 46; return; case 46:;

  }

  };

}



void test_coroutine(void){

  int i = 4;

  CoroutineInfo fooInfo = {0};

  while(i--){

    foo(&fooInfo);

  }

}



void test_getTime_(void){

  resetTime();

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((getTime())), (((void *)0)), (_U_UINT)61, UNITY_DISPLAY_STYLE_INT);



}





void test_readButton_(void){

  int StateTable[] = {(!0),0};

  setButtonPointerTable(StateTable);

  UnityAssertEqualNumber((_U_SINT)(((!0))), (_U_SINT)((readButton())), (((void *)0)), (_U_UINT)69, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((readButton())), (((void *)0)), (_U_UINT)70, UNITY_DISPLAY_STYLE_INT);

}



void test_configLEDandButton(void){

  ButtonAndLEDInfo* self = malloc(sizeof(ButtonAndLEDInfo));

  ConfigLEDAndButton(self,100);

  UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((self->interval)), (((void *)0)), (_U_UINT)76, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(((!0))), (_U_SINT)((self->LedState)), (((void *)0)), (_U_UINT)77, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(((!0))), (_U_SINT)((self->whichLED->state)), (((void *)0)), (_U_UINT)78, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(((!0))), (_U_SINT)((self->whichButton->state)), (((void *)0)), (_U_UINT)79, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((self->prevTime)), (((void *)0)), (_U_UINT)80, UNITY_DISPLAY_STYLE_INT);

}

void test_ButtonAndLED(void){

  resetTime();

  int StateTable[] = {0,0,(!0),(!0)};

  setButtonPointerTable(StateTable);

  ButtonAndLEDInfo* self = malloc(sizeof(ButtonAndLEDInfo));

  ConfigLEDAndButton(self,100);

  ButtonAndLED(self);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((self->buttonHasRelease)), (((void *)0)), (_U_UINT)89, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((self->whichLED->state)), (((void *)0)), (_U_UINT)90, UNITY_DISPLAY_STYLE_INT);

  ButtonAndLED(self);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((self->buttonHasRelease)), (((void *)0)), (_U_UINT)92, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((self->whichLED->state)), (((void *)0)), (_U_UINT)93, UNITY_DISPLAY_STYLE_INT);

  ButtonAndLED(self);

  UnityAssertEqualNumber((_U_SINT)(((!0))), (_U_SINT)((self->whichLED->state)), (((void *)0)), (_U_UINT)95, UNITY_DISPLAY_STYLE_INT);

  ButtonAndLED(self);

  UnityAssertEqualNumber((_U_SINT)(((!0))), (_U_SINT)((self->whichLED->state)), (((void *)0)), (_U_UINT)97, UNITY_DISPLAY_STYLE_INT);



}
