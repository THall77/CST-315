/*

Tyler Allen Hall
Professor Ricardo Citro
CST-315
January 22, 2022.

This program is designed to practice multithreads,
specifically by solving the producer/consumer problem.

*/

#include <iostream>
#include <thread>
#include <mutex>
#include <ctime>

using namespace std;

mutex mtx;

int buffer[15];
int count = 0;

void producer(){

    for(int i = 0; i < 15; i++){

        int x = rand() % 100;

        mtx.lock();
        if(count < 15){

            buffer[count] = x;
            count++;

        }
        mtx.unlock();

    }

}

void consumer(){

    for(int i = 0; i < 15; i++){

        int x = 0;
        mtx.lock();
        if(count > 0){

            x = buffer[count - 1];
            count --;

        }
        mtx.unlock();

        cout << "Producer created and Consumer took " << x << endl;

    }

}




int main(){

srand(time(NULL));

thread prod(producer);
thread cons(consumer);

prod.join();

cons.join();



return 0;

}