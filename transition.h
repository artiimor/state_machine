#ifndef TRANSITION_H
#define TRANSITION_H

#include "state.h"

/**
  * Struct 
  * 
  * Represents one input and output of the transition function
  */
typedef struct _transition transition;

/**
  * Creates a case for the transition function
  * 
  * @param input_state input state
  * @param imput_symbol imput simbol
  * @param res_states array with states. Result of this case of the transition function
  */
transition *transition_new(state *input_state, char input_symbol, state *output_states);

/**
  * getter of the input state of this case.
  * 
  * @param transition the case of the transition function
  * @return the input state
  */
state *transition_get_input_state(transition *transition);

/**
  * Getter getter of the input symbol of this case.
  * @param transition the case of the transition function
  * @return the input symbol
  */
char transition_get_input_symbol(transition *transition);

/**
  * Getter getter of the output of this case.
  * 
  * @param transition the case of the transition function
  * @return an array with the output states
  */
state *transition_get_output_state(transition *transition);

/***************************************************************************/
/****************************debug functions********************************/
/***************************************************************************/

/**
  * print the information of the transition
  * 
  * @param transition the transition to print
  */

void transition_print(transition *transition);


#endif
