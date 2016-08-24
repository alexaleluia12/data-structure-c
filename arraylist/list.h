#ifndef __LIST_H__
#define __LIST_H__

typedef struct {
    void ** lst_elements;
    int len;
    int top;
} List;

void die(char *message);
List * create_list();
void destroy_list(List * lst);
void * get(List * lst, int i);
void * set(List * lst, int i , void * element);
void add(List * lst, void * element);
void * remove_at(List * lst, int i);
int size(List * lst);
void resize(List * lst);
void desalloc(List * lst);
int max(int v1, int v2);

#endif /* __LIST_H__ */



