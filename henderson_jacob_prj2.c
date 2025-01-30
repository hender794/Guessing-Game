/*
* Auth: Jake Henderson
* Date: 11-09-24 (Due: 11-14-24)
* Course: CSCI-4350
* Desc: Project 2
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

#define MAX 10
#define MIN 1

int generate(int generated[], int cnt);
int find(int generated[], int num, int cnt);
int findBalls(int generated[], int input[], int cnt);
int findStrikes(int generated[], int input[], int cnt);
int inputValues(int valid, int input[], int cnt);

int main( void ) {
	int valid = 0;
	int generated[3];
	int input[3];
	int cnt = 3;
	int balls;
	int strikes;
	int i;
	int finish = 0;
	char play;
	generate(generated, cnt);
    
	while(finish == 0){
		inputValues(valid, input, cnt);

	    balls = findBalls(generated, input, cnt);
		strikes = findStrikes(generated, input, cnt);

		if(strikes == 3) {
			finish = 1;
		}	
		else{
			printf("%d balls, %d strikes \n", balls, strikes);
		}
	}

    printf("Good job! Do you want to play again? (Y/N): \n");
    getchar();
	scanf(" %c", &play);

	if(play == 'Y' || play == 'y'){
		main();
	}
	else{
		return 0;
		}
	return 0;
}

int inputValues(int valid, int input[], int cnt){
	while(valid < 3){
		int i = 0;

    	printf("Enter 3 integers(1-9): ");
    
	    for (i = 0; i < cnt; i++) {
	        scanf("%d", &input[i]);
	        if (input[i] < 1 || 9 < input[i]) {
	    		printf("Please try again!\n");
	    		while (getchar() != '\n');
                break;		    	}
	    	else {
	    		valid = valid + 1;
	    	}
	    }
	}
	return 0;
}

int findBalls(int generated[], int input[], int cnt){
	int i = 0;
	int num_balls = 0;

	for(i = 0; i < cnt; i++) {
		int balls_idx = find(generated, input[i], cnt);
		if(balls_idx != -1 && balls_idx != i){
			num_balls++;
		}
	}
	return num_balls;
}


int findStrikes(int generated[], int input[], int cnt){
	int i = 0;
	int num_strikes = 0;

	for(i = 0; i < cnt; i++) {
		int strikes_idx = find(generated, input[i], cnt);
		if(strikes_idx != -1 && strikes_idx == i){
			num_strikes++;
		}
	}
	return num_strikes;
}

int generate(int generated[], int cnt) {
	int i = 0;
	int num = 0;

	while (i < cnt) {
		num = rand() % 9 + 1;
		if (find(generated, num, i) == -1) {
			generated[i] = num;
			i++;
		}
	}
	find(generated, num, cnt);

	return 0;
}

int find(int generated[], int num, int cnt) {
	int i;
	int value = -1;

	for (i = 0; i < cnt; i++) {
        if (generated[i] == num){
        	value = i;
        	return value;
        }
    }
    return value;
}
