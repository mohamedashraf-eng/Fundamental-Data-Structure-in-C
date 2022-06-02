#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <windows.h>
#include <string.h>
#include <math.h>
#define IO
void io(void)
{
  #ifdef IO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

}
//====================================================

typedef struct node
{
  int data;
  struct node *next;
  struct node *prev;
}Node;

void append(Node **head, int data)
{
  if(!(*head))
  {
    Node *newNode = (Node *) malloc(sizeof(*newNode));

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = *head;

    *head = newNode;
    (*head)->prev = NULL;

    return;
  }

  else
    if((*head))
    {
      Node *newNode = (Node *) malloc(sizeof(*newNode));

      newNode->data = data;
      newNode->next = NULL;

      Node *traverser = *head;

      while(traverser->next)
        traverser = traverser->next;

      traverser->next = newNode;
      newNode->prev = traverser;
      return;
    }

  else
    return;
}

void printlist(Node *head)
{
  Node *last = NULL;

  printf("\n Forward Traverse: ");
  printf("\n HEAD=>");
  while(head)
  {
    printf("<=[%d]=>", head->data);
    last = head;
    head = head->next;
  }
  printf("NULL");

  printf("\n \n Reverse Traverse: ");
  printf("\n NULL");
  while(last)
  {
    printf("<=[%d]=>", last->data);
    last = last->prev;
  }
  printf("<=HEAD");
  return;
}
int main()
{
  //io(); // Input Output Function.
  system("COLOR 0A");

  Node *head = NULL;

  for(int i = 0; i < 5; i++)
    append(&head, i);

  printlist(head);

  printf("\n");
  return 0;
}
//====================================================
