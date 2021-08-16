/****************************************************************************\
|*                                                                          *|
|* background.cpp - part of Possum, a Space Shooter game.                   *|
|*                                                                          *|
|* Copyright (C) 2021 Pete Favelle <32blit@ahnlak.com>                      *|
|*                                                                          *|
|* This file is released under the MIT License; see LICENSE for details.    *|
|*                                                                          *|
|* The Background class handles an ever-scrolling star-filled background    *|
|* which appears on every screen throughout the game.                       *|
|*                                                                          *|
\****************************************************************************/

/* System headers. */

#include <unistd.h>


/* Local headers. */

#include "possum.hpp"
#include "background.hpp"


/* Functions. */

/**
 * Background()
 * 
 * Constructor; sets things up to know which part of the background sprite
 * we're using, sensible default scroll speeds and suchlike.
 */

Background::Background( void )
{
  /* The background starts at the start. */
  c_panel = 0;
  c_offset = 0;
  c_delay = 20;
  c_last_tick = 0;

  /* All done. */
  return;
}


/**
 * ~Background()
 * 
 * Destructor; general tidying up, but we really don't have much work here.
 */

Background::~Background( void )
{
  /* All done. */
  return;
}


/**
 * update( p_time )
 * 
 * Updates the position of the background, based on the time elapsed. This
 * ensures that it's a visually smooth scroll, in theory.
 */

void Background::update( uint32_t p_time )
{
  /* If this is the first call, not much we can sensibly do. */
  if ( c_last_tick == 0 )
  {
    c_last_tick = p_time;
    return;
  }

  /* Check to see if enough time has passed to move. */
  if ( p_time < ( c_last_tick + c_delay ) )
  {
    return;
  }
  c_last_tick = p_time;

  /*
   * Move the offset down on the panel; panels are 256px long, so once we
   * reach the bottom we loop back.
   */
  if ( c_offset == 0 )
  {
    /* And reset the offset. */
    c_offset = PANEL_HEIGHT-1;
  }
  else
  {
    /* Otherwise we just keep moving the offset along. */
    c_offset--;
  }

  /* All done. */
  return;
}


/**
 * render()
 * 
 * Draws the background to the screen, based on it's current position.
 */

void Background::render( void )
{
  uint8_t     l_carry = 0;
  blit::Rect  l_src_rect( c_panel * (PANEL_WIDTH+1), c_offset, PANEL_WIDTH, blit::screen.bounds.h );

  /*
   * On the face of it, simple - blit from the right panel, at the right
   * offset. However, we need to make sure we don't go off the bottom.
   */
  if ( l_src_rect.bl().y >= PANEL_HEIGHT )
  {
    l_carry = l_src_rect.bl().y - PANEL_HEIGHT;
    l_src_rect.h -= l_carry;
  }

  /* So, as much of the top panel as possible. */
  blit::screen.blit( g_ss_backgrounds, l_src_rect, blit::Point( 0, 0 ) );

  /* If the screen is wider than the panels, need to add some more! */
  if ( blit::screen.bounds.w > PANEL_WIDTH )
  {
    blit::screen.blit( g_ss_backgrounds, l_src_rect, blit::Point( PANEL_WIDTH, 0 ) );
  }

  /* And then, if we have a carry, we fetch that from the next panel. */
  if ( l_carry > 0 )
  {
    /* Set the y to the top. */
    l_src_rect.y = 0;

    /* Open up the height fully, let the blit clip it. */
    l_src_rect.h = blit::screen.bounds.h;

    /* And then blit this bit too. */
    blit::screen.blit( g_ss_backgrounds, l_src_rect, blit::Point( 0, blit::screen.bounds.h - l_carry ) );
    if ( blit::screen.bounds.w > PANEL_WIDTH )
    {
      blit::screen.blit( g_ss_backgrounds, l_src_rect, blit::Point( PANEL_WIDTH, blit::screen.bounds.h - l_carry ) );
    }
  }

  /* All done. */
  return;
}


/* End of file background.cpp */
