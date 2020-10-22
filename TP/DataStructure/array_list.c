/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "array_list.h"
#include <stdlib.h>

/**
 * @brief La fonction init_array_list permet d'initialiser la liste à 0
 * 
 * @param l 
 */
void init_array_list(Array_list *l)
{
    l->index = 0;
}

/**
 * @brief La fonction insert_at permet d'insérer un élément dans la liste à une position donnée
 * 
 * @param l 
 * @param position 
 * @param value 
 */
void insert_at(Array_list *l, int position, float value)
{
    if (position < l->index)
    {
        for (int i = position; i < l->index; i++)
        {
            l->data[i + 1] = l->data[i];
        }
        l->data[position] = value;
        l->index++;
    }
}

/**
 * @brief La fonction add permet d'ajouer un element dans la liste
 * 
 * @param l 
 * @param value 
 */
void add(Array_list *l, float value)
{
    if (l->index < ARRAY_LIST_MAX_SIZE)
    {
        l->data[l->index++] = value;
    }
}

/**
 * @brief La fonction remove_at permet de supprimer un élément à une position donnée
 * 
 * @param l 
 * @param position 
 * @return float 
 */
float remove_at(Array_list *l, int position)
{
    float tmp = l->data[position];
    l->data[position] = 0;
    for (int i = position; i < l->index; i++)
    {
        l->data[i] = l->data[i + 1];
    }
    l->index--;
    return tmp;
}

/**
 * @brief La fonction get_at permet de récupérer l'élément d'une position donnée
 * 
 * @param l 
 * @param position 
 * @return float 
 */
float get_at(Array_list *l, int position)
{
    return l->data[position];
}

/**
 * @brief La fonction clear permet de vider la liste
 * 
 * @param l 
 */
void clear_array_list(Array_list *l)
{
    l->index = 0;
    free(l);
}