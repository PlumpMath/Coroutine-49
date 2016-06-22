#include "unity.h"
#include "Coroutine.h"
#include "mock_MockFunction.h"
#include <malloc.h>

int timeTable[] = {0,80,100,150,250,300,500};
uint32_t* timePoint = NULL;
uint32_t* buttonStatePointer = NULL;

int fake_readButton(){
  int state  = *buttonStatePointer;
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
  startCoroutine();
  while(1){
  self->i +=10;
  yield();
  self->i +=2;
  yield();
  }
  endCoroutine();
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
 TEST_ASSERT_EQUAL(0,getTime());
 //TEST_ASSERT_EQUAL(100,getTime());
}


void test_readButton_(void){
  int StateTable[] = {IS_ON,IS_OFF};
  setButtonPointerTable(StateTable);
  TEST_ASSERT_EQUAL(IS_ON,readButton());
  TEST_ASSERT_EQUAL(IS_OFF,readButton());
}

void test_configLEDandButton(void){
  ButtonAndLEDInfo* self = malloc(sizeof(ButtonAndLEDInfo));
  ConfigLEDAndButton(self,100);
  TEST_ASSERT_EQUAL(100,self->interval);
  TEST_ASSERT_EQUAL(IS_ON,self->LedState);
  TEST_ASSERT_EQUAL(IS_ON,self->whichLED->state);
  TEST_ASSERT_EQUAL(IS_ON,self->whichButton->state);
  TEST_ASSERT_EQUAL(0,self->prevTime);
}
void test_ButtonAndLED(void){
  resetTime();
  int StateTable[] = {IS_RELEASED,IS_RELEASED,IS_PRESSED,IS_PRESSED};
  setButtonPointerTable(StateTable);
  ButtonAndLEDInfo* self = malloc(sizeof(ButtonAndLEDInfo));
  ConfigLEDAndButton(self,100);
  ButtonAndLED(self); //IS_RELEASED
  TEST_ASSERT_EQUAL(FALSE,self->buttonHasRelease);
  TEST_ASSERT_EQUAL(IS_OFF,self->whichLED->state);
  ButtonAndLED(self); //IS_RELEASED
  TEST_ASSERT_EQUAL(FALSE,self->buttonHasRelease);
  TEST_ASSERT_EQUAL(IS_OFF,self->whichLED->state);
  ButtonAndLED(self); //IS_PRESSED,getTime = 0;
  TEST_ASSERT_EQUAL(IS_ON,self->whichLED->state);
  ButtonAndLED(self); //IS_PRESSED,getTime = 80;
  TEST_ASSERT_EQUAL(IS_ON,self->whichLED->state);
  
}
