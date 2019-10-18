#include <stdio.h>
#include <stdlib.h>

#include "transition.h"
#include "state.h"
#include "types.h"

struct _transition
{
  state *input_state;  /*input state for this case of the function*/
  char input_symbol;   /*output state for this case of the function*/
  state *output_state; /*We need one transition for every output with the same symbol*/
};

transition *transition_new(state *input_state, char input_symbol, state *output_state)
{

  transition *new_transition;

  if (input_state == NULL || output_state == NULL)
    return NULL;

  new_transition = (transition *)malloc(sizeof(transition));

  if (new_transition == NULL)
    return NULL;

  new_transition->input_state = input_state;
  new_transition->input_symbol = input_symbol;
  new_transition->output_state = output_state;

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
    return '\0';

  return transition->input_symbol;
}

state *transition_get_output_state(transition *transition)
{
  if (transition == NULL)
    return NULL;

  return transition->output_state;
}

void transition_print(transition *transition)
{

  if (transition == NULL)
    return;

  printf("\n\nTRANSITION:\n\tESTADO INICIAL: \n");
  state_print(transition->input_state);
  printf("\tINPUT SYMBOL: %c\nESTADO SALIDA:\n", transition->input_symbol);
  state_print(transition->output_state);

  printf("FIN DE TRANSITION\n");
}
