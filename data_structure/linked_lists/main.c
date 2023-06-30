#include <stdio.h>
#include "lists.h"

int main(){

  List* list = create_list();

  list = list_insert(list, 3);

  list_print(list);

}
