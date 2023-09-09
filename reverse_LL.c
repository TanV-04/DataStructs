#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *link;
};

void reverse(struct node *head)
{
  struct node *prev = NULL;
  struct node *ptr = head;
  struct node *next = NULL;

  while (ptr != NULL)
  {
    next = ptr->link;
    ptr->link = prev;

    // reversing
    prev = ptr;
    ptr = next;
  }
  head = prev;

  ptr = head;

  while (ptr != NULL)
  {
    printf("%d ", ptr->data);
    ptr = ptr->link;
  }
}

int main()
{
  struct node *head = (struct node *)malloc(sizeof(struct node));
  head->data = 10;
  head->link = NULL;

  struct node *current = (struct node *)malloc(sizeof(struct node));
  current->data = 20;
  current->link = NULL;
  head->link = current;

  current = (struct node *)malloc(sizeof(struct node));
  current->data = 30;
  current->link = NULL;
  head->link->link = current;

  current = (struct node *)malloc(sizeof(struct node));
  current->data = 40;
  current->link = NULL;
  head->link->link->link = current;

  reverse(head);
}