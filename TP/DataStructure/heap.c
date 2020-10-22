/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "heap.h"
#include <stddef.h>

/**
 * @brief La fonction init_heap permet d'initialiser le tas à 0
 * 
 * @param h 
 */
void init_heap(Heap *h)
{
    h->index = 0;
}

/**
 * @brief La fonction is_heap_empty permet de vérifier si le tas est vide ou pas
 * 
 * @param h 
 * @return true 
 * @return false 
 */
bool is_heap_empty(Heap *h)
{
    return h->index <= 0;
}

/**
 * @brief La fonction pop_heap permet de recupérer l'element root
 * 
 * @param h 
 * @return float 
 */
float pop_heap(Heap *h)
{
    float tmp = h->data[0];
    for (int i = 0; i < h->index; i++)
    {
        h->data[i] = h->data[i + 1];
    }

    h->index--;
    return tmp;
}

/**
 * @brief La fonction push_heap permet d'ajouter un element au tas
 * 
 * @param h 
 * @param value 
 */
void push_heap(Heap *h, float value)
{
    if (h->index < HEAP_MAX_SIZE)
    {
        if (value > h->data[0])
        {
            float tmp = h->data[0];
            h->data[0] = value;
            for (int i = 1; i < h->index; i++)
            {
                h->data[i] = h->data[i + 1];
            }
            h->index++;
        }
        else
        {
            h->data[h->index++] = value;
        }
    }
}

/**
 * @brief La fonction replace permet de remplacer l'element root par un nouvel element
 * 
 * @param h 
 * @param value 
 * @return float 
 */
float replace(Heap *h, float value)
{
    float tmp = h->data[0];
    h->data[0] = value;
    return tmp;
}

/**
 * @brief La fonction peek_heap permet de retourner l'élément root sans l'enlever
 * 
 * @param h 
 * @return float 
 */
float peek_heap(Heap *h)
{
    if (h->index > 0)
    {
        return h->data[0];
    }
}

/**
 * @brief La fonction merge permet de fusionné un tas source sur un tas de destination
 * 
 * @param dest 
 * @param src 
 */
void merge(Heap *dest, Heap *src)
{
    for (int i = 0; i < src->index; i++)
    {
        push_heap(dest, src->data[i]);
    }
}

/**
 * @brief La fonction heapify permet de créer un tas à partir d'un taleau
 * 
 * @param s 
 * @param array 
 * @param array_size 
 */
void heapify(Heap *s, float array[], size_t array_size)
{
    s->index = array_size;
    for (int i = 0; i < s->index; i++){
        s->data[i + 1] = array[i];
    }
}