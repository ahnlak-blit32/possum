/****************************************************************************\
|*                                                                          *|
|* player.cpp - part of Possum, a Space Shooter game.                       *|
|*                                                                          *|
|* Copyright (C) 2021 Pete Favelle <32blit@ahnlak.com>                      *|
|*                                                                          *|
|* This file is released under the MIT License; see LICENSE for details.    *|
|*                                                                          *|
|* The Player class encapsulates the whole player; his ship, lives, scores. *|
|*                                                                          *|
\****************************************************************************/

/* System headers. */


/* Local headers. */

#include "possum.hpp"
#include "player.hpp"


/* Functions. */


/**
 * Player()
 * 
 * Constructor; just sets up some basic parameters.
 */

Player::Player( void )
{
  /* Default our position the middle bottom of the screen. */
  c_position.x = blit::screen.bounds.w / 2;
  c_position.y = blit::screen.bounds.h - 12;
  c_bank = BANK_NONE;
  c_thrust = THRUST_CRUISE;
  c_thrust_frame = 0;

  /* All done. */
  return;
}


/**
 * ~Player()
 * 
 * Destructor; simple tidying up - very little is required.
 */

Player::~Player( void )
{
  /* All done. */
  return;
}


/**
 * update( time )
 * 
 * Called every tick to update the player state, based on various inputs which
 * depend on whether or not the game is active, and other factors.
 */

void Player::update( uint32_t p_time )
{
  /* Check to see if there is movement input. */
  if ( blit::buttons.state & blit::Button::DPAD_LEFT )
  {
    /* Moving left; set the bank angle to start with. */
    c_bank = BANK_LEFT;

    /* If we haven't hit the edge of the screen, move too. */
    if ( c_position.x > 4 )
    {
      c_position.x--;
    }
  }
  else if ( blit::buttons.state & blit::Button::DPAD_RIGHT )
  {
    /* Moving right then, again, always set the bank angle. */
    c_bank = BANK_RIGHT;

    /* If we haven't hit the edge of the screen, move too. */
    if ( c_position.x < blit::screen.bounds.w - 4 )
    {
      c_position.x++;
    }
  }
  else
  {
    /* We're not moving left or right, so we shouldn't bank. */
    c_bank = BANK_NONE;
  }

  /* Vertical movement is a bit easier, because there's no banking. */
  if ( blit::buttons.state & blit::Button::DPAD_UP )
  {
    /* Boost the thrusters, and move if there's space. */
    c_thrust = THRUST_BOOST;
    if ( c_position.y > 4 )
    {
      c_position.y--;
    }
  }
  else if ( blit::buttons.state & blit::Button::DPAD_DOWN )
  {
    /* Drift down, turn the thrusters down too. */
    c_thrust = THRUST_NONE;
    if ( c_position.y < blit::screen.bounds.h - 8 )
    {
      c_position.y++;
    }
  }
  else
  {
    /* We're just cruising. */
    c_thrust = THRUST_CRUISE;
  }

  /* Keep the thrusters ticking, at a sensible framerate. */
  if ( p_time > ( c_thrust_tick + 75 ) )
  {
    /* Keep moving through the frames. */
    if ( ++c_thrust_frame >= 3 )
    {
      c_thrust_frame = 0;
    }

    /* And remember that we've ticked. */
    c_thrust_tick = p_time;
  }

  /* Remember the last tick we were here. */
  c_last_tick = p_time;

  /* All done. */
  return;
}


/**
 * render()
 * 
 * Called every tick to render the player; we always know where the ship is and
 * what state it's in.
 */

void Player::render( void )
{
  static blit::Point l_ship_offset( -4, -4 );
  static blit::Point l_thrust_offset( -4, 4 );

  /*
   * The player position indicates the center of the ship; so, we just pick 
   * the right sprite based on the bank angle.
   */
  blit::Rect l_ship_src( 8 * c_bank, 16, 8, 8 );
  blit::screen.blit( g_ss_ships, l_ship_src, c_position + l_ship_offset );

  /* The ship needs to have the right thrusters, too. */
  blit::Rect l_thrust_src( 8 * ( 5 + c_thrust_frame ), 8 * c_thrust, 8, 8 );
  blit::screen.blit( g_ss_misc, l_thrust_src, c_position + l_thrust_offset );

  /* All done. */
  return;
}

/* End of file player.cpp */
