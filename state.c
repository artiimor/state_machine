#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "string.h"
#include "state.h"

struct _state
{
  type_state type;
  long id;
};

state *state_create(int type, long id)
{

  state *new_state;

  if ((type != INITIAL && type != FINAL && type != OTHER) || id < 0)
    return NULL;

  new_state = (state *)malloc(sizeof(state));

  if (new_state == NULL)
    return NULL;

  new_state->type = type;


  new_state->id = id;

  return new_state;
}

int state_is_final(state *state)
{
  if (state == NULL)
    return FALSE;
    
  if (state->type == FINAL)
    return TRUE;

  return FALSE;
}

int state_is_initial(state *state)
{
  if (state->type == INITIAL)
    return TRUE;

  return FALSE;
}

int state_is_equal(state *s1, state *s2)
{

  if (s1 == NULL || s2 == NULL)
    return FALSE;

  if (s1 == s2)
    return TRUE;

  if (s1->id == s2->id)
    return TRUE;

  return FALSE;
}

void state_print(state *state)
{
  printf("ESTADO:\n\tTIPO: %d\nID: %ld\n\n",state->type,state->id);
}
