#include "unity.h"
#include "Coroutine.h"

void setUp(void)
{
}

void tearDown(void)
{
}

typedef struct{
  int state;
  int i;
  
}CoroutineInfo;

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