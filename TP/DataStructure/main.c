/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: aurelio
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <assert.h>

#include "stack.c"
#include "queue.c"
#include "array_list.c"
#include "heap.c"


/**
 * @brief La fonction test_stack permet d'effectuer l'ensemble des tests des fonction associé à la pile
 * 
 */
void test_stack()
{
    printf("Lancement des tests stacks ! \n");
    Stack *s = malloc(1 * sizeof(Stack));
    init_stack(s);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    assert(peek(s) == 3);
    swap(s);
    assert(pop(s) == 1);
    dup(s);
    assert(peek(s) == 3);
    clear_stack(s);
    assert(is_stack_empty(s) == 1);
}

/**
 * @brief La fonction test_queue permet d'effectuer l'ensemble des tests des fonction associé à la file
 * 
 */
void test_queue()
{
    printf("Lancement des tests queue ! \n");
    Queue *q = malloc(1 * sizeof(Queue));
    init_queue(q);
    enqueue(q, 1);
    assert(front(q) == 1);
    dequeue(q);
     assert(front(q) == 0);
    clear_queue(q);
    assert(is_queue_empty(q) == 1);
}

/**
 * @brief La fonction test_arraylist permet d'effectuer l'ensemble des tests des fonction associé aux listes
 * 
 */
void test_arraylist()
{
    printf("Lancement des tests arraylist ! \n");
    Array_list *l = malloc(1 * sizeof(Array_list));
    init_array_list(l);
    add(l,1);
    add(l,2);
    assert(get_at(l, 1) == 2);
    insert_at(l, 1, 5);
    assert(get_at(l, 1) == 5);
    remove_at(l, 0);
    assert(get_at(l, 0) == 5);

}

/**
 * @brief La fonction test_heap permet d'effectuer l'ensemble des tests des fonction associé aux tas
 * 
 */
void test_heap()
{
      printf("Lancement des tests heap ! \n");
    Heap *h = malloc(1 * sizeof(Heap));
    Heap *src = malloc(1 * sizeof(Heap));
    init_heap(h);
    assert(is_heap_empty(h) == 1);
    push_heap(h, 3);
    push_heap(h, 2);
    push_heap(h, 1);
    assert(replace(h, 5) == 3);
    assert(peek_heap(h) == 5);
    assert(pop_heap(h) == 5);
    assert(peek_heap(h) == 2);
    assert(is_heap_empty(h) == 0);
    //Option
    float array[] = { 1, 2};
    heapify(src, array, 2);
    merge(h, src);
}



/**
 * @brief Le main est la fonction principale du code qui retourne 0 si tout s'est bien passé
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char **argv)
{
    test_stack();
    test_queue();
    test_arraylist();
    test_heap();

    return (EXIT_SUCCESS);
}
