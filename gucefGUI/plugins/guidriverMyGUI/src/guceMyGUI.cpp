/*
 *  guidriverMyGUI: glue module for the MyGUI GUI backend
 *  Copyright (C) 2002 - 2007.  Dinand Vanvelzen
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

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCEF_DLLINIT_H
#include "gucef_DLLInit.h"
#define GUCEF_DLLINIT_H
#endif /* GUCEF_DLLINIT_H ? */

#ifndef GUCE_MYGUI_CMODULE_H
#include "guceMyGUI_CModule.h"
#define GUCEF_MYGUI_CMODULE_H
#endif /* GUCEF_MYGUI_CMODULE_H ? */

#include "guceMyGUI.h"

/*-------------------------------------------------------------------------//
//                                                                         //
//      UTILITIES                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

//GUCEF_DLL_INIT_FUNC_BEG_END( GUCE::MYGUIOGRE::CModule );

/*-------------------------------------------------------------------------*/

const char*
GUCE_MYGUIOGRE_ModuleCompileTimeStamp( void )
{
    return __TIMESTAMP__;
}

/*-------------------------------------------------------------------------*/