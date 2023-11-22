/*
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
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef UTFT_DDIG_h
#define UTFT_DDIG_h

#include "arduino.h"
#include <UTFT_DLB.h>

#define drawL drawLine
#define setC setColor

class UTFT_DDIG : public UTFT_DLB
{

 public:
    UTFT_DDIG();
    UTFT_DDIG(byte model, int RS, int WR,int CS, int RST, int SER=0);
void configDigit(int Width, int Height, int Depth);

void drawDigit(int num, int setDigX, int setDigY, unsigned int color, unsigned int bgcolor);
    int digX, digY, digHeight = 144, digWidth = 96, digDepth = 10, space;
private:
    void drawSegHoriz(int x1, int y1, int x2, int y2, int segDepth);
    void drawSegVert(int x1, int y1, int x2, int y2, int segDepth);
    void drawSegmentA(unsigned int color);
    void drawSegmentB(unsigned int color);
    void drawSegmentC(unsigned int color);
    void drawSegmentD(unsigned int color);
    void drawSegmentE(unsigned int color);
    void drawSegmentF(unsigned int color);
    void drawSegmentG(unsigned int color);
};

#endif