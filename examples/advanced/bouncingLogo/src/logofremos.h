//-----------------------------LICENSE NOTICE------------------------------------
//  This file is part of CPCtelera: An Amstrad CPC Game Engine 
//  Copyright (C) 2015 Dardalorth / Fremos / Carlio 
//  Copyright (C) 2015 ronaldo / Fremos / Cheesetea / ByteRealms (@FranGallegoBR)
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//------------------------------------------------------------------------------

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////
//////  SPRITE AND PALETTE DEFINITIONS
//////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

// Selected firmware colors from the video palette to be used with the sprite
const unsigned char gc_palette[16] = {
   0x0D, 0x0F, 0x03, 0x18, 0x01, 0x14, 0x06, 0x1A,
   0x00, 0x02, 0x0B, 0x12, 0x08, 0x05, 0x10, 0x09
};

// Sprite definition of the Fremos Logo for mode 0
//  by Dardalorth / Fremos / Carlio
const unsigned char gc_LogoFremos[1100] = {
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x4C,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0x8C,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x48,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x84,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x48,0xC0,0xC0,0xC0,
   0xC0,0xC0,0xC0,0x84,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x48,0xC0,0x84,0x0C,0x0C,0x48,0x84,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x48,0xC0,0x84,0x4C,0x8C,0x48,0x84,0x4C,0xCC,0x8C,0x4C,0xCC,0xCC,
   0x8C,0x00,0x00,0x00,0x00,0x4C,0xCC,0xCC,0xCC,0x8C,0x00,0x00,0x4C,0xCC,0x8C,
   0x4C,0xCC,0x8C,0x00,0x00,0x00,0x00,0x4C,0xCC,0xCC,0xCC,0x8C,0x00,0x00,0x00,
   0x00,0x4C,0xCC,0xCC,0xCC,0xCC,0x8C,0x00,0x00,0x00,0x00,0x00,0x48,0xC0,0x84,
   0x48,0x84,0x0C,0x0C,0x48,0xC0,0x84,0x48,0xC0,0xC0,0x84,0x00,0x00,0x00,0x00,
   0x48,0xC0,0xC0,0xC0,0x84,0x00,0x00,0x48,0xC0,0x84,0x48,0xC0,0x84,0x00,0x00,
   0x00,0x00,0x48,0xC0,0xC0,0xC0,0x84,0x00,0x00,0x00,0x00,0x48,0xC0,0xC0,0xC0,
   0xC0,0x84,0x00,0x00,0x00,0x00,0x00,0x48,0xC0,0xC4,0xC8,0x84,0x00,0x00,0x48,
   0xC0,0xC4,0xC8,0xC0,0xC0,0xC4,0x8C,0x00,0x00,0x4C,0xC8,0xC0,0xC0,0xC0,0xC4,
   0x8C,0x4C,0xC8,0xC0,0xC4,0xC8,0xC0,0xC4,0x8C,0x00,0x00,0x4C,0xC8,0xC0,0xC0,
   0xC0,0xC4,0x8C,0x00,0x00,0x4C,0xC8,0xC0,0xC0,0xC0,0xC0,0x84,0x00,0x00,0x00,
   0x00,0x00,0x48,0xC0,0xC0,0xC0,0x84,0x00,0x00,0x0C,0x48,0xC0,0xC0,0x84,0x48,
   0xC0,0x84,0x00,0x00,0x48,0xC0,0x84,0x0C,0x48,0xC0,0x84,0x48,0xC0,0xC0,0xC0,
   0xC0,0xC0,0xC0,0x84,0x00,0x00,0x48,0xC0,0x84,0x0C,0x48,0xC0,0x84,0x00,0x00,
   0x48,0xC0,0x84,0x0C,0x0C,0x0C,0x0C,0x00,0x00,0x00,0x00,0x00,0x48,0xC0,0xC0,
   0xC0,0x84,0x00,0x00,0x00,0x48,0xC0,0xC0,0x84,0x48,0xC0,0x84,0x00,0x00,0x48,
   0xC0,0xC4,0xCC,0xC8,0xC0,0x84,0x48,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x84,0x00,
   0x00,0x48,0xC0,0x84,0x00,0x48,0xC0,0x84,0x00,0x00,0x48,0xC0,0xC4,0xCC,0xCC,
   0xCC,0x8C,0x00,0x00,0x00,0x00,0x00,0x48,0xC0,0x84,0x48,0x84,0x00,0x00,0x00,
   0x48,0xC0,0x84,0x0C,0x0C,0x0C,0x0C,0x00,0x00,0x48,0xC0,0xC0,0xC0,0xC0,0xC0,
   0x84,0x48,0xC0,0x84,0x48,0x84,0x48,0xC0,0x84,0x00,0x00,0x48,0xC0,0x84,0x00,
   0x48,0xC0,0x84,0x00,0x00,0x0C,0x48,0xC0,0xC0,0xC0,0xC0,0x84,0x00,0x00,0x00,
   0x00,0x00,0x48,0xC0,0x84,0x48,0x84,0x00,0x00,0x00,0x48,0xC0,0x84,0x00,0x00,
   0x00,0x00,0x00,0x00,0x48,0xC0,0xC0,0xC0,0xC0,0xC0,0x84,0x48,0xC0,0x84,0x48,
   0x84,0x48,0xC0,0x84,0x00,0x00,0x48,0xC0,0x84,0x00,0x48,0xC0,0x84,0x00,0x00,
   0x00,0x48,0xC0,0xC0,0xC0,0xC0,0xC4,0x8C,0x00,0x00,0x00,0x00,0x48,0xC0,0x84,
   0x0C,0x0C,0x00,0x00,0x00,0x48,0xC0,0x84,0x00,0x00,0x00,0x00,0x00,0x00,0x48,
   0xC0,0x84,0x0C,0x0C,0x0C,0x0C,0x48,0xC0,0x84,0x48,0x84,0x48,0xC0,0x84,0x00,
   0x00,0x48,0xC0,0x84,0x00,0x48,0xC0,0x84,0x00,0x00,0x00,0x0C,0x0C,0x0C,0x0C,
   0x48,0xC0,0x84,0x00,0x00,0x00,0x4C,0xC8,0xC0,0xC4,0x8C,0x00,0x00,0x00,0x4C,
   0xC8,0xC0,0xC4,0x8C,0x00,0x00,0x00,0x00,0x00,0x48,0xC0,0xC4,0xCC,0xCC,0x8C,
   0x00,0x48,0xC0,0x84,0x48,0x84,0x48,0xC0,0x84,0x00,0x00,0x48,0xC0,0xC4,0xCC,
   0xC8,0xC0,0x84,0x00,0x00,0x4C,0xCC,0xCC,0xCC,0xCC,0xC8,0xC0,0x84,0x00,0x00,
   0x00,0x48,0xC0,0xC0,0xC0,0x84,0x00,0x00,0x00,0x48,0xC0,0xC0,0xC0,0x84,0x00,
   0x00,0x00,0x00,0x00,0x0C,0x48,0xC0,0xC0,0xC0,0x84,0x00,0x48,0xC0,0x84,0x0C,
   0x0C,0x48,0xC0,0x84,0x00,0x00,0x0C,0x48,0xC0,0xC0,0xC0,0x84,0x0C,0x00,0x00,
   0x48,0xC0,0xC0,0xC0,0xC0,0xC0,0x84,0x0C,0x00,0x00,0x00,0x48,0xC0,0xC0,0xC0,
   0x84,0x00,0x00,0x00,0x48,0xC0,0xC0,0xC0,0x84,0x00,0x00,0x00,0x00,0x00,0x00,
   0x48,0xC0,0xC0,0xC0,0x84,0x00,0x48,0xC0,0x84,0x00,0x00,0x48,0xC0,0x84,0x00,
   0x00,0x00,0x48,0xC0,0xC0,0xC0,0x84,0x00,0x00,0x00,0x48,0xC0,0xC0,0xC0,0xC0,
   0xC0,0x84,0x00,0x00,0x00,0x00,0x0C,0x0C,0x0C,0x0C,0x0C,0x00,0x00,0x00,0x0C,
   0x0C,0x0C,0x0C,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x0C,0x0C,0x0C,0x0C,
   0x00,0x0C,0x0C,0x0C,0x00,0x00,0x0C,0x0C,0x0C,0x00,0x00,0x00,0x0C,0x0C,0x0C,
   0x0C,0x0C,0x00,0x00,0x00,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00
};
