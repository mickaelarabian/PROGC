/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "queue.h"
#include <stdlib.h>

/**
 * @brief La fonction init_queue permet d'initialiser la file à 0
 * 
 * @param q
 */
void init_queue(Queue *q)
{
    q->index = 0;
    q->start = 0;
}

/**
 * @brief La fonction enqueue permet d'ajouter un élément à l'entrée de la file
 * 
 * @param q 
 * @param value 
 */
void enqueue(Queue *q, float value)
{
    if (q->index < QUEUE_MAX_SIZE)
    {
        q->data[q->index++] = value;
    }
}

/**
 * @brief La fonction enqueue permet de retirer un element de la liste par la sortie
 * 
 * @param q 
 * @return float 
 */
float dequeue(Queue *q)
{
    if (q->index > q->start)
    {
        return q->data[q->start++];
    }
}

/**
 * @brief La fonction is_queue_empty vérifie si la file est vide ou pas
 * 
 * @param q 
 * @return true 
 * @return false 
 */
bool is_queue_empty(Queue *q)
{
    return q->index <= 0;
}

/**
 * @brief La fonction front permet de récupérer l'element à la sortie sans le retirer
 * 
 * @param q 
 * @return float 
 */
float front(Queue *q)
{
    return q->data[q->start];
}

/**
 * @brief La fonction clear permet de vider la file
 * 
 * @param q 
 */
void clear_queue(Queue *q)
{
    q->index = 0;
    free(q);
}