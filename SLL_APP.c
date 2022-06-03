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

typedef struct PERSON_DATA
{
  char _name[30];
  char _age[3];
  //char *_id;
  //char *_grade;
}data;

typedef struct SLL_Node
{
  struct PERSON_DATA *person_data;
  struct SLL_Node *next;
}node;

void list_append(node **head, data *data)
{
  if(!(*head))
  {
    node *new_node = (node *) malloc(sizeof(node));

    new_node->person_data = data;
    new_node->next = NULL;

    *head = new_node;
    return;
  }
  else
    if((*head))
  {
    node *traverser = *head;

    node *new_node = (node *) malloc(sizeof(node));

    new_node->person_data = data;
    new_node->next = NULL;

    while(traverser->next)
      traverser = traverser->next;

    traverser->next = new_node;
    return;
  }
  else
  {
    printf("\n unexpected error with linked list.");
    return;
  }
}

void printlist(node *head)
{
  int c = 0;

  while(head)
  {
    printf("\n [ %d ] Person Name: %s", c, head->person_data->_name);
    printf("\n [ %d ] Person Age: %s", c, head->person_data->_age);
    printf("\n");
    c++;
    head = head->next;
  }
  return;
}

void collect_data(void)
{
  int choice = 0;

  node *head = NULL;

  while(1)
  {
    printf("\n Hello to my register system. ");
    printf("\n Do you want to:");
    printf("\n [ 1 ] Insert new data?");
    printf("\n [ 2 ] View the data?");
    printf("\n [ 3 ] Exit?");
    printf("\n [ > ]: "); scanf("%d", &choice);

    if(choice == 1)
    {
      system("cls");

      // Allocating new memory for the new data input.
      data *new_person = (data *) malloc(sizeof(data));

      // Getting the persons's name.
      printf("\n Person name: ");
      scanf("%s", new_person->_name);

      // Getting the person's age.
      printf("\n Person age: ");
      scanf("%s", new_person->_age);

      // Add the data to linked list.
      list_append(&head, new_person);
      
      system("cls");
    }
    else
      if(choice == 2)
    {
      system("cls");

      if(!head)
      {
        int c = 0;

        printf("\n No data exists.\n");

        while(c++ < 500000000);
        system("cls");
      }
      else
        while(1)
        {
          char back_to_main = 'n';

          printlist(head);

          printf("\n Back to main menu?");
          printf("\n [ > ]: ");
          scanf(" %c", &back_to_main);

          if(back_to_main == 'y' || back_to_main == 'Y')
            break;

          system("cls");
        }//end while.

      system("cls");
    }
    else
      if(choice == 3)
    {
      int c = 0;
      system("cls");
      printf("\n Thanks for using the system. ");
      printf("\n Data saved.");

      while(c++ < 500000000);
      system("cls");

      break;
    }
    else
    {
      system("cls");
      int c = 0;
      printf("\n Please enter valid option. \n");
      while(c++ < 500000000);
      system("cls");
    }
  }//end while.
}

int main()
{
  //io(); // Input Output Function.
  system("COLOR 0A");

  collect_data();

  printf("\n Embedded programmer: Mohamed Wx");
  printf("\n Thanks.");

  printf("\n");
  return 0;
}
//====================================================
