
//testing file, REMOVE BEFORE SUBMITTING!!!

#include "htab.h"
#include "structs.h"

void print_table(htab_t *t){
    printf("Start of htab\n");
    for(int i = 0; i < (int)t->arr_size; i++){
        if (t->arr_ptr[i] == NULL){
            printf("\t%i\t---\n", i);
        }
        else{
            printf("\t%i\t ", i);
            htab_item_t *tmp = t->arr_ptr[i];
            while(tmp != NULL){
                printf("[%s, %d] - ", tmp->pair.key, tmp->pair.value);
                tmp = tmp->next;
            }
            printf("\n");
        }
    }
    printf("End of htab\n");
}


void print_pair(htab_pair_t *p){
    printf("Start of pair\n");
    printf("\tKey: %s\n", p->key);
    printf("\tValue: %i\n", p->value);
    printf("End of pair\n");
}

void disrupt(htab_pair_t *p){
    p->key = "jinyklic";
}

int main(void){
    
    htab_t *table = htab_init(8);
    //print_table(table);
    char *key = "klic";
    htab_insert(table, key);
    key = "klic2";
    htab_insert(table, "klic22");
    htab_insert(table, "klic3");
    htab_insert(table, "klic4");
    htab_insert(table, key);
    print_table(table);
    htab_for_each(table, &disrupt);
    print_table(table);
    //htab_resize(table, 4);
    //print_table(table);
    //htab_resize(table, 5);
    //print_table(table);
    //htab_resize(table, 15);
    //print_table(table);


    //htab_erase(table, "klic4");
    //htab_erase(table, "klic");
    //print_table(table);
    
    //htab_clear(table);
    //print_table(table);
    //htab_pair_t *pair = htab_lookup_add(table, "klic222255");
    //print_pair(pair);
    //print_table(table);
    
    htab_free(table);
    return 0;
}
