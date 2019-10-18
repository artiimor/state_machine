#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "state_machine.h"
#include "state.h"
#include "transition.h"

#include "types.h"
int main()
{
    state *Q0, *Q1, *Q2, *Q3, *QF;
    transition *f1, *f2, *f3, *f4;

    state *all_states[5];

    transition *all_transitions[4];

    state_machine *state_machine;

    Q0 = state_create(INITIAL, 0);
    Q1 = state_create(OTHER, 1);
    Q2 = state_create(OTHER, 2);
    Q3 = state_create(OTHER, 3);
    QF = state_create(FINAL, 4);

    all_states[0] = Q0;
    all_states[1] = Q1;
    all_states[2] = Q2;
    all_states[3] = Q3;
    all_states[4] = QF;

    f1 = transition_new(Q0, 'h', Q1);
    f2 = transition_new(Q1, 'o', Q2);
    f3 = transition_new(Q2, 'l', Q3);
    f4 = transition_new(Q3, 'a', QF);

    all_transitions[0] = f1;
    all_transitions[1] = f2;
    all_transitions[2] = f3;
    all_transitions[3] = f4;

    /*
    state_print(state_array_1[0]);
    transition_print(f1);*/

    state_machine = state_machine_new(Q0, all_states, all_transitions, 5, 4);

    if(state_machine_isvalidword(state_machine, "hola")){
        printf("FUNCIONA, He reconocido la palabra\n");
    }
    else{
        printf("No he reconocido la palabra\n");
    }

    /*free all the memory*/
    free(Q0);
    free(Q1);
    free(Q2);
    free(Q3);
    free(QF);

    free(f1);
    free(f2);
    free(f3);
    free(f4);

    free(state_machine);

    return 0;

}