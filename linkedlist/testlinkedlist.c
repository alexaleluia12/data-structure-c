#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "linkedlist.h"


int * create_lst2(int a, int b)
{
    int *nv_lst = malloc(2*(sizeof(int)));
    assert(nv_lst != NULL);
    nv_lst[0] = a;
    nv_lst[1] = b;
    return nv_lst;
}


void show_list(List *lst)
{
    Node *node = lst->init;
    int *p;
    if(node){
        while(node){
            if(node->data){
                p = node->data;
                printf("[%d - %d]\n", p[0], p[1]);
            } else{
                die("the array of int is not alloced");
            }
            node = node->next;
        }
    }
}

int main (int argc, char *argv[])
{
    Node *no = create_node(3);
    
    printf("value of no: %d\n", no->data);
    printf("value no next: %p\n", no->next);
    List *lst = create_list();

    insert(lst, create_lst2(1, 3));
    insert(lst, create_lst2(4, 7));

    Node *third = insert(lst, create_lst2(8,2));
    insert(lst, create_lst2(83, 12));
    show_list(lst);
    printf("after move the third\n");
    remove_node(lst, third);
    show_list(lst);
    printf("after remove the first first\n");
    remove_node(lst, lst->init);
    show_list(lst);
    destroy_all(lst);
    free(no); // call destroy gives an error because 3 is on stack
    return 0;
}
