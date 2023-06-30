
#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

typedef struct list List;

struct list{

  int info;
  List *next;

};

List* create_list(void){

  return NULL;

}

List* list_insert(List* list, int value){

  List* new_list = (List*)malloc(sizeof(List));
  new_list->info = value;
  new_list->next = list;

  return new_list;

}

void list_print(List* list){

    List* p;

    for(p = list; p != NULL; p = p->next){

        printf("%d\n", p->info);

    }

}

int list_empty(struct List* list){

    return (list == NULL);

}

List* list_search(struct List* list, int v){

    List* p;

    for(p = list; p != NULL; p = p->next){

        if(p->info == v){

            return p;

        }

List* remove_item(List* list, int val){

    List* prev = NULL;
    List* p = list;

    while(p != NULL && p->info != val){

        prev = p;
        p = p->next;

    }

    if(p == NULL){

        return list;

    }

    if(prev == NULL){

        list = p->next;

    }

    else{

        prev->next = p->next;

    }

    free(p);
    return list;

}

List* ordenate_insert(struct List* list, int value){

    List* new_list;
    List* prev = NULL;
    List* p = list;


    while(p != NULL && p->next < value){

        prev = p;
        p = p->next;

    }

    new_list = (List*) malloc(sizeof(List));
    new_list->info = value;


    }

    else{

        new_list->next = prev->next;
        prev->next = new_list;

    }

    return list;

}

void list_free(List* list){

    List* t;
    List* p = list;

    while(p != NULL){

        t = p->next;

        free(p);

        p = t;

    }
}

int list_equal(List* list1, List* list2){

    List* p1;
    List* p2;

    for(p1 = list1, p2 = list2; p1 != NULL && p2 != NULL; p1 = p1->next, p2 = p2->next){

        if(p1->info != p2->info){

            return 0;

        }
    }

    return p1==p2;

}

