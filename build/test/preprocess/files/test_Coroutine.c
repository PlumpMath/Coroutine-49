#include "Coroutine.h"
#include "unity.h"


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

  switch( self->state ){ case 0:;



  self->i +=10;

  self->state = 22; break; case 22:;



  self->i +=2;



  self->state = 26; break; case 26:;



  };



  }







void test_coroutine(void){



  int i = 4;

  CoroutineInfo fooInfo = {0};



  while(i--){

    foo(&fooInfo);



  }





}
