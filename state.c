#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "string.h"
#include "state.h"

struct _state
{
  type_state type;
  char *name;
};

state *state_create(int type, char *name)
{

  state *new_state;

  if ((type != INITIAL && type != FINAL && type != OTHER) || name == NULL)
    return NULL;

  new_state = (state *)malloc(sizeof(state));

  if (new_state == NULL)
    return NULL;

  new_state->type = type;


  strcpy(new_state->name, name);

  return new_state;
}

int state_is_final(state *state)
{
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

  if (strcmp(s1->name, s2->name) == 0)
    return TRUE;

  return FALSE;
}

void state_print(state *state)
{
  printf("\n\nESTADO:\n\tTIPO: %d.\n\tNOMBRE: %s\n\n",state->type,state->name);
}
