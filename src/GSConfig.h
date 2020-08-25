/***************************************************************************
 *   Copyright (c) 2020 Gustavo Carneiro <gcarneiroa@hotmail.com>          *
 *                                                                         *
 *   This file is part of the GSystem development system.                  *
 *                                                                         *
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Library General Public           *
 *   License as published by the Free Software Foundation; either          *
 *   version 2 of the License, or (at your option) any later version.      *
 *                                                                         *
 *   This library  is distributed in the hope that it will be useful,      *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Library General Public License for more details.                  *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this library; see the file COPYING.LIB. If not,    *
 *   write to the Free Software Foundation, Inc., 59 Temple Place,         *
 *   Suite 330, Boston, MA  02111-1307, USA                                *
 *                                                                         *
 ***************************************************************************/

#ifndef GSCONFIG_H
#define GSCONFIG_H

#if defined (FC_OS_WIN32) || defined(FC_OS_CYGWIN)
    #ifdef GSAPP
        #define AppExport   __declspec(dllexport)
        #define DataExport  __declspec(dllexport)
    #else
        #define AppExport   __declspec(dllimport)
        #define DataExport  __declspec(dllimport)
    #endif
    #ifdef GSBase
        #define BaseExport  __declspec(dllexport)
    #else
        #define BaseExport  __declspec(dllimport)
    #endif
    #ifdef GSGui
        #define GuiExport   __declspec(dllexport)
    #else
        #define GuiExport   __declspec(dllimport)
    #endif
#else
    #ifndef BaseExport
        #define BaseExport
    #endif
    #ifndef GuiExport
        #define GuiExport
    #endif
    #ifndef AppExport
        #define AppExport
    #endif
    #ifndef DataExport
        #define DataExport
    #endif
#endif

#endif
