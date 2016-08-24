#include <stdio.h>
#include <stdlib.h>

#include "list.h"



// https://www.happybearsoftware.com/implementing-a-dynamic-array
int * dois_int(int v1, int v2)
{
    int * pt = calloc(2, sizeof(int));
    if(!pt)
        die("erro to create an array of two elements");
    pt[0] = v1;
    pt[1] = v2;
    return pt;
}

void mostrar_lst(List * lst)
{
    int i, mx = size(lst);
    int * ptr;
    for(i=0; i<mx; i++){
        ptr = get(lst, i);
        printf("(%d, %d)\n", ptr[0], ptr[1]);
    }
    printf("\n");
}

int main (int argc, char *argv[])
{
    List * lst = create_list();
    int * ptr = NULL;
    
    int * tmp;
    
    add(lst, dois_int(2, 4));
    printf("All 1\n");
    mostrar_lst(lst);
    
    
    add(lst, dois_int(5, 9));
    
    printf("\nAll 2\n");
    mostrar_lst(lst);
    
    add(lst, dois_int(4, 8));
    printf("\nAll 3\n");
    mostrar_lst(lst);
    
    ptr = get(lst, 0);
    printf(">> %d\n", ptr[1]);
    printf("length of top %d\n", lst->top);
    printf("length of lista %d\n", lst->len);
    printf("\n");
    printf("All\n");
    mostrar_lst(lst);
    
    printf("out the first\n");
    
    tmp = remove_at(lst, 0);
    free(tmp);
    mostrar_lst(lst);
    
    printf("take off the last\n");
    free(remove_at(lst, 1));
    mostrar_lst(lst);
    
    printf("show again\n");
    mostrar_lst(lst);
    printf("length of top %d\n", lst->top);
    printf("length of lista %d\n", lst->len);
    
    destroy_list(lst);
    return 0;
}
