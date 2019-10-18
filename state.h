#ifndef STATE_H
#define STATE_H

/*struct that represent the state of a state_machine*/
typedef struct _state state;

/** Creates a state
  * @param type enum that shows the type of the state
  * @param long with the id of the state
  * 
  * @return ste state or NULL if something wrong happened
  */
state *state_create(int type, long id);

/**
  * check if a state is final or not
  * @param state the state we want to check
  * @return boolean that indicates if the state is final
  */
int state_is_final(state *state);

/**
  * check if a state is initial or not
  * @param state the state we want to check
  * @return boolean that indicates if the state is initial
  */
int state_is_initial(state *state);

/**
  * check if two states are similar so they can be considered the same
  * @param s1 one state we want to compare
  * @param s2 one state we want to compare
  * @return boolean that indicates if the state if final
  */
int state_is_equal(state *s1, state *s2);

void state_print(state *state);

#endif
