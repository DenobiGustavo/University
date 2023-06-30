
#ifndef LISTS_H
#define LISTS_H

typedef struct list List;

struct lists{

  int info;
  List *next;

};

//create a new list
List* create_list(void);
//insert a new value at the start of the list
List* list_insert(List* list, int value);
//remove a value at the list
List* list_remove(List* list, int value);
//print a list
void  list_print(List* list);
//search a value at the list
List* list_search(List* list, int value);
//check if the list is empty
int list_empty(List* list);
//free all values at the list
void list_free(List* list);
//insert values in order
List* list_insert_in_order(List* list, int value);
//checks if the lists are equal
int list_equal(List* list1, List* list2);

#endif




