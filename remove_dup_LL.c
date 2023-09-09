#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *link;
};

void duplicate(struct node *head)
{
  int flag = 0;
  struct node *ptr = head;

  while (ptr != NULL && ptr->link != NULL)
  {
    struct node *p = ptr;
    while (p->link != NULL)
    {
      if (p->link->data == ptr->data) //check if the data in p's next node is equal to the ptr->data 
      {
        struct node *dup = p->link; //hold reference
        p->link = p->link->link; // point to the next to next node;
        free(dup); //free the memory/duplicate node
      }
      else
      {
        p = p->link; //move to the next node 
      }
    }
    ptr = ptr->link;
  }
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
  current->data = 30;
  current->link = NULL;
  head->link->link->link = current;

  duplicate(head);
}