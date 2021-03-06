/*
  The oSIP library implements the Session Initiation Protocol (SIP -rfc2543-)
  Copyright (C) 2001  Aymeric MOIZARD jack@atosc.org
  
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
  
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.
  
  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include <stdio.h>

#include <osip/port.h>
#include <osip/fifo.h>
#include <osip/osip.h>
#include "fsm.h"


/* find the transition for state and type in statemachine */
/* return NULL; if transition is not found.               */
transition_t *
fsm_findmethod (type_t type, state_t state, statemachine_t * statemachine)
{
  int pos;

  pos = 0;
  while (!list_eol (statemachine->transitions, pos))
    {
      transition_t *transition;

      transition = (transition_t *) list_get (statemachine->transitions, pos);
      if (transition->type == type && transition->state == state)
	return transition;
      pos++;
    }
  return NULL;
}


/* call the right execution method.          */
/*   return -1 when event must be discarded  */
int
fsm_callmethod (type_t type, state_t state, statemachine_t * statemachine,
		void *sipevent, void *transaction)
{
  transition_t *transition;

  transition = fsm_findmethod (type, state, statemachine);
  if (transition == NULL)
    {
      /* No transition found for this event */
      return -1;		/* error */
    }
  transition->method (transaction, sipevent);
  return 0;			/* ok */
}
