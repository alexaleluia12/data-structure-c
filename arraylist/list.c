#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "list.h"


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


List * create_list()
{
    List *lst = calloc(1, sizeof(List));
    if(!lst)
        die("nao dei para criar a lista");
    lst->lst_elements = calloc(1, sizeof(void *));
    lst->len = 1;
    lst->top = 0;
    return lst;
}

void destroy_list(List * lst)
{
    if(lst){
        if(lst->lst_elements) desalloc(lst);
        free(lst);
    }
}

void * get(List * lst, int i)
{
    if(i < 0 || i >= lst->top){
        char tmp_str[50];
        sprintf(tmp_str, "Index not valid on get, %d", i);
        die(tmp_str);
    }
    return lst->lst_elements[i];
}

void * set(List * lst, int i , void * element)
{
    if(i < 0 || i >= lst->top)
        die("Index not valid on set");
    void * old = lst->lst_elements[i];
    lst->lst_elements[i] = element;
    return old;
}

void add(List * lst, void * element)
{
    if(lst->top == lst->len)
        resize(lst);
    lst->lst_elements[lst->top] = element;
    lst->top++;
}

void * remove_at(List * lst, int i)
{
    if(i < 0 || i > lst->top)
        die("Indice not valid on remove");
    void * excluded = lst->lst_elements[i];
    int max = lst->top - 1;
    for(; i<max; i++){
        memcpy(&lst->lst_elements[i], &lst->lst_elements[i+1], sizeof(void *));
        // lst->lst_elements[i] = lst->lst_elements[i+1];
    }
    lst->top--;
    if(lst->len >= 3*lst->top)
        resize(lst);
    return excluded;
    
}

int size(List * lst)
{
    return lst->top;
}

void resize(List * lst)
{
    int mx_value = max(1, (2*lst->top));
    void ** nw_array = calloc(mx_value, sizeof(void *));
    if(!nw_array)
        die("the new array was not created\n");
    
    
    int i;
    for(i=0; i<lst->top; i++){
        memcpy(&nw_array[i], &lst->lst_elements[i], sizeof(void *));
        // nw_array[i] = lst->lst_elements[i];
    }
    // desalloc all the array alloced in (create_list or here)
    free(lst->lst_elements);
    
    
    lst->len = mx_value;
    lst->lst_elements = nw_array;
    
}

// should be called just once
void desalloc(List * lst)
{
    int i, max = lst->top;
    if(lst->lst_elements){
        for(i=0; i<max; i++){
            // desalloc all the array's content
            if(lst->lst_elements[i] != NULL){
                void * obj = lst->lst_elements[i];
                free(obj);
            } 
        }
        free(lst->lst_elements);
    }
    
}

int max(int v1, int v2)
{
    if(v1 >= v2) return v1;
    return v2;
}
