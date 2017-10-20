//-----------------------------LICENSE NOTICE------------------------------------
//  This file is part of CPCtelera: An Amstrad CPC Game Engine
//  Copyright (C) 2017 Bouche Arnaud
//  Copyright (C) 2017 ronaldo / Fremos / Cheesetea / ByteRealms (@FranGallegoBR)
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//------------------------------------------------------------------------------

#include <declarations.h>

/////////////////////////////////////////////////////////////////////////////////
// Mask Table Definition for Mode 1
cpctm_createTransparentMaskTable(gMaskTable, MASK_TABLE_LOCATION, M1, 0);

/////////////////////////////////////////////////////////////////////////////////
// GLOBAL VARIABLES
u8 gNbTileset; // Nb tileset of star background
u8 gPosScroll; // Pos scrolling of star background

// Draw functions pointer 
typedef void (*TDrawFunc)(void);
TDrawFunc gDrawFunc; // Current drawing function

/*****************************************************/
/*                                      */
/* Draw sprite directly in video memory          */
/*                                       */
/*****************************************************/
void DrawSprite()
{
   u8* screenPtr;
   u8 i;

   cpct_waitVSYNC();
   
   for(i = 0; i < VIEW_W_BYTES; i++)
   {
      u8 offsetSpriteScroll = (gPosScroll + i)%gNbTileset; // Simulate scrolling by adding offset in sprite tileset index
      screenPtr = GetScreenPtr(VIEW_X + i, VIEW_Y);
      
      cpct_drawSprite(g_tileset[offsetSpriteScroll], screenPtr, G_BACK_00_W, G_BACK_00_H);
   }

   /** Draw title at fixed coordinates */
   screenPtr =  GetScreenPtr(VIEW_X + POS_TITLE_X, 0);
   cpct_drawSpriteMaskedAlignedTable(g_title, screenPtr, G_TITLE_W, G_TITLE_H, gMaskTable);
   
   /** Select sprite and calculate its byte-ptr location Video Memory */
   {
      const u8* fireSp = (gPosScroll % 2) == 0 ? g_fire_0 : g_fire_1;
      u8  x = VIEW_X + POS_SHIP_X - G_FIRE_0_W;
      u8  y = VIEW_Y + POS_SHIP_Y + 2;
      screenPtr = GetScreenPtr(x, y);
      
      cpct_drawSpriteMaskedAlignedTable(fireSp, screenPtr, G_FIRE_0_W, G_FIRE_0_H, gMaskTable);
   }
   
   screenPtr = GetScreenPtr(VIEW_X + POS_SHIP_X, VIEW_Y + POS_SHIP_Y);
   cpct_drawSpriteMasked(g_ship, screenPtr, G_SHIP_W, G_SHIP_H);
}

/*****************************************************/
/*                                      */
/* Draw sprite Hardware double buffer            */
/*                                       */
/*****************************************************/
void DrawHWDoubleBuffer()
{
   u8* backScreenPtr;

   u8 i;
   for(i = 0; i < VIEW_W_BYTES; i++)
   {
      u8 offsetSpriteScroll = (gPosScroll + i)%gNbTileset; // Simulate scrolling by adding offset in sprite tileset index
      backScreenPtr = GetBackBufferPtr(VIEW_X + i, VIEW_Y);
      
      cpct_drawSprite(g_tileset[offsetSpriteScroll], backScreenPtr, G_BACK_00_W, G_BACK_00_H);     
   }

   /** Draw title at fixed coordinates */ 
   backScreenPtr = GetBackBufferPtr(VIEW_X + POS_TITLE_X, 0);
   cpct_drawSpriteMaskedAlignedTable(g_title, backScreenPtr, G_TITLE_W, G_TITLE_H, gMaskTable);
   
   /** Select sprite and calculate its byte-ptr location Video Back Buffer */
   {
      const u8* fireSp = (gPosScroll % 2) == 0 ? g_fire_0 : g_fire_1;
      u8  x = VIEW_X + POS_SHIP_X - G_FIRE_0_W;
      u8  y = VIEW_Y + POS_SHIP_Y + 2;
      backScreenPtr = GetBackBufferPtr(x, y);
      
      cpct_drawSpriteMaskedAlignedTable(fireSp, backScreenPtr, G_FIRE_0_W, G_FIRE_0_H, gMaskTable);
   }
   
   backScreenPtr = GetBackBufferPtr(VIEW_X + POS_SHIP_X, VIEW_Y + POS_SHIP_Y);
   cpct_drawSpriteMasked(g_ship, backScreenPtr, G_SHIP_W, G_SHIP_H);
   
   // Flip memory buffer Back <-> Screen
   FlipBuffer();
}

