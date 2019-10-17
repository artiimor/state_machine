#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "state_machine.h"
#include "state.h"
#include "transition.h"

#include "types.h"

/*struct that representates a state_machine*/
typedef struct _state_machine state_machine;

/**
 * state_machine new creates a new state machine
 * 
 * @param init_state the initial state of the state machine
 * @param states all the states of the state machine
 * @param transition_function all the posible transitions of the state machine
 * 
 * @return the new state machine
 */
state_machine *state_machine_new(state *init_state, state **states, transition **transition_function);

/**
 * state_machine_contains_state check if the state_machine contains a state
 * 
 * @param state_machine the state machine
 * @param state the state to check
 * 
 * @return a boolean with the result
 */
boolean state_machine_contains_state(state_machine *state_machine, state *state);

/**
 * state_machine_get_states gives us all the states of the state machine
 * 
 * @param state_machine the state machine
 * 
 * @return an array with all the states
 */
state **state_machine_get_states(state_machine *state_machine);

/**
 * state_machine_get_initial_state returns the initial state
 * 
 * @param state_machine the state machine
 * 
 * @return the initial state
 */
state *state_machine_get_initial_state(state_machine *state_machine);

/**
 * state_machine_get_transitions returns all the posible transitions
 * 
 * @param state_machine the state machine
 * 
 * @return the transitions from the transition function
 */
transition **state_machine_get_transitions(state_machine *state_machine);

/**
 * state_machine_get_statenumber gives us the number of states
 * 
 * @param state_machine the state machine
 * 
 * @return the amount os states in the state machine
 */
int state_machine_get_statenumber(state_machine *state_machine);

/**
 * state_machine_get_transitionnumber gives us the number of possible transitions
 * 
 * @param state_machine the state machine
 * 
 * @return the number of possible transitions
 */
int state_machine_get_transitionnumber(state_machine *state_machine);

/**
 * state_machine_isvalidword check if a word is allowed by the state machine
 * 
 * @param state_machine the state machine
 * @param word the word we want to check
 * 
 * @return a boolean with the result
 */
boolean state_machine_isvalidword(state_machine *state_machine, char *word);

#endif
