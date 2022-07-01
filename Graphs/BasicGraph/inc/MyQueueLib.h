/*
    Author: Mohamed Wx
    Date: 6/30/2022
    Sub: This header will contain the queue functions.
*/
//!=============================> .START
#ifndef _MyQueueLib_H
#define _MyQueueLib_H

#ifdef _cplusplus
    extern "C"{
#endif

/*
----------------------------------------------------------------
!-                       INCLUDED HEADERS                      -
----------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <assert.h>
#include <time.h>

/*
----------------------------------------------------------------
!-                       DEFINED VARIABLES                     -
----------------------------------------------------------------
*/

#define MAX_QUEUE_NODES    ((const uint16_t) 100)

// Standard error macro function for error handeling.
#define error_exit(ERROR_TYPE) \
({fprintf(stderr, "ERROR (File: %s -- Function: %s -- Line: %d -- Type: %s)", \
                          __FILE__,__func__,__LINE__,ERROR_TYPE); \
                          exit(-1);}) 
#define UNIMPLEMENTED \
    do { \
        fprintf(stderr, "%s:%d: %s is not implemented yet\n", \
                __FILE__, __LINE__, __func__); \
        abort(); \
    } while(0)               
        
/*
----------------------------------------------------------------
!-                       DEFINED STRUCTS                       -
----------------------------------------------------------------
*/

// Struct for the linkedl list for the Queue.
#pragma pack(1)
typedef struct qNode
{
    uint16_t data;
    struct qNode *next;
}qNode;

// Struct for the Queue parameters.
#pragma pack(1)
typedef struct MyQueue
{
    uint16_t myqueue_nodes_counter;
    qNode *front,
          *rear,
          *top;
}MyQueue;


/*
----------------------------------------------------------------
!-                       DEFINED FUNCTIONS                     -
----------------------------------------------------------------
*/

// Main Functions: Queue
MyQueue *CreateQueue(void);
void DestoryQueue(MyQueue *);
void enqueue(MyQueue *, const uint16_t);
void dequeue(MyQueue *);

// Sub Functions: Queue
qNode *CreateNode(const uint16_t);
bool Queue_IsEmpty(MyQueue *);
uint16_t SizeofQ(MyQueue *);

void heap_allocation_validity(void *);

#ifdef __cplusplus
    }
#endif
//!=============================> .END
#endif // _MyQueueLib_H