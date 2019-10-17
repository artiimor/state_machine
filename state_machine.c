#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "state_machine.h"
#include "state.h"
#include "transition.h"

#include "types.h"

boolean is_state_contained(state **state_array, state *state, int state_array_lenght);

struct _state_machine
{
  state *init_state;                /* the initial state. Here all starts */
  state **states;                   /* array with all the states of the automaton */
  transition **transition_function; /* this array contains the information for the transition function */
  int state_number;
  int transition_number;
};

state_machine *state_machine_new(state *init_state, state **states, transition **transition_function)
{

  int i;
  state_machine *new_state_machine;

  if (init_state == NULL || states == NULL || transition_function == NULL || state_is_initial(init_state) == FALSE)
    return NULL;

  new_state_machine = (state_machine *)malloc(sizeof(state_machine));

  if (new_state_machine == NULL)
    return NULL;

  new_state_machine->init_state = init_state;
  new_state_machine->states = states;
  new_state_machine->transition_function = transition_function;

  for (i = 0; states[i] != NULL; i++)
    ;
  new_state_machine->state_number = i;

  for (i = 0; transition_function[i] != NULL; i++)
    ;
  new_state_machine->transition_number = i;

	/*hola*/

  return new_state_machine;
}

boolean state_machine_contains_state(state_machine *state_machine, state *state)
{

  int i;

  if (state == NULL)
    return FALSE;

  for (i = 0; i < state_machine->state_number; i++)
  {

    if (state_is_equal(state_machine->states[i], state) == TRUE)
      return TRUE;
  }

  return FALSE;
}

state **state_machine_get_states(state_machine *state_machine)
{
  if (state_machine == NULL)
    return NULL;

  return state_machine->states;
}

state *state_machine_get_initial_state(state_machine *state_machine)
{
  if (state_machine == NULL)
    return NULL;

  return state_machine->init_state;
}

transition **state_machine_get_transitions(state_machine *state_machine)
{
  if (state_machine == NULL)
    return NULL;

  return state_machine->transition_function;
}

int state_machine_get_statenumber(state_machine *state_machine)
{
  if (state_machine == NULL)
    return -1;

  return state_machine->state_number;
}

int state_machine_get_transitionnumber(state_machine *state_machine)
{
  if (state_machine == NULL)
    return -1;

  return state_machine->transition_number;
}

boolean state_machine_isvalidword(state_machine *state_machine, char *word)
{

  int i, j, k, n;                  /*counter for the loops*/
  int max_states, max_transitions; /*max amount of states and transitions*/
  int actual_states_aux, previous_states_aux, output_states_lenght;
  transition **transitions; /*all the transitions*/
  state **actual_states = NULL;
  state **previous_states = NULL;
  state **transition_output_aux;
  state *initial_state;

  char symbol_aux;
  state *transition_input_aux;

  if (state_machine == NULL || word == NULL)
  {
    return FALSE;
  }

  /*
  for (i = 0; i < state_machine->state_number; i++)
  {
    state_print(state_machine->states[i]);
  }
  */
 
  /*
  for (i = 0; i < state_machine->transition_number; i++)
  {
    transition_print(state_machine->transition_function[i]);
  }
  */
  

  /*we want to check all the transitions and states*/
  transitions = state_machine_get_transitions(state_machine);
  max_states = state_machine_get_statenumber(state_machine);
  max_transitions = state_machine_get_transitionnumber(state_machine);
  actual_states = (state **)calloc(max_states, sizeof(state *));
  actual_states_aux = 0;
  initial_state = state_machine_get_initial_state(state_machine);

  /*loop for every symbol of the word*/
  for (i = 0; i < strlen(word); i++)
  {
    if (previous_states != NULL)
    {
      free(previous_states);
      previous_states = actual_states;
      previous_states_aux = actual_states_aux;
    }
    /*reset actual_states*/
    actual_states = (state **)calloc(max_states, sizeof(state *));
    actual_states_aux = 0;

    /*when we start*/
    if (i == 0)
    {
      printf("HOLA\n");
      /*loop for checking every possible transition*/
      for (k = 0; k < max_transitions; k++)
      {
        symbol_aux = transition_get_input_symbol(transitions[k]);
        transition_input_aux = transition_get_input_state(transitions[k]);
        /*we have a new state if exist a transition with the correct symbol and state*/
        if (symbol_aux == word[i] && state_is_equal(transition_input_aux, initial_state))
        {
          transition_output_aux = transition_get_output_states(transitions[k]);
          /*now we introduce every output state is not container in actual_states*/
          output_states_lenght = transition_get_output_states_lenght(transitions[k]);
          for (n = 0; n < output_states_lenght; n++)
          {
            if (!is_state_contained(actual_states, transition_output_aux[n], actual_states_aux))
            {
              actual_states[actual_states_aux] = transition_output_aux[n];
              actual_states_aux++;
            }
          }
        }
      }
    }

    else
    {
      /*previous_states = actual_states, so we check every state*/

      /*reset actual_states*/
      actual_states = (state **)calloc(max_states, sizeof(state *));
      actual_states_aux = 0;

      /*loop for the transition of every current state*/
      for (j = 0; j < previous_states_aux; j++)
      {
        /*loop for checking every possible transition*/
        for (k = 0; k < max_transitions; k++)
        {
          symbol_aux = transition_get_input_symbol(transitions[k]);
          transition_input_aux = transition_get_input_state(transitions[k]);
          /*we have a new state if exist a transition with the correct symbol and state*/
          if (symbol_aux == word[i] && state_is_equal(transition_input_aux, previous_states[j]))
          {
            transition_output_aux = transition_get_output_states(transitions[k]);
            /*now we introduce every output state is not container in actual_states*/
            output_states_lenght = transition_get_output_states_lenght(transitions[k]);
            for (n = 0; n < output_states_lenght; n++)
            {
              if (!is_state_contained(actual_states, transition_output_aux[n], actual_states_aux))
              {
                actual_states[actual_states_aux] = transition_output_aux[n];
                actual_states_aux++;
              }
            }
          }
        }
      }
    }
  }

  /*now we have the final states, we only have to check if there is a final state*/
  for (i = 0; i < max_states || actual_states[i] == NULL; i++)
  {
    if (state_is_final(actual_states[i]))
    {
      return TRUE;
    }
  }

  return FALSE;
}

boolean is_state_contained(state **state_array, state *state, int state_array_lenght)
{
  int i;
  if (state_array_lenght <= 0 || state == NULL || state_array == NULL)
    return FALSE;

  for (i = 0; i < state_array_lenght - 1 || state_array[i] == NULL; i++)
  {
    printf("\n\n%d\n\n", state_array_lenght);
    if (state_is_equal(state, state_array[i]))
    {
      return TRUE;
    }
  }

  return FALSE;
}
