/*
 *  gucefCORE: GUCEF module providing O/S abstraction and generic solutions
 *  Copyright (C) 2002 - 2007.  Dinand Vanvelzen
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

#ifndef GUCEF_CORE_MACROS_H
#include "gucefCORE_macros.h"         /* often used gucefCORE macros */
#define GUCEF_CORE_MACROS_H
#endif /* GUCEF_CORE_MACROS_H ? */

#ifndef GUCEF_CORE_CLOGMANAGER_H
#include "CLogManager.h"
#define GUCEF_CORE_CLOGMANAGER_H
#endif /* GUCEF_CORE_CLOGMANAGER_H ? */

#ifndef GUCEF_CORE_DVCPPSTRINGUTILS_H
#include "dvcppstringutils.h"
#define GUCEF_CORE_DVCPPSTRINGUTILS_H
#endif /* GUCEF_CORE_DVCPPSTRINGUTILS_H ? */

#ifndef GUCEF_CORE_CGENERICPLUGIN_H
#include "CGenericPlugin.h"
#define GUCEF_CORE_CGENERICPLUGIN_H
#endif /* GUCEF_CORE_CGENERICPLUGIN_H ? */

#ifndef GUCEF_CORE_DVFILEUTILS_H
#include "dvfileutils.h"
#define GUCEF_CORE_DVFILEUTILS_H
#endif /* GUCEF_CORE_DVFILEUTILS_H ? */

#ifndef GUCEF_CORE_CTRACER_H
#include "CTracer.h"
#define GUCEF_CORE_CTRACER_H
#endif /* GUCEF_CORE_CTRACER_H ?  */

#include "CGenericPluginManager.h"

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCEF {
namespace CORE {

/*-------------------------------------------------------------------------//
//                                                                         //
//      GLOBAL VARS                                                        //
//                                                                         //
//-------------------------------------------------------------------------*/

CGenericPluginManager* CGenericPluginManager::m_instance = NULL;

/*-------------------------------------------------------------------------//
//                                                                         //
//      UTILITIES                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

CGenericPluginManager::CGenericPluginManager( void )
    : CPluginManager()
{GUCEF_TRACE;
}

/*-------------------------------------------------------------------------*/

CGenericPluginManager::~CGenericPluginManager()
{GUCEF_TRACE;
}

/*-------------------------------------------------------------------------*/

CGenericPluginManager*
CGenericPluginManager::Instance( void )
{GUCEF_TRACE;
    if ( !m_instance )
    {
        m_instance = new CGenericPluginManager();
        GUCEF_SYSTEM_LOG( LOGLEVEL_NORMAL, "GUCEF::CORE::CGenericPluginManager Singleton created" );
    }
    
    return m_instance;
}

/*-------------------------------------------------------------------------*/

void
CGenericPluginManager::Deinstance( void )
{GUCEF_TRACE;
    
    delete m_instance;
    m_instance = NULL;
    GUCEF_SYSTEM_LOG( LOGLEVEL_NORMAL, "GUCEF::CORE::CGenericPluginManager Singleton destroyed" );
}

/*-------------------------------------------------------------------------*/

void
CGenericPluginManager::LoadAll( void )
{GUCEF_TRACE;

    CString pluginDir( GetPluginDir() );
    CString pluginPath( pluginDir );
    struct SDI_Data* dirInfo = DI_First_Dir_Entry( pluginDir.C_String() );
    if ( NULL != dirInfo )
    {
        do
        {
            // Check if the dir entry is a file and not a dir
            if ( 0 != DI_Is_It_A_File( dirInfo ) )
            {
                // build the path string to the file
                AppendToPath( pluginPath         ,
                              DI_Name( dirInfo ) );
                
                // now we try to load the file as a generic plugin
                Load( pluginPath ); 
                
                // reset path for next loop iteration
                pluginPath = pluginDir; 
            }
            
        } while ( 0 != DI_Next_Dir_Entry( dirInfo ) );
        
        DI_Cleanup( dirInfo );
    }
}

/*-------------------------------------------------------------------------*/
    
void
CGenericPluginManager::UnloadAll( void )
{GUCEF_TRACE;
    
    TPluginList::iterator i = m_pluginList.begin();
    while ( i != m_pluginList.end() )
    {
        // notify observers that we are about to unload the module
        NotifyObservers( PluginUnloadedEvent );
        
        // Perform the actual unload
        (*i)->Unload();
        delete (*i);
        (*i) = NULL;
        
        ++i;
    }
    
    m_pluginList.clear();
}

/*-------------------------------------------------------------------------*/
    
bool
CGenericPluginManager::IsLoaded( const CString& pluginPath )
{GUCEF_TRACE;

    TPluginList::iterator i = m_pluginList.begin();
    while ( i != m_pluginList.end() )
    {
        if ( pluginPath == (*i)->GetModulePath() )
        {
            return true;
        }
        
        ++i;
    }
    
    return false;
}

/*-------------------------------------------------------------------------*/

bool
CGenericPluginManager::Load( const CString& pluginPath )
{GUCEF_TRACE;
    
    if ( !IsLoaded( pluginPath ) )
    {
        GUCEF_SYSTEM_LOG( LOGLEVEL_NORMAL, "Attempting to load generic plugin: " + pluginPath );
        
        CGenericPlugin* plugin = new CGenericPlugin();
        if ( plugin->Load( pluginPath ) )
        {
            GUCEF_SYSTEM_LOG( LOGLEVEL_NORMAL, "Generic plugin loaded: " + pluginPath );
            
            // The file has been successfully loaded as a generic plugin module
            m_pluginList.push_back( plugin );
            
            // Notify the observers of this event
            NotifyObservers( PluginLoadedEvent );
            
            return true;
        }
        else
        {
            GUCEF_SYSTEM_LOG( LOGLEVEL_NORMAL, "Failed to load module as a generic plugin: " + pluginPath );
            
            // Failed to load the file as a generic plugin
            delete plugin;
            return false;
        }
        
    }
    
    // Already loaded
    return true;
}

/*-------------------------------------------------------------------------*/
    
bool
CGenericPluginManager::Unload( const CString& pluginPath )
{GUCEF_TRACE;

    TPluginList::iterator i = m_pluginList.begin();
    while ( i != m_pluginList.end() )
    {
        if ( pluginPath == (*i)->GetModulePath() )
        {
            GUCEF_SYSTEM_LOG( LOGLEVEL_NORMAL, "Attempting to unload generic plugin: " + pluginPath );

            // Perform the actual unload
            if ( (*i)->Unload() )
            {
                GUCEF_SYSTEM_LOG( LOGLEVEL_NORMAL, "Generic plugin unloaded: " + pluginPath );
                
                // notify observers that we unloaded the module
                NotifyObservers( PluginUnloadedEvent );
                            
                m_pluginList.erase( i );
            }
            return true;
        }
        
        ++i;
    }
    
    // Cannot find module
    return false;
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

} /* namespace CORE */
} /* namespace GUCEF */

/*-------------------------------------------------------------------------*/