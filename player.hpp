/****************************************************************************\
|*                                                                          *|
|* player.hpp - part of Possum, a Space Shooter game.                       *|
|*                                                                          *|
|* Copyright (C) 2021 Pete Favelle <32blit@ahnlak.com>                      *|
|*                                                                          *|
|* This file is released under the MIT License; see LICENSE for details.    *|
|*                                                                          *|
|* The Player class encapsulates the whole player; his ship, lives, scores. *|
|*                                                                          *|
\****************************************************************************/

#ifndef   _PLAYER_HPP_
#define   _PLAYER_HPP_


/* Constants and enums. */

typedef enum
{
  BANK_LEFT,
  BANK_NONE,
  BANK_RIGHT
} ship_bank_t;

typedef enum
{
  THRUST_NONE,
  THRUST_CRUISE,
  THRUST_BOOST
} ship_thrust_t;


/* Structures. */


class Player {
private:
  uint32_t      c_last_tick;
  blit::Point   c_position;
  ship_bank_t   c_bank;
  ship_thrust_t c_thrust;
  uint8_t       c_thrust_frame;
  uint32_t      c_thrust_tick;

public:
                Player( void );
               ~Player( void );
  void          update( uint32_t );
  void          render( void );
};


#endif /* _PLAYER_HPP_ */

/* End of file player.hpp */
