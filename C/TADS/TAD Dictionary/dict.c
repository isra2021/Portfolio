#include <assert.h>
#include "dict.h"
#include <stdlib.h>

struct _node_t {
    dict_t left;
    dict_t right;
    key_t key;
    value_t value;
};

dict_t dict_empty() {
  return NULL;
}

static dict_t create_node(key_t word, value_t def) {
    dict_t dict = malloc(sizeof(struct _node_t));
    dict -> key = word;
    dict -> value = def;
    dict -> left = dict_empty();
    dict -> right = dict_empty();
    return dict;
}

dict_t dict_add(dict_t dict, key_t word, value_t def) {
    if(dict == NULL){
        dict = create_node(word, def);
    }
    else if(key_eq(word, dict -> key)){
        key_destroy(dict -> key);
        value_destroy(dict -> value);
        dict -> key = word;
        dict -> value = def;
    }
    else if(key_less(word, dict -> key)){
        dict -> left = dict_add(dict -> left, word, def);
    }
    else{
        dict -> right = dict_add(dict -> right, word, def);
    }
    return dict;
}

value_t dict_search(dict_t dict, key_t word) {
    value_t def = NULL;
    if(dict != NULL && word != NULL){
        if(key_eq(word, dict -> key)){
            def = dict -> value;
        }
        else if(key_less(word, dict -> key)){
            def = dict_search(dict -> left, word);
        }
        else{
            def = dict_search(dict -> right, word);
        }
    }
    return def;
}

bool dict_exists(dict_t dict, key_t word) {
    if(!dict || !word) return false;
    bool b = false;
    if(key_eq(dict -> key, word)){
        b = true;
    }
    else if(key_less(word, dict -> key)){
        b = dict_exists(dict -> left, word);
    }
    else{
        b = dict_exists(dict -> right, word);
    }
    return b;
}

unsigned int dict_length(dict_t dict){
        if(dict == NULL) return 0;
        return (dict_length(dict -> left) + dict_length(dict -> right) + 1);
}

/*
static key_t maximo_izq(dict_t dict){
    key_t max = NULL;
    if(dict != NULL){
        if(dict -> right == NULL){
            max = dict -> key;
        }
        else{
            max = maximo_izq(dict -> right);
        }
    }
    return max;
}

static dict_t delete_max(dict_t dict) {
    if(dict -> right == NULL){
        dict_t aux = dict;
        dict = dict -> left;
        key_destroy(aux -> key);
        value_destroy(aux -> value);
        free(aux);
        aux = NULL;
    }
    else {
        dict -> right = delete_max(dict -> right);
    }
    return dict;
}
*/

/*
dict_t dict_remove(dict_t dict, key_t key) {
    dict_t result = dict;
    if(dict != NULL){
        if(key_less(key, dict -> key)){
            dict -> left = dict_remove(dict -> left, key);
        }
        if(key_less(dict -> key, key)){
            dict -> right = dict_remove(dict->right,key);
        }
        if((key_eq(key, dict -> key)) && (dict -> left == NULL)){
            result = dict -> right;
        }
        if((key_eq(key, dict -> key)) && (dict->left != NULL)){
            result -> key = maximo_izq(dict -> left);
            dict -> left = delete_max(dict -> left);
        }
    }
    return (result);
}
*/

static dict_t free_node(dict_t node) {
    key_destroy(node -> key);
    value_destroy(node -> value);
    free(node);
    return (node = NULL);
}

dict_t dict_remove(dict_t dict, key_t key) {
    dict_t result = dict;
    if(!dict || !key) return NULL;
    if(key_eq(dict->key, key)) {
        if (!dict -> left) {
            result = dict -> right;
            dict = free_node(dict);
        } else {
            dict_t father = NULL;
            dict_t max = dict->left;
            while(max -> right != NULL) {
                father = max;
                max = max -> right;
            }
            if(!father) {
                max->right = dict -> right;
                dict = free_node(dict);
                result = max;
            } else {
                dict -> key = key_destroy(dict -> key);
                dict -> value = value_destroy(dict -> value);
                dict -> key = max -> key;
                dict -> value = max -> value;
                father -> right = max -> left;
                free(max);
            }
        }
    } else if(key_less(dict -> key, key)) {
        dict -> right = dict_remove(dict -> right, key);
    } else {
        dict -> left = dict_remove(dict -> left, key);
    }

    return result;
}


dict_t dict_remove_all(dict_t dict) {
    return dict_destroy(dict);
}

void dict_dump(dict_t dict, FILE *file) {
      if(dict != NULL && file != NULL){
          dict_dump(dict -> left, file);
          key_dump(dict -> key, file);
          fprintf(file, ": ");
          value_dump(dict -> value, file);
          fprintf(file, "\n");
          dict_dump(dict -> right, file);
    }
}

dict_t dict_destroy(dict_t dict) {
    if(!dict) return NULL;
    dict -> key = key_destroy(dict -> key);
    dict -> value = value_destroy(dict -> value);
    dict -> left = dict_destroy(dict -> left);
    dict -> right = dict_destroy(dict -> right);
    free(dict);
    return (dict = NULL);
}



