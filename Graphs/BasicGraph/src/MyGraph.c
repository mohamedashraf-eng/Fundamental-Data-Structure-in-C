/*
    Author: Mohamed Wx
    Date: 6/30/2022
    Sub: This c file will contain the graph functions implementation.
*/
//!=============================> .START
/*
----------------------------------------------------------------
!-                       INCLUDED HEADERS                      -
----------------------------------------------------------------
*/

#include "../inc/MyGraphLib.h"

/*
----------------------------------------------------------------
!-                       DEFINED VARIABLES                     -
----------------------------------------------------------------
*/



/*
----------------------------------------------------------------
!-                       DEFINED FUNCTIONS                     -
----------------------------------------------------------------
*/
//!=============================> .MAIN FUNCTIONS

// Function to create a graph from scratch.
MyGraph *CreateGraph(GraphEdge *edges, uint16_t num_of_edges)
{   
    // Error handler.
    if(edges == NULL)
        error_exit("EDGES: NULL");
    if(num_of_edges > EDGES_MAX_NUM)
        error_exit("EDGES > EDGES_MAX_NUM");
        
    // Allocate a graph structure in heap.
    MyGraph *new_graph = (MyGraph *) malloc(sizeof(MyGraph));
    heap_allocation_validity((void *) new_graph);

    // initialize head pointer for all vertices
    for(uint16_t i = 0; i < VERTICES_MAX_NUM; i++)
        new_graph->head[i] = NULL;

    // Add the edges one by one.
    for(uint16_t i = 0; i < num_of_edges; i++)
    {
        // Get source & destination & weights of a vertex[i].
        uint16_t src = edges[i].source;
        uint16_t dest = edges[i].destination;
        int16_t  weight = edges[i].weight;

        // Allocate memory for the graph adj list. & Set the param.
        GraphNode *NewNode= (GraphNode *) malloc(sizeof(GraphNode));
        heap_allocation_validity((void *) NewNode);
        
        NewNode->destination = dest;
        NewNode->weight = weight;

        // Make the new node point to the current head.
        NewNode->next = new_graph->head[src];

        // Make the current head point to the new node.
        new_graph->head[src] = NewNode;
    }//end for.

    return new_graph;
}//end CreateGraph.

// Function to deallocate (destroy) a graph.
void DestroyGraph(MyGraph *graph)
{   
    UNIMPLEMENTED;
}//end DestroyGraph.
//!=============================> .SUB FUNCTIONS.

// Function to make sure that memory is allocated successfully.
void heap_allocation_validity(void *chunk_of_memory)
{
    if((void *) chunk_of_memory == NULL)
        error_exit("MALLOC: NULL");
}//end heap_allocation_validity.

// Function to print a graph.
void printgraph(MyGraph *graph)
{
    if(graph == NULL)
        error_exit("GRAPH: NULL");

    for (uint16_t i = 0; i < VERTICES_MAX_NUM; i++)
    {
        // print current vertex and all its neighbors
        GraphNode *ptr = graph->head[i];
        while (ptr != NULL)
        {
            printf("{%d -> %d} (%d)\t", i, 
            ptr->destination, 
            ptr->weight);

            ptr = ptr->next;
        }
 
        printf("\n");
    }
}//end printgraph.

//!=============================> .END
