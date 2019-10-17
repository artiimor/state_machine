#include <stdio.h>
#include <stdlib.h>

#include "transition.h"
#include "state.h"
#include "types.h"

struct _transition
{
  state *input_state;    /*input state for this case of the function*/
  char input_symbol;     /*output state for this case of the function*/
  state **output_states; /*all the result states (it must be an array for the NDA)*/
  int output_states_lenght;
};

transition *transition_new(state *input_state, char input_symbol, state **output_states, int output_states_lenght)
{

  transition *new_transition;

  if (input_state == NULL || output_states == NULL)
    return NULL;

  new_transition = (transition *)malloc(sizeof(transition));

  if (new_transition == NULL)
    return NULL;

  new_transition->input_state = input_state;
  new_transition->input_symbol = input_symbol;
  new_transition->output_states = output_states;
  new_transition->output_states_lenght = output_states_lenght;

  /*printf("DEBUG TRANSITION:");*/
  state_print(new_transition->output_states[0]);

  return new_transition;
}

state *transition_get_input_state(transition *transition)
{
  if (transition == NULL)
    return NULL;

  return transition->input_state;
}

char transition_get_input_symbol(transition *transition)
{
  if (transition == NULL)
    return '\n';

  return transition->input_symbol;
}

state **transition_get_output_states(transition *transition)
{
  if (transition == NULL)
    return NULL;

  return transition->output_states;
}

int transition_get_output_states_lenght(transition *transition)
{
  if (transition == NULL)
    return -1;

  return transition->output_states_lenght;
}

void transition_print(transition *transition)
{

  int i;

  if (transition == NULL)
    return;

  printf("\n\nTRANSITION:\n\tESTADO INICIAL: \n");
  state_print(transition->input_state);
  printf("\tINPUT SYMBOL: %c\nESTADOS SALIDA:\n", transition->input_symbol);

  for (i = 0; transition->output_states[i] == NULL; i++)
  {
    state_print(transition->output_states[i]);
  }

  printf("FIN DE TRANSITION\n");
}
