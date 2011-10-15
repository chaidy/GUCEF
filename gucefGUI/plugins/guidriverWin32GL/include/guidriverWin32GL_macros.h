/*
 *  guidriverWin32GL: module implementing GL based window management for Win32
 *  Copyright (C) 2002 - 2011.  Dinand Vanvelzen
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef GUIDRIVERWIN32GL_MACROS_H
#define GUIDRIVERWIN32GL_MACROS_H

/*
 *      Build configuration specific macros.
 *      Also includes the generic macros which are build config independant.
 */

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCEF_GUI_MACROS_H
#include "gucefGUI_macros.h"
#define GUCEF_GUI_MACROS_H
#endif /* GUCEF_GUI_MACROS_H ? */

#ifndef GUIDRIVERWIN32GL_CONFIG_H
#include "guidriverWin32GL_config.h"
#define GUIDRIVERWIN32GL_CONFIG_H
#endif /* GUIDRIVERWIN32GL_CONFIG_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      GENERAL MACROS                                                     //
//                                                                         //
//-------------------------------------------------------------------------*/

/*
 *      Macros for dynamic linking or static linking. Use the switches in the
 *      config file to control the export type.
 */

#undef GUIDRIVERWIN32GL_EXPORTSPEC
#ifdef GUIDRIVERWIN32GL_BUILD_MODULE
  #define GUIDRIVERWIN32GL_EXPORTSPEC GUCEF_EXPORT
#else
  #define GUIDRIVERWIN32GL_EXPORTSPEC GUCEF_IMPORT
#endif /* GUIDRIVERWIN32GL_BUILD_MODULE ? */

#undef GUIDRIVERWIN32GL_PUBLIC_CPP
#ifdef GUIDRIVERWIN32GL_PUBLIC_CPP_CODE
  #define GUIDRIVERWIN32GL_PUBLIC_CPP GUIDRIVERWIN32GL_EXPORTSPEC
#else
  #define GUIDRIVERWIN32GL_PUBLIC_CPP GUCEF_HIDDEN
#endif /* GUIDRIVERWIN32GL_EXPORT_CPP_CODE */

#define GUIDRIVERWIN32GL_PRIVATE_CPP GUCEF_HIDDEN

#undef GUIDRIVERWIN32GL_PUBLIC_C
#ifdef GUIDRIVERWIN32GL_PUBLIC_C_CODE
  #define GUIDRIVERWIN32GL_PUBLIC_C GUIDRIVERWIN32GL_EXPORTSPEC
#else
  #define GUIDRIVERWIN32GL_PUBLIC_C GUCEF_HIDDEN
#endif /* GUIDRIVERWIN32GL_PUBLIC_C_CODE */

#define GUIDRIVERWIN32GL_PRIVATE_C GUCEF_HIDDEN

/*-------------------------------------------------------------------------*/

#endif /* GUIDRIVERWIN32GL_MACROS_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 02-03-2007 :
        - Dinand: re-added this header

---------------------------------------------------------------------------*/