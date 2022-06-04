#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>
#define IO
void io(void)
{
  #ifdef IO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

}
//====================================================

typedef struct DLL_NODE
{
  const char *url;
  struct DLL_NODE *next;
  struct DLL_NODE *prev;
}node;

void create_new(node **head, const char *homepage)
{
  node *new_tab  = (node *) malloc(sizeof(node));

  //int url_size = strlen(homepage);

  // Create memory for the homepage url and store it.
  //new_tab->url = (char *) malloc(sizeof(char) * url_size);
  new_tab->url = homepage;

  new_tab->next = NULL;
  new_tab->prev = NULL;

  *head = new_tab;

  return;
}

void append_url(node **head, const char *url)
{
  if(!(*head))
  {
    create_new(head, url);
    return;
  }
  else
    if((*head))
  {
    node *new_tab = (node *) malloc(sizeof(node));
    node *traverser = *head;

    while(traverser->next)
      traverser = traverser->next;

    new_tab->url  = url;
    new_tab->next = NULL;
    new_tab->prev = traverser;

    traverser->next = new_tab;

    return;
  }
  else
    return;
}

node *open_tab(node *head, const char *url)
{
  if(!head)
    return NULL;

  else
  {
    while(head)
    {
      head = head->next;

      if(head->url == url)
        return head;
    }
  }

  return NULL;
}

void close_tab(node *head, node *current, ...)
{
  // If user wanted to close specific tab with url.
  va_list url; // Variadic buffer.
  va_start(url, current); // Variadic pointer base.

  // Store the wanted url.
  char *wanted_url = (char *) va_arg(url, int);

  while(head->url != wanted_url)
    head = head->next;

  head->prev->next = head->next;

  free(head);

  va_end(url);

  return;
}

void printlist(node *head)
{
  int c = 0;
  printf("\n Current opened tabs(urls):");
  while(head)
  {
    printf("\n tab[%d]: %s", c++, head->url);
    head = head->next;
  }

  return;
}

int main()
{
  //io(); // Input Output Function.
  system("COLOR 0A");

  const char *urls[] = {"www.homepage.com",
                        "www.google.com",
                        "www.facebook.com",
                        "www.linkedin.com",
                        "wwww.youtube.com"};

  node *head = NULL, *current = NULL;

  //printf("\n URL: %s", urls[0]);

  // Opens the browser (Fresh start with homepage)
  create_new(&head, urls[0]);

  // Starts to explore. (Assumed user opens <SITE_URL: XX>)
  // i represents the tab(url) in sequence.
  for(int i = 1; i < 5; i++)
    append_url(&head, urls[i]);


  // Assume user opens an already opened tab. (Track the current opened tab)
  current = open_tab(head, urls[3]);

  // Assume user to close the current tab / any other tab.
  close_tab(head, current, urls[1]);

  // Track tabs. (printing the urls opened)
  printlist(head);

  printf("\n");
  return 0;
}
//====================================================
