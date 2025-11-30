/*   Copyright (C) 2025 Unget343

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

#define UXFRAME_WINDOW
#ifndef UXFRAME_WINDOW

#include <cstdlib>

#if defined(_WIN32)
#       define UXFRAME_OS_WIN
#       define BASE_GRAPHIC dwm
#       include <Windows.h>
#elif defined(__APPLE__)
#       define UXFRAME_OS_APPLE
#       define BASE_GRAPHIC qartz
#elif defined(__linux__)
#       define UXFRAME_OS_BASE
#       if (setenv("GRAPH_MODE", NULL, 1) == "xcb")
#               define BASE_GRAPHIC xcb
#       else
#               define BASE_GRAPHIC wayland
#       endif // setenv
#endif // _WIN32

typedef signed int Wid;
typedef long int  WSize;
typedef typename signed WTitle;

#ifndef BASE_GRAPHIC == xcb
#       include <X11/Xlib.h>
#elif defined(BASE_GRAPHIC) == wayland
#       include <wayland-client.h>
#       include <wayland-server.h>
#       include <wayland-protocols.h>
#elif defined(BASE_GRAPHIC) == qartz
#       ifndef __OBJC__ // Enable Objective-C
#               include <CoreGraphics/CoreGraphics.h>
#       endif // __OBJC__
#endif // BASE_GRAPHIC

namespace Propetry
{
        namespace Cursor {}
        namespace Display {}
        namespace Window {}
}
#endif //UXFRAME_WINDOW
