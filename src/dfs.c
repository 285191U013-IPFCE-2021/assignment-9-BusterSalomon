/*
 * Search an expression using DFS.
 */

#include <stdio.h>		/* scanf, printf */
#include <stdlib.h>		/* abort */
#include <stdbool.h>		/* bool, true, false */
#include "..\include\dfs.h"

/*
PROBLEM SOLVING STEPS

1. Push the root to the stack

  stack:
  _______
  root
  _______

2. Print the num of the root
3. Set visited to true

4. Check if the root have any left and right childs
  * if a left child exist, then push it to the stack
  * if both exist, then first push the right one

  stack:

  ______
  left_1
  ______
  right_1
  ______
  root
  ______

5. Print the num of the first elem on the stack
6. If the child doesnt have any childs, then pop it and visit the old child


*/



void DFT (node * root) {

    // CREATE A NEW STACK AND INITIALIZE IT TO NULL
    stack * sp = NULL;

    // PUSH ROOT TO THE STACK
    push (&sp, root);

    // MAKE A LOOP TO RUN TROUGH THE TREE
    while (sp != NULL) {

        // Local variabels
        node * current_node = sp->node;
        node * lchild = current_node->lchild;
        node * rchild = current_node->rchild;

    
        // Conditionally push childs
        if (rchild != NULL && !rchild->visited) {
            push (&sp, rchild);
        }
        if (lchild != NULL && !lchild->visited) {
            push (&sp, lchild);
        }

        // Pop current node if we have traversed to and end or it have already been visited
        // Not neccesary to check (rchild->visited && lchild->visited) as current_node->visited does the job
        if ((lchild == NULL && rchild == NULL) || current_node->visited ) { 
            pop (&sp);
        }

        // Update visited and print if not visited yet
        if (current_node->visited == false) {
            current_node->visited = true;
            printf ("%d ", current_node->num);
        }

}       


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

// topp is a double pointer, ie. it contains the address 
// of where the address of the stack is stored
// This is so the address of the stack can be modified
void push (stack ** topp, node * node) {
    // Makes new stack element
    stack * newStack;
    newStack = (stack*) malloc (sizeof (stack));

    // Set the new stack values
    newStack->next = *topp;
    newStack->node = node;

    // Update topp
    *topp = newStack;
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

// For double pointer reasoning - check comment above push
node *pop (stack ** topp) {
    if (*topp == NULL) return 0;

	// Tempoaraly storing
    stack * toFree = *topp;
    node * the_node = (*topp)->node;

    // Set new entrance point to the stack
    *topp = (*topp)->next;

    // Frees old entrance point
    free (toFree);

    // Return adress of the node
    return the_node;
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
