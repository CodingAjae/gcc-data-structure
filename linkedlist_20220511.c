#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  struct node *prev;
  struct node *next;
  int val;
} t_node;

t_node* create(int val)
{
  t_node *p = (t_node*)malloc(sizeof(t_node));
  p->val = val;
  p->prev = NULL;
  p->next = NULL;
  return p;
}

t_node *first, *last;

void node_start()
{
  first = NULL;
  last = NULL;
}

void node_append(int val)
{
  if(first == NULL)
  {
    first = create(val);
    first->next = first;
    first->prev = first;
    last = first;
  }
  else
  {
    t_node* p = create(val);
    p->next = last->next;
    p->prev = last;
    p->prev->next = p;
    first->prev = p;
    last = p;
  }
}

void node_disp()
{
  t_node *p = first;
  while(1)
  {
    printf("# %02d (%02d) %02d\n", p->prev->val,p->val,p->next->val);
    if( p->next == first ) break;
    p = p->next;
  }
}

int main(int args, char** argv)
{
 node_start();

 int i = 0;
 for(i=1; i<10;i++)
 {
   node_append(i);
 }

 node_disp();
 return 0;
}
