//=============================> .INC
#include "MyGraphLib.h"
//=============================> .DATA

//=============================> .MAIN
int main(void)
{
    // Change terimnal color: GREEN.
    system("COLOR 0A");

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

    printf("\n");
    return 0;
}

//=============================> .FUNC
