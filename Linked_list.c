#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>
#include <inttypes.h>
//=====================================

// IMPORTANT KEYBOARD KEYS(ASCII):
// BACKSPACE:
#define BKSP 8
// ENTER:
#define ENTER 13
// ESCAPE:
#define ESC 27
// SPACE:
#define SPACE 32
// TAB:
#define TAB 9
//=====================================s

// Creating the linked lists structre
//#pragma pack(1)
struct node
{
  uint8_t data;
  //uint8_t data2;
  //uint8_t data3;

  struct node *next;
};
typedef struct node node;

// This function will insert list in front.
/*
  Time Complexity is = O(1).
*/
void push(node **head_ref, uint8_t data)
{
  node *new_node = (node *) malloc(sizeof(node));

  // Malloc NULL Check.
  if(!new_node)
  {
    printf("\n Error cannot allocate memory!");
    exit(2);
  }

  // 1- put in the data
  new_node->data = data;

  //2- Make the new  node point to head.
  new_node->next = (*head_ref);

  // make the head point to the new node.
  (*head_ref) = new_node;
}

//This function will insert after given node
/*
  Time Complexity is = O(1).
*/
void insert_after(node *prev, uint8_t data)
{
  // Check if the node is the last node (== NULL).
  if(!prev)
  {
    printf("\n The previous node is NULL!\n");
    exit(1);
  }

  node *new_node = (node *) malloc(sizeof(node));

  // Malloc NULL Check.
  if(!new_node)
  {
    printf("\n Error cannot allocate memory!");
    exit(2);
  }

  // 1- put in the data
  new_node->data = data;

  // 2- Make the next of the new node is the next of the prev node.
  new_node->next = prev->next;

  //3- Make the prev node point to its next node (new node).
  prev->next = new_node;
}

// Function to add node at the end.
/*
  Time Complexity is = O(n).
*/
void append(node **head_ref, uint8_t data)
{
  node *new_node = (node *) malloc(sizeof(node));

  // Malloc NULL Check.
  if(!new_node)
  {
    printf("\n Error cannot allocate memory!");
    exit(2);
  }

  // 1- reference to the previous last node.
  node *last = *head_ref;

  // 2- Put the data.
  new_node->data = data;

  // 3- Assign the next node to NULL (because it is the last node)
  new_node->next = NULL;

  // Check if list is empty.
  if(*head_ref == NULL)
  {
    *head_ref = new_node;
    return;
  }

  // if list isn't empty, get the last element then add the node next to it.
  while(last->next)
  {
    last = last->next;
  }

  // Assign the next of previous last element to the current last element.
  last->next = new_node;
}

// Function to print the linked lists:
void print_lists(node *head)
{
  printf("\n ADDRESS\tDATA\t NEXT\n\n");
  while(head != NULL)
  {
    printf(" 0x%p\t %d\t 0x%p\n", &head->data, head->data, head->next);
    head = head->next;
  }

  printf("\n");
}

int main(void)
{
  system("COLOR 0A");

  node *head = NULL;

  //append(&head, 0);

  for(uint8_t i = 255; i > 0; i--)
  {
    push(&head, i);
  }

  print_lists(head);

  printf("\n");
  return 0;
}
