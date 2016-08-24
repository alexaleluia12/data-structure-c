#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

struct Node {
    void *data;
    struct Node *next;
};

typedef struct Node Node;

typedef struct {
    Node *init;
} List;

void die(char *message);
List *create_list();
Node *create_node(void *value);
void destroy(Node *node);
void destroy_all(List *lst);
Node * insert(List *lst, void *data);
void remove_node(List *lst, Node *node);
Node *get_last_node(List *lst);
int size(List *lst);


#endif /* __LINKEDLIST_H__ */

