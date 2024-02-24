# UTFT_DDIG
UTFT DDIG was made to improve the display response time of seven-segment numbers, the accepted value is between 0-9 and 10-15 (A-F)

This library (UTFT_DDIG) extends the UTFT_DLB library, which in turn extends the UTFT library.

So both libraries are needed.

UTFT DDIG was made to improve the display response time of seven-segment numbers, the accepted value is between 0-9 and 10-15 (A-F)

- Note: Version adapted to work with the TFT_eSPI library [TFT_DDIG](https://github.com/rtek1000/TFT_DDIG)

You can control:

- Position
- Width
- Height
- Thickness (Minimum segment thickness: 2 px)
- Color

Test: [UTFT_DDIG speed test example (Arduino Mega + SSD1963 with 7 inch TFT) - YouTube](https://www.youtube.com/watch?v=amKvzLVV9GM)
- (The red number originates in the font made for the UTFT library, the green color numbers are generated in the library code UTFT_DDIG)

UTFT: http://www.rinkydinkelectronics.com/library.php?id=51

UTFT_DLB: https://sites.google.com/site/dlbarduino/downloads

Ref.: https://forum.arduino.cc/t/utft_ddig-display-seven-segment-numbers-faster-than-using-character-font/489801

----

Note: As this library only uses the draw line function ("drawL()"), this code can be adapted to operate with other libraries that can draw a line.

----

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
