/*


Tyler Allen Hall
CST-315
Ricardo Citro
Feb 10, 2022

The purpose of this program is to
provide an example of how Monitors work.



*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// This struct contains the mutex and the 
// amount of items currently in stock at a store.
struct inventory {

    int item_amt;
    int mtx;

};

// This function ensures that we have no stock to begin with,
// and that the mutex is set to 1.
void init_inventory(struct inventory inv){

    inv.item_amt = 0;
    inv.mtx = 1;

}

/*

Simply put, this function sets the mutex wither to 1 or 0.
If 0, then the store must be restocked and the "restocking thread"
waits. 

If the mutex is 1, it displays the current amount of items in the
store at the current time.


*/
void restock(struct inventory inv, int amount)
{
        int n = rand() % 2;
        inv.mtx = n;
        if(inv.mtx != 1){

            printf("Restocking items...\n"); 
            sleep(1.5);
            return;

        } 
        inv.mtx = 0;
        printf("Current amount of items: %d\n", amount);
        inv.mtx = 0;

        sleep(1.5);

}

int main(){

srand(time(NULL));

struct inventory i1;

init_inventory(i1);

while(1){

restock(i1, rand() % 10 + 1);

}


return 0;

}



