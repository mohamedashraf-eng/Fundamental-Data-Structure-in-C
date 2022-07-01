//=============================> .INC
#include "inc/MyGraphLib.h"
#include "inc/MyQueueLib.h"
// #include "inc/MyStackLib.h"
//=============================> .DATA

//=============================> .MAIN
int main(void)
{
    // Change terimnal color: GREEN.
    system("COLOR 0A");
/*
    GraphEdge myedges[] =
    {
        {1,30 ,5},
        {9,4, 7},
        {4,2, 1},
        {1,4, 3},
        {9,1, 3},
        {1,2, 4}
    };
 
    uint16_t n = sizeof(myedges) / sizeof(myedges[0]);

    MyGraph *mygraph = CreateGraph(myedges, n);

    printgraph(mygraph);
*/

    MyQueue *Q = CreateQueue();

    for(int i = 20; i > 0; i--)
        enqueue(Q, rand()%1000);
    
    printf("\n");
    qNode *temp = Q->front;
    while(temp != NULL)
     {   
        printf("%d ", temp->data);
        temp = temp->next;
     }
    printf("\n Queue size: %d", SizeofQ(Q));
    printf("\n Front-> %d", Q->front->data);
    printf("\n Rear-> %d", Q->rear->data);
    printf("\n Top-> %d", Q->top->data);

    DestroyQueue(Q);

    printf("\n");
    return 0;
}

//=============================> .FUNC
