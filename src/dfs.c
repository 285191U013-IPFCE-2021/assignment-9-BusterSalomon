/*
 * Search an expression using DFS.
 */

#include <stdio.h>		/* scanf, printf */
#include <stdlib.h>		/* abort */
#include <stdbool.h>		/* bool, true, false */
#include "..\include\dfs.h"


void DFT (node * root)
{
	// Implement DFS
	// Hint: You can use print_node, print_tree and/or print_stack.

}

node *make_node (int num, node * left, node * right) {
    node *newNode;
    newNode = (node*) malloc (sizeof (node));
    newNode->num = num;
    newNode->lchild = left;
    newNode->rchild = right;
    newNode->visited = false;
	return newNode;
}

void free_node (node * p)
{
	
}


void print_node (node * p)
{

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("%d", p->num);
}


void print_tree (node * p, int depth)
{
  for (int i = 0; i < depth; i = i + 1)
    printf (" ");
  printf ("| ");

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("[%d]\n", p->num);


  if (p->lchild)
    {
      print_tree (p->lchild, depth + 1);
    }

  if (p->rchild)
    print_tree (p->rchild, depth + 1);
}

stack *push (stack * topp, node * node) {
    // Makes new stack element
    stack * newStack;
    newStack = (stack*) malloc (sizeof (stack));

    // Set the new stack values
    newStack->next = topp;
    newStack->node = node;

    // Update topp
    topp = newStack;
    
    return newStack;
}

bool isEmpty (stack * topp)
{
  return false;
}

node *top (stack * topp)
{
	return 0;
}

// Utility function to pop topp  
// element from the stack 

stack *pop (stack * topp) {
    if (topp == NULL) return 0;

	// Tempoaraly storing
    stack * toFree = topp;
    node * the_node = topp->node;

    // Set new entrance point to the stack
    topp = topp->next;

    // Frees old entrance point
    // free (toFree);

    // Return adress of the node
    return toFree;
}

void print_stack (stack * topp)
{
  struct stack *temp = topp;

  while (temp != NULL)
    {

      print_node (temp->node);
      printf ("\n");

      temp = temp->next;
    }

  printf ("====\n");

  return;
}
