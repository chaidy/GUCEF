/*
 *  vfspluginVP: Generic GUCEF VFS plugin for "Violation Pack" archives
 *  Copyright (C) 2002 - 2008.  Dinand Vanvelzen
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
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

#ifndef GUCEF_CORE_CVALUELIST_H
#include "CValueList.h"
#define GUCEF_CORE_CVALUELIST_H
#endif /* GUCEF_CORE_CVALUELIST_H ? */

#ifndef GUCEF_CORE_CLOGMANAGER_H
#include "CLogManager.h"
#define GUCEF_CORE_CLOGMANAGER_H
#endif /* GUCEF_CORE_CLOGMANAGER_H ? */

#ifndef GUCEF_LOGSERVICELIB_CLOGSVCCLIENT_H
#include "GucefLogServiceLib_CLogSvcClient.h"
#define GUCEF_LOGSERVICELIB_CLOGSVCCLIENT_H
#endif /* GUCEF_LOGSERVICELIB_CLOGSVCCLIENT_H ? */

#include "GucefLogServiceClientPlugin.h"

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCEF {
namespace LOGSERVICECLIENTPLUGIN {

/*--------------------------------------------------------------------------*/

using namespace LOGSERVICELIB;

/*-------------------------------------------------------------------------//
//                                                                         //
//      GLOBAL VARS                                                        //
//                                                                         //
//-------------------------------------------------------------------------*/

CLogSvcClient svcClient;

/*-------------------------------------------------------------------------//
//                                                                         //
//      UTILITIES                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

void
ParseParams( const int argc                 , 
             const char** argv              ,
             CORE::CValueList& keyValueList )
{GUCEF_TRACE;
    
    keyValueList.DeleteAll();
    for ( CORE::Int32 i=0; i<argc; ++i ) 
    {
        keyValueList.Set( argv[ i ] );
    }
}

/*--------------------------------------------------------------------------*/

CORE::Int32 GUCEF_PLUGIN_CALLSPEC_PREFIX 
GUCEFPlugin_Load( CORE::UInt32 argc, const char** argv ) GUCEF_PLUGIN_CALLSPEC_SUFFIX
{GUCEF_TRACE;

    // Parse the plugin parameters
    CORE::CValueList keyValueList;
    ParseParams( argc, argv, keyValueList );

    CORE::CString addressOfService = keyValueList.GetValueAlways( "logServiceAddress" );
    if ( 0 == addressOfService.Length() )
    {
        // Connecting to localhost is the default
        addressOfService = "localhost";
    }
    
    CORE::UInt16 logServicePort = 43557;
    if ( keyValueList.HasKey( "logServicePort" ) )
    {
        logServicePort = CORE::StringToUInt16( keyValueList.GetValueAlways( "logServicePort" ) );
    }
    
    svcClient.ConnectTo( addressOfService, logServicePort );

    CORE::CLogManager::Instance()->AddLogger( &svcClient );
    
    return 1;
}

/*--------------------------------------------------------------------------*/

void GUCEF_PLUGIN_CALLSPEC_PREFIX 
GUCEFPlugin_Unload( void ) GUCEF_PLUGIN_CALLSPEC_SUFFIX
{GUCEF_TRACE;

    CORE::CLogManager::Instance()->RemoveLogger( &svcClient );
}

/*--------------------------------------------------------------------------*/

void GUCEF_PLUGIN_CALLSPEC_PREFIX 
GUCEFPlugin_GetVersion( CORE::TVersion* versionInfo ) GUCEF_PLUGIN_CALLSPEC_SUFFIX
{GUCEF_TRACE;

    versionInfo->major = 1; 
    versionInfo->minor = 0;
    versionInfo->patch = 0;
    versionInfo->release = 0;
}

/*--------------------------------------------------------------------------*/

const char* GUCEF_PLUGIN_CALLSPEC_PREFIX 
GUCEFPlugin_GetCopyright( void ) GUCEF_PLUGIN_CALLSPEC_SUFFIX
{GUCEF_TRACE;
    
    return "Copyright (C) 2010.  Dinand Vanvelzen, Released under LGPLv2 or later";
}

/*--------------------------------------------------------------------------*/

const char* GUCEF_PLUGIN_CALLSPEC_PREFIX 
GUCEFPlugin_GetDescription( void ) GUCEF_PLUGIN_CALLSPEC_SUFFIX
{GUCEF_TRACE;

    return "Generic GUCEF plugin for communication with the GUCEF Log service";
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace LOGSERVICECLIENTPLUGIN */
}; /* namespace GUCEF */

/*-------------------------------------------------------------------------*/
