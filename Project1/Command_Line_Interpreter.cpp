/*

Tyler Hall
CST-315
Professor Ricardo Citro
Feb 6, 2022

This project is designed to create a CLI in order to practice coding the beginning of our own shell. 
What it does is takes arguements, and executes them
in their own processes, each command separated by a ;.

*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <time.h>
#include <sys/wait.h>

using namespace std;

string prompt = "Enter Command: ";
int count;

int main(){

    int pid = fork();
    string user_string;
    char * args[100];
    char str[100];
    int count;

    while(1){

	cout << prompt;
	cin.getline(str,100);
	
	char *temp = strtok(str, "; ");
	
	while(temp){
	
	args[count] = temp;
	temp = strtok(NULL, " ");
	count++;
	
	
	}
	
	int i = 1;
	
	if(pid == 0){
	
	i = count / 2;
	
	} else {
	
	wait(NULL);
	i = 0;
	
	}
	
	
	for(i = 0; i <= count; i++){
	
	execv(args[i], args);
	
	}
	
	

    }


    return 0;
}
