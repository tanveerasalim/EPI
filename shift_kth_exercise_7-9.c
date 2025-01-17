#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  struct Node * link;
} Node;

Node * shift_kth(Node * rootp, int k)
{
  Node * first = rootp;

  Node * second = rootp;

  int d = k;

  while (d > 1)
  {
    second = ((second)->link);

    d--;
  }

  while (((second)->link) != NULL)
  {
    second = ((second)->link);

    first = ((first)->link);
  }

  ((second)->link) = (rootp);

  while ( ((rootp)->link) != (first) )
  {
    rootp = ((rootp)->link);
  }

  ((rootp)->link) = NULL;

  return (first);
}

void print_list_dpp(Node ** rootp)
{
  if (rootp == NULL || *rootp == NULL)
  {return;}

  while ((*rootp) != NULL)
  {
    printf("%p ",*rootp);

    rootp = &((*rootp)->link);
  }
  printf("\n\n");
}

void print_list_spp(Node * root)
{
  if ( root == NULL)
  { return; }

  while ( root != NULL)
  {
    printf("%p ",root);

    root = root->link;
  }
  
  printf("\n\n");
}


int main(void) 
{
  
  
  Node * first = (Node *)malloc(sizeof(Node));

  Node * first_cpy = first;

  Node * second = (Node *)malloc(sizeof(Node));

  Node * third = (Node *)malloc(sizeof(Node));

  first->link = second;

  second->link = third;

  third->link = NULL;

  print_list_spp(first);

  Node * result = shift_kth(first,);

  print_list_spp(result);

#if 0

  if ( first_cpy == first) {free(first);}

  free(first_cpy);

  free(second);

  free(third);

#endif
}
