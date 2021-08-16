/****************************************************************************\
|*                                                                          *|
|* possum.cpp - part of Possum, a Space Shooter game.                       *|
|*                                                                          *|
|* Copyright (C) 2021 Pete Favelle <32blit@ahnlak.com>                      *|
|*                                                                          *|
|* This file is released under the MIT License; see LICENSE for details.    *|
|*                                                                          *|
|* Main entry point for the program; this file provides the three 32Blit    *|
|* interface functions (init, update, render).                              *|
|*                                                                          *|
\****************************************************************************/

/* System headers. */


/* Local headers. */

#define  _POSSUM_X
#include "possum.hpp"

#include "background.hpp"
#include "player.hpp"
#include "ssap.hpp"


/* Module variables. */

Background *m_background = nullptr;
Player     *m_player = nullptr;


/* Functions. */


/**
 * init()
 * 
 * Called on game launch, to do the basic set up, select screen mode et al.
 */

void init( void )
{
  /* Select lo-res, which is 120px high on all our platforms (width varies) */
  blit::set_screen_mode( blit::ScreenMode::lores );

  /* Initialise our spritesheets; we keep these global because frankly that */
  /* makes sense and I'm very, very sorry. They're read-only, though!       */
  g_ss_backgrounds = blit::Surface::load_read_only( ssap_backgrounds );
  g_ss_characters = blit::Surface::load_read_only( ssap_characters );
  g_ss_UI = blit::Surface::load_read_only( ssap_ui );
  g_ss_misc = blit::Surface::load_read_only( ssap_misc );
  g_ss_projectiles = blit::Surface::load_read_only( ssap_projectiles );
  g_ss_ships = blit::Surface::load_read_only( ssap_ships );

  /* Create the background object, used to draw, err, the background. */
  m_background = new Background();

  /* And the player object, which holds the ship, the scores, ... */
  m_player = new Player();

  /* All done. */
  return;
}


/**
 * update( time )
 * 
 * Called every tick to update the world state; these update ticks should be
 * every 10ms (100Hz), and the 'nomimal' elapsed time is provided as an
 * argument. Missed updates will be caught up (with faked times) if necessary.
 */

void update( uint32_t p_time )
{
  /* The background moves forever, behind... well, everything really. */
  if ( m_background != nullptr )
  {
    m_background->update( p_time );
  }

  /* When the game isn't running, the player object still needs updates. */
  if ( m_player != nullptr )
  {
    m_player->update( p_time );
  }


  /* All done. */
  return;
}


/**
 * render( time )
 * 
 * Called every tick to render the world; these render ticks should be every
 * 20ms (50Hz), but may be dropped if system performance requires. Therefore
 * it's critical that the world is not modified during the render step.
 */

void render( uint32_t p_time )
{
  /* We always need to clear down and draw the background. */
  if ( m_background != nullptr )
  {
    m_background->render();
  }

  /* If the game isn't running, the player still needs to be visible. */
  if ( m_player != nullptr )
  {
    m_player->render();
  }

  /* All done. */
  return;
}

/* End of file possum.cpp */