/*****************************************************/
/*                                      */
/* Draw sprite Software double buffer            */
/*                                       */
/*****************************************************/
void DrawSWDoubleBuffer()
{
   u8* backBufferPtr;

   u8 i;
   for(i = 0; i < VIEW_W_BYTES; i++)
   {
      u8 offsetSpriteScroll = (gPosScroll + i)%gNbTileset; // Simulate scrolling by adding offset in sprite tileset index
      backBufferPtr = gBackBuffer + i;
      
      cpct_drawToSpriteBuffer(VIEW_W_BYTES, backBufferPtr, G_BACK_00_W, G_BACK_00_H, g_tileset[offsetSpriteScroll]);
   }

   /** Draw title at fixed coordinates */
   backBufferPtr = gBackBuffer + POS_TITLE_X;
   cpct_drawToSpriteBufferMaskedAlignedTable(VIEW_W_BYTES, backBufferPtr, G_TITLE_W, G_TITLE_H, g_title, gMaskTable);
   
   /** Select sprite and calculate its byte-ptr location inside Sprite BackBuffer */
   {
      const u8* fireSp = (gPosScroll % 2) == 0 ? g_fire_0 : g_fire_1;
      u8  x = POS_SHIP_X - G_FIRE_0_W;
      u8  y = POS_SHIP_Y + 2;
      backBufferPtr = cpctm_spriteBufferPtr(gBackBuffer, VIEW_W_BYTES, x, y);
      
      cpct_drawToSpriteBufferMaskedAlignedTable(VIEW_W_BYTES, backBufferPtr, G_FIRE_0_W, G_FIRE_0_H, fireSp, gMaskTable);
   }

   backBufferPtr = cpctm_spriteBufferPtr(gBackBuffer, VIEW_W_BYTES, POS_SHIP_X, POS_SHIP_Y);
   cpct_drawToSpriteBufferMasked(VIEW_W_BYTES, backBufferPtr, G_SHIP_W, G_SHIP_H, g_ship);

   /** Copy backBuffer to screen memory */
   CopyToScreen();
}

/*****************************************************/
/*                                      */
/* Check input keys to change draw function      */
/*                                       */
/*****************************************************/
void CheckUserInput() {
   cpct_scanKeyboard_f();
   
   if (cpct_isKeyPressed(Key_1)) {
      gDrawFunc = DrawSprite;
      DrawSelection(1);
   } else if (cpct_isKeyPressed(Key_2)) {
      gDrawFunc = DrawHWDoubleBuffer;
      DrawSelection(2);
   } else if (cpct_isKeyPressed(Key_3)) {
      gDrawFunc = DrawSWDoubleBuffer;
      DrawSelection(3);
   }
}

/*****************************************************/
/*                                      */
/* Initialization                          */
/*                                       */
/*****************************************************/
void Init()
{
   cpct_disableFirmware(); // Disable firmware in order to use HW double buffer
   cpct_memset((u8*)SCREEN_BUFF, 0, 0x4000); // Empty back buffer
   
   cpct_setPalette(g_palette, 5);   
   initVideoMemoryBuffers();
   
   gNbTileset = sizeof(g_tileset)/sizeof(u8*);
   gPosScroll = 0;
   
   gDrawFunc = DrawSprite;
   DrawSelection(1);
   
   DrawInfoText();
}

/*****************************************************/
/*                                      */
/* Draw main routine                       */
/*                                       */
/*****************************************************/
void main(void) 
{
   /** Change stack location in order to use HW double buffer */
   cpct_setStackLocation((u8*)NEW_STACK_LOCATION);
   Init();
   
   while(1)
   {
      CheckUserInput();
      
      // Scroll background, draw title, draw ship
      gPosScroll++;
      gDrawFunc();
   }
}
