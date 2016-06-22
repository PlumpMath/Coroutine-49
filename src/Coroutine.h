#ifndef Coroutine_H
#define Coroutine_H


#define startCoroutine() \
            switch( self->state ){   \
            case 0:
#define endCoroutine()          \
            }
            
#define yield()    self->state = __LINE__; \
                    return; \
                    case __LINE__:
            
            
            
#endif // Coroutine_H
