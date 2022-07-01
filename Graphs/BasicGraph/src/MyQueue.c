/*
    Author: Mohamed Wx
    Date: 6/30/2022
    Sub: This c file will contain the queue functions implementation.
*/
//!=============================> .START
/*
----------------------------------------------------------------
!-                       INCLUDED HEADERS                      -
----------------------------------------------------------------
*/

#include "../inc/MyQueueLib.h"

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
// Function to create new queue.
MyQueue *CreateQueue(void)
{ 
    // Create new queue struct in heap.
    MyQueue *NewQueue = (MyQueue *) malloc(sizeof(MyQueue));
    heap_allocation_validity((void *) NewQueue);

    // Set the new queue parameters.
    NewQueue->top   = NULL;
    NewQueue->front = NULL;
    NewQueue->rear  = NULL;

    NewQueue->myqueue_nodes_counter = 0;

    return NewQueue;
}//end CreateQueue.

// Function to destory a queue.
void DestroyQueue(MyQueue *myqueue)
{
    // Error handler.
    if(myqueue == NULL)
        error_exit("QUEUE:NULL");

    // File the front != NULL.
    while(!Queue_IsEmpty(myqueue))
    {
        // Temporary pointer to store the previous front.
        qNode *temp = myqueue->front;

        // Let the front point to the next in the list.
        myqueue->front = myqueue->front->next;

        // Free the previous front node.
        free(temp);
    }   

    // Let the Front & Rear as NULL.
    myqueue->top   = NULL;
    myqueue->front = NULL;
    myqueue->rear  = NULL;

    // Free the queue struct.
    free(myqueue);

    return;
}//end DestroyQueue.

// Function to add new item in the queue.
void enqueue(MyQueue *myqueue, const uint16_t data)
{
    // Error handler.
    if(myqueue == NULL)
        error_exit("QUEUE:NULL");

    if(myqueue->myqueue_nodes_counter > MAX_QUEUE_NODES)
        error_exit("QUEUE_NODES > MAX_QUEUE_NODES");
   
    // Create new node.
    qNode *NewNode = CreateNode(data);

    // Check if the queue is empty.
    if(Queue_IsEmpty(myqueue))
    {
        myqueue->top   = NewNode;
        myqueue->front = NewNode;
        myqueue->rear  = NewNode;
        myqueue->myqueue_nodes_counter++; // Increase number of nodes.

        return;
    }
    // Else if the queue isn't empty.
    else
    {   
        myqueue->rear->next = NewNode; // Make the next of the current rear is the new node.
        myqueue->rear = NewNode; // Make the current rear point to the new node.
        myqueue->myqueue_nodes_counter++; // Increase number of nodes.

        // Check if the new input data is the max.
        if(NewNode->data > myqueue->top->data)
            myqueue->top = NewNode;

        return;
    }

}//end enqueue.

// Function to remove element from the queue.
void dequeue(MyQueue *myqueue)
{
    // Error handler.
    if(myqueue == NULL)
        error_exit("QUEUE:NULL");
    
    // Check if the queue is empty.
    if(Queue_IsEmpty(myqueue))
    {
        printf("\n dequeue failed. Current queue is empty\n");

        return;
    }
    // If Queue isn't empty.
    else
    {
        // Temporary pointer to store the current front (As chunk in heap).
        qNode *temp = myqueue->front;

        // Make the current front point to the next element.
        myqueue->front = myqueue->front->next;
        
        myqueue->myqueue_nodes_counter--; // Decrease number of nodes.
        
        // Check if the front becomes null.
        if(myqueue->front == NULL)
        {    
            myqueue->rear = NULL;
        }

        // Predict the future for a stupid user.
        if(myqueue->front->next == NULL)
            printf("\n Warning! Queue last element. (Please don't call the queue after the next \"dequeue()\" call)\n");

        // Free the previous front.
        free(temp);

        return;
    }

}//end dequeue.
//!=============================> .SUB FUNCTIONS.

// Function to make sure that memory is allocated successfully.
void heap_allocation_validity(void *chunk_of_memory)
{
    if(chunk_of_memory == NULL)
        error_exit("MALLOC: NULL");
}//end heap_allocation_validity.

// Sub function for the queue linked list to add new node.
qNode *CreateNode(uint16_t data)
{
    // Create new node.
    qNode *NewNode = (qNode *) malloc(sizeof(qNode));
    heap_allocation_validity((void *) NewNode);

    NewNode->data = data;
    NewNode->next = NULL;

    return NewNode;
}//end CreateNode.

// Sub function to check if the queue is empty.
bool Queue_IsEmpty(MyQueue *myqueue)
{
    // Error handler.
    if(myqueue == NULL)
        error_exit("QUEUE: NULL");

    if(myqueue->front == NULL)
        return true;
    
    return false;
}//end Queue_IsEmpty.

// Sub function to return the queue size.
uint16_t SizeofQ(MyQueue *myqueue)
{
    // Erro handler.
    if(myqueue == NULL)
        error_exit("QUEUE: NULL");
    
    return myqueue->myqueue_nodes_counter;
}//end SizeofQ.

//!=============================> .END
