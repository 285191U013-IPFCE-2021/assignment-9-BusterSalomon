extern "C"{
    // Add the header files required to run your main 
    #include "..\include\dfs.h"
}

#include <stdlib.h>
#include <stdio.h>

// File for sandboxing and trying out code
int main (int argc, char **argv) {
    
    // ----- TEST PUSH AND POP
    // Init empty stack
     stack * st = NULL;

    // Make notes
    node *x = make_node (5, NULL, NULL);
    node *y = make_node (10, NULL, NULL);
    node *z = make_node (20, NULL, NULL);

    // Print notes
    printf ("Printing individual nodes num\n");
    printf ("%d\n", x->num);
    printf ("%d\n", y->num);
    printf ("%d\n", z->num);

    printf ("\n");

    // Push notes onto stack
    push (&st, x);
    push (&st, y);
    push (&st, z);

    // Pop and print testing
    printf ("Compare nodes to nodes popped from the stack\n");
    node * popped_z = pop (&st);
    printf ("%d\n", z->num == popped_z->num); // PRINTS 1 - IE. IT WORKS
    node * popped_y = pop (&st);
    printf ("%d\n", y->num == popped_y->num); // PRINTS 1 - IE. IT WORKS
    node * popped_x = pop (&st);
    printf ("%d\n", x->num == popped_x->num); // PRINTS 1 - IE. IT WORKS

    
    printf ("\n");

    // ------ TEST DFT
    printf ("Testing DFT - print should equal: 4 7 28 77 86 3 9 98\n");
     node *root = make_node (4,
			  make_node (7,
				     make_node (28,
						make_node (77,
							   NULL,
							   NULL),
						make_node (23,
							   NULL,
							   NULL)),
				     make_node (86,
						make_node (3,
							   NULL,
							   NULL),
						make_node (9,
							   NULL,
							   NULL))),
			  make_node (98,
				     NULL,
				     NULL));
    // Print Tree
    DFT(root);    

    return 0;
}