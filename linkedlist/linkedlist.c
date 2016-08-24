#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>


#include "linkedlist.h"


void die(char *message)
{
    if(errno){
        perror(message);
    }
    else {
        printf("ERRO: %s\n", message);
        exit(1);
    }
}


List *create_list()
{
    List *new_list = calloc(1, sizeof(List));
    assert(new_list != NULL);
    return new_list;
}


Node *create_node(void *value)
{
    Node *new_node = calloc(1, sizeof(Node));
    assert(new_node != NULL);
    assert(value != NULL);
    new_node->data = value;
    return new_node;
}


void destroy(Node *node)
{
    if(node){
        free(node->data);
        free(node);
    }
}


void destroy_all(List *lst)
{
    Node *node = lst->init;
    Node *before;
    if(node == NULL)
        return;
    while(node->next){
        before = node->next;
        destroy(node);
        node = before;
    }
    destroy(node);
    free(lst);
}


Node * insert(List *lst, void *data)
{
    Node *node = lst->init;
    Node *created = NULL;
    if(!node){
        created = create_node(data);
        lst->init = created;
    }
    else {
        while(node->next != NULL){
            node = node->next;
        }
        created = create_node(data);
        node->next = created;
    }

    return created;
}


// remove *node at *lst
void remove_node(List *lst, Node *node)
{
    Node *prev, *current;
    current = lst->init;
    prev = current;
    assert(current);
    if(node == current){
        lst->init = current->next;
        destroy(current);
    } else {
        while(node != current && current != NULL){
            prev = current;
            current = current->next;
        }
        if(current){
            prev->next = current->next;
            destroy(current);
        } else {
            die("the elemento none is not in the list");
        }
    }

}


Node *get_last_node(List *lst)
{
    Node *prev, *current;
    current = lst->init;
    prev = current;
    assert(current);

    while(current){
        prev = current;
        current = current->next;
    }
    return prev;
}


int size(List *lst)
{
    int count = 0;
    Node *node = lst->init;
    if(node){
        while(node){
            count++;
            node = node->next;
        }
    }
    
    return count;
}

