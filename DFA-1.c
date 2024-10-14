#include <stdio.h>



typedef enum {X,Y,Z} State;

void transition(State* currentstate, char input){

    switch (*currentstate)
    {
    case X:
        if(input == 'a'){
            *currentstate = X;
        }else if(input == 'b'){
            *currentstate = Y;
        }
        break;

    case Y:
        if(input == 'a'){
            *currentstate = X;
        }else if(input == 'b'){
            *currentstate = Z;
        }
        break;

    case Z:
        *currentstate = Z;
        break;
    }
}

int main(){

    char inputstring[100];
    State currentState = X; // initial state
    printf("Enter the input string (a and b characters):");
    scanf("%s", inputstring);

    // abaa

    for(int i = 0; inputstring[i] !='\0';i++){
        transition(&currentState, inputstring[i]);
        if(currentState == Z && inputstring[i] == 'b'){
            break;
        }
    }

    // Accepted or rejected check
    if(currentState == Z){
        printf("Rejected: Reached state at Z.\n ");
    } else{
        printf("Accepted: Final state is %d.\n", currentState);
    }


}
