/*Unix framework -- mcursor.h
* Library for edit cursor in WM based on X11(if supported)
*
*  Copyright (C) 2025 UnixSD

   This file is part of Unix Engine.

   Unix Engine is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Unix Engine is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Unix Engine.  If not, see <http://www.gnu.org/licenses/>.
*/

#if defined(_WIN32)
#   error "Unsupported OS: please use Unix-like system"
#elif defined(__APPLE__) && defined(__MACH__)
#   pragma message("[Warning]: Work may be unstable on macOS")
#endif

#include <X11/Xlib.h>

Display *display = XOpenDisplay(nullptr);
Window root = DefaultRootWindow(display);

namespace CursorProperty
{
    void setPos(int x, int y);
    void Grab(int x, int y);
    void UnGrab();

    void SetIcon();
    void SetCursor();

    int getPosX();
    int getPosY();
}

