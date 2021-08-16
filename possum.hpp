/****************************************************************************\
|*                                                                          *|
|* possum.hpp - part of Possum, a Space Shooter game.                       *|
|*                                                                          *|
|* Copyright (C) 2021 Pete Favelle <32blit@ahnlak.com>                      *|
|*                                                                          *|
|* This file is released under the MIT License; see LICENSE for details.    *|
|*                                                                          *|
|* This header declares any system-wide constants and structures; class     *|
|* declarations can be found in their own headers.                          *|
|*                                                                          *|
\****************************************************************************/

#ifndef   _POSSUM_HPP_
#define   _POSSUM_HPP_

#include "32blit.hpp"


/* Constants and enums. */


/* Structures. */


/* Globals. Yes, I know. */

/*
 * We only want to declare globals once, but extern them everywhere. This is
 * and ancient technique from University days that will probably make modern
 * programmers puke. Sorry!
 */
#ifndef   _POSSUM_X
#define   _POSSUM_X extern
#endif /* _POSSUM_X */

_POSSUM_X blit::Surface *g_ss_backgrounds;
_POSSUM_X blit::Surface *g_ss_characters;
_POSSUM_X blit::Surface *g_ss_UI;
_POSSUM_X blit::Surface *g_ss_misc;
_POSSUM_X blit::Surface *g_ss_projectiles;
_POSSUM_X blit::Surface *g_ss_ships;


/* Prototypes. */


#endif /* _POSSUM_HPP_ */

/* End of file possum.hpp */
