/*
    Author: Mohamed Wx
    Date: 6/30/2022
    Sub: This header will contain the graph functions.
*/
//!=============================> .START
#ifndef _MyGraphLib_H
#define _MyGraphLib_H

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

#define VERTICES_MAX_NUM ((const uint16_t) 10)
#define EDGES_MAX_NUM    ((const uint16_t) 10)

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

// Struct for the graph node (Linked based graph).
#pragma pack(1)
typedef struct GraphNode
{
    uint16_t destination, 
             weight;
    struct GraphNode *next;
}GraphNode;

// Struct for the graph edge parameters.
#pragma pack(1)
typedef struct GraphEdge
{
    uint16_t source, 
             destination;
    int16_t  weight;
}GraphEdge;

// Struct for the graph data structure.
#pragma pack(1)
typedef struct MyGraph
{
    struct GraphNode *head[VERTICES_MAX_NUM];
}MyGraph;


/*
----------------------------------------------------------------
!-                       DEFINED FUNCTIONS                     -
----------------------------------------------------------------
*/
// Main Functions.
MyGraph *CreateGraph(GraphEdge *, uint16_t);
//void DestroyGraph();

// Sub Functions.
void heap_allocation_validity(void *);
void printgraph(MyGraph *);

#ifdef __cplusplus
    }
#endif
//!=============================> .END
#endif // _MyGraphLib_H
