/*


Tyler Allen Hall
CST-315
Ricardo Citro
Feb 10, 2022

The purpose of this program is to
provide an example of how Monitors work.



*/

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>

struct inventory {

    int item_amt;
    pthread_mutex_t mtx;
    pthread_cond_t stock;

};

static void init_inventory(struct inventory *inv){

    inv->item_amt = 0;
    pthread_mutex_init(&inv->mtx, NULL);
    pthread_cond_init(&inv->stock,NULL);

}

static void deposit(struct inventory *inv, int amount)
{
        pthread_mutex_lock(&inv->mtx);
        fprintf(stderr, "Amount of items:%d\n", amount);
        inv->item_amt += amount;
        pthread_cond_broadcast(&inv->stock);
        pthread_mutex_unlock(&inv->mtx);
}





