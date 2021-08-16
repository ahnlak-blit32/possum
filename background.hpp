/****************************************************************************\
|*                                                                          *|
|* background.hpp - part of Possum, a Space Shooter game.                   *|
|*                                                                          *|
|* Copyright (C) 2021 Pete Favelle <32blit@ahnlak.com>                      *|
|*                                                                          *|
|* This file is released under the MIT License; see LICENSE for details.    *|
|*                                                                          *|
|* The Background class handles an ever-scrolling star-filled background    *|
|* which appears on every screen throughout the game.                       *|
|*                                                                          *|
\****************************************************************************/

#ifndef   _BACKGROUND_HPP_
#define   _BACKGROUND_HPP_


/* Constants and enums. */

#define   PANEL_WIDTH   128
#define   PANEL_HEIGHT  256

/* Structures. */


class Background
{
private:
  uint8_t   c_panel;
  uint8_t   c_offset;
  uint8_t   c_delay;
  uint32_t  c_last_tick;


public:
            Background( void );
           ~Background( void );
  void      update( uint32_t );
  void      render( void );
};


#endif /* _BACKGROUND_HPP_ */

/* End of file background.hpp */
