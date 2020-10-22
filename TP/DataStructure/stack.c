/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "stack.h"
#include <stdlib.h>

/**
 * @brief La fonction init_stack permet d'initialiser la pile à 0
 * 
 * @param s 
 */
void init_stack(Stack *s)
{
    s->index = 0;
}

/**
 * @brief La fonction push permet d'ajouter un element au dessus de la pile
 * 
 * @param s 
 * @param value 
 */
void push(Stack *s, float value)
{
    if (s->index < STACK_MAX_SIZE)
    {
        s->data[s->index++] = value;
    }
}

/**
 * @brief La fonction pop permet de retirer le dernier element ajouté à la pile
 * 
 * @param s 
 * @return float 
 */
float pop(Stack *s)
{
    if (s->index > 0)
    {
        --s->index;
        return s->data[s->index];
    }
}

/**
 * @brief La fonction is_stack_empty vérfie si la pile est vide ou pas
 * 
 * @param s 
 * @return true 
 * @return false 
 */
bool is_stack_empty(Stack *s)
{
    return s->index <= 0;
}

/**
 * @brief La fonction peek permet de récupérer l'element au sommet de la pile non sans le supprimer
 * 
 * @param s 
 * @return float 
 */
float peek(Stack *s)
{
    if (s->index > 0)
    {
        return s->data[s->index - 1];
    }
}

/**
 * @brief La fonction dup duplique le sommet de la pile
 * 
 * @param s 
 */
void dup(Stack *s)
{
    if(s->index > 0){
        s->data[s->index] = peek(s);
    }
}

/**
 * @brief La fonction swap permet d'échanger la position des éléments se trouvant aux sommets de la pile
 * 
 * @param s 
 */
void swap(Stack *s)
{
    float tmp;
    if (s->index >= 1)
    {
        tmp = pop(s);
        s->data[s->index-1] = s->data[0];
        s->data[0] = tmp;
    }
}

/**
 * @brief La fonction clear_stack permet de vider la pile
 * 
 * @param s 
 */
void clear_stack(Stack *s)
{
    s->index = 0;
    free(s);
}