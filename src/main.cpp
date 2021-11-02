extern "C"{
    // Add the header files required to run your main 
    #include "..\include\dfs.h"
}

#include <stdlib.h>
#include <stdio.h>

// File for sandboxing and trying out code
int main(int argc, char **argv)
{
    printf ("HEY\n");
    // Create and initialize stack
    stack * st;
    st = (stack*) malloc (sizeof (stack));
    st->node = NULL;
    st->next = NULL;

     // Creates some nodes
    //  node *root = make_node (5, 
    //                 make_node (10, 
    //                     make_node (1, NULL, NULL), 
    //                     make_node (2, NULL, NULL)
    //                 ), 
    //                 make_node (20, NULL, NULL)
    //             );
    
    node *x = make_node (5, NULL, NULL);
    node *y = make_node (10, NULL, NULL);
    node *z = make_node (20, NULL, NULL);

    printf ("%d\n", x->num);

    // print_node (x);
    // print_node (y);
    // print_node (z);
    
    
    push (st, x);
    // push (st, y);
    // push (st, z);

    printf ("%d\n", st->node->num);

    //print_stack (st);
    

    return 0;
}