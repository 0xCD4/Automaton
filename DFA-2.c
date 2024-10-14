#include <stdio.h>
#include <stddef.h>

typedef enum { q0, q1, q2 } State;

State transition(State currentState, char symbol) {
    switch (currentState) {
        case q0:
            if (symbol == 'a') return q1;
            if (symbol == 'b') return q2;
            break;
        case q1:
            if (symbol == 'a') return q1;
            if (symbol == 'b') return q2;
            break;
        case q2:
            if (symbol == 'a') return q1;
            if (symbol == 'b') return q2;
            break;
    }
    return -1; // Invalid state transition
}

int processInput(const char *input, size_t length) {
    State currentState = q0;
    for (size_t i = 0; i < length; i++) {
        currentState = transition(currentState, input[i]);
        if (currentState == -1) return 0; // Invalid state transition
    }
    return currentState == q2; // Return 1 if final state is q2, otherwise 0
}

int main() {
    const char* input = "abbbbb";
    size_t length = 6; // Length of the input string
    if (processInput(input, length)) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }
    return 0;
}
