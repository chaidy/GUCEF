/*
 *  gucefPATCHERAPP: Application module for the patcher application
 *  Copyright (C) 2002 - 2013.  Dinand Vanvelzen
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

#ifndef GUCEF_CORE_DVOSWRAP_H
#include "DVOSWRAP.h"
#define GUCEF_CORE_DVOSWRAP_H
#endif /* GUCEF_CORE_DVOSWRAP_H ? */

#ifndef GUCEF_CORE_CCOREGLOBAL_H
#include "gucefCORE_CCoreGlobal.h"
#define GUCEF_CORE_CCOREGLOBAL_H
#endif /* GUCEF_CORE_CCOREGLOBAL_H ? */

#ifndef GUCEF_CORE_CGUCEFAPPLICATION_H
#include "CGUCEFApplication.h"
#define GUCEF_CORE_CGUCEFAPPLICATION_H
#endif /* GUCEF_CORE_CGUCEFAPPLICATION_H ? */

#ifndef GUCEF_CORE_DVCPPSTRINGUTILS_H
#include "dvcppstringutils.h"
#define GUCEF_CORE_DVCPPSTRINGUTILS_H
#endif /* GUCEF_CORE_DVCPPSTRINGUTILS_H ? */

#ifndef GUCEF_GUI_CGUIGLOBAL_H
#include "gucefGUI_CGuiGlobal.h"
#define GUCEF_GUI_CGUIGLOBAL_H
#endif /* GUCEF_GUI_CGUIGLOBAL_H ? */

#ifndef GUCEF_GUI_CGUIMANAGER_H
#include "gucefGUI_CGUIManager.h"
#define GUCEF_GUI_CGUIMANAGER_H
#endif /* GUCEF_GUI_CGUIMANAGER_H ? */

#ifndef GUCEF_GUI_CWINDOWMANAGER_H
#include "gucefGUI_CWindowManager.h"
#define GUCEF_GUI_CWINDOWMANAGER_H
#endif /* GUCEF_GUI_CWINDOWMANAGER_H ? */

#ifndef GUCEF_GUI_CFORMEX_H
#include "gucefGUI_CFormEx.h"
#define GUCEF_GUI_CFORMEX_H
#endif /* GUCEF_GUI_CFORMEX_H ? */

#ifndef GUCEF_PATCHERAPP_CPATCHERAPPMAINCONFIG_H
#include "gucefPATCHERAPP_CPatcherAppConfig.h"
#define GUCEF_PATCHERAPP_CPATCHERAPPMAINCONFIG_H
#endif /* GUCEF_PATCHERAPP_CPATCHERAPPMAINCONFIG_H ? */

#ifndef GUCEF_PATCHERAPP_CPATCHERAPPGLOBAL_H
#include "gucefPATCHERAPP_CPatcherAppGlobal.h"
#define GUCEF_PATCHERAPP_CPATCHERAPPGLOBAL_H
#endif /* GUCEF_PATCHERAPP_CPATCHERAPPGLOBAL_H ? */

#include "gucefPATCHERAPP_CMainPatcherAppLogic.h"

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCEF {
namespace PATCHERAPP {

/*-------------------------------------------------------------------------//
//                                                                         //
//      IMPLEMENTATION                                                     //
//                                                                         //
//-------------------------------------------------------------------------*/

CMainPatcherAppLogic::CMainPatcherAppLogic( void )
    : CORE::CObservingNotifier() ,
      m_consoleLogger( NULL )    ,
      m_fileLogger( NULL )       ,
      m_logFile( NULL )          ,
      m_consoleWindow( NULL )
{GUCEF_TRACE;

    TEventCallback callback( this, &CMainPatcherAppLogic::OnFirstAppCycle ); 
    SubscribeTo( &CORE::CCoreGlobal::Instance()->GetApplication() , 
                 CORE::CGUCEFApplication::FirstCycleEvent         ,
                 callback                                         );
}

/*-------------------------------------------------------------------------*/

CMainPatcherAppLogic::~CMainPatcherAppLogic()
{GUCEF_TRACE;

    Shutdown();
}

/*-------------------------------------------------------------------------*/

Int32
CMainPatcherAppLogic::Init( UInt32 argc, const char** argv )
{GUCEF_TRACE;

    SetupLogging();
    return 1;
}

/*-------------------------------------------------------------------------*/

void
CMainPatcherAppLogic::Shutdown( void )
{GUCEF_TRACE;

    ShutdownLogging();
}

/*-------------------------------------------------------------------------*/

bool
CMainPatcherAppLogic::SetupWindowContext( GUI::TWindowManagerBackendPtr windowMngrBackend ,
                                          const GUI::CString& windowMngrBackendName       ,
                                          const GUI::CString& guiDriverToUse              )
{GUCEF_TRACE;

    GUI::CString windowTitle( "Galaxy Unlimited Patcher" );
    GUI::TWindowContextPtr windowContext = windowMngrBackend->CreateWindowContext( windowTitle ,
                                                                                   800         ,
                                                                                   600         ,
                                                                                   false       );

    if ( NULL != windowContext )
    {
        GUCEF_LOG( CORE::LOGLEVEL_NORMAL, "Successfully created window context using backend " + windowMngrBackendName );

        // create GUI context for our window
        GUI::TGuiContextPtr guiContext = GUI::CGuiGlobal::Instance()->GetGuiManager().CreateGUIContext( guiDriverToUse, windowContext );
        if ( NULL != guiContext )
        {
            GUCEF_LOG( CORE::LOGLEVEL_NORMAL, "Successfully created GUI context using backend " + guiDriverToUse );

            // Load some fonts
           // LoadFonts( guiContext );

            CPatcherAppConfig& config = CPatcherAppGlobal::Instance()->GetConfig();
            const CString& initialFormTypeName = config.GetInitialFormTypeName();

            // Create a form to load the layout into
            GUI::CFormEx* form = static_cast< GUI::CFormEx* >( guiContext->CreateForm( initialFormTypeName ) );
            if ( NULL != form )
            {
                GUCEF_LOG( CORE::LOGLEVEL_NORMAL, "Successfully created form object of type: " + initialFormTypeName );

                // load the initial layout resource
                const CString& initialFormResourcePath = config.GetInitialFormResourcePath();
                if ( form->LoadLayout( initialFormResourcePath ) )
                {
                    GUCEF_LOG( CORE::LOGLEVEL_NORMAL, "Successfully loaded form from resource: " + initialFormResourcePath );
                    return form->Show();
                }
            }
        }
    }
    else
    {
        GUCEF_ERROR_LOG( CORE::LOGLEVEL_NORMAL, "Failed to obtain a window context" );
    }

    return false;
}

/*-------------------------------------------------------------------------*/

void
CMainPatcherAppLogic::ShutdownLogging( void )
{GUCEF_TRACE;

    if ( NULL != m_fileLogger )
    {
        CORE::CCoreGlobal::Instance()->GetLogManager().RemoveLogger( m_fileLogger );
    }
    if ( NULL != m_consoleLogger )
    {
        CORE::CCoreGlobal::Instance()->GetLogManager().RemoveLogger( m_consoleLogger->GetLogger() );
    }

    delete m_consoleLogger;
    m_consoleLogger = NULL;
    
    delete m_fileLogger;
    m_fileLogger = NULL;

    delete m_logFile;
    m_logFile = NULL;
}

/*-------------------------------------------------------------------------*/

void
CMainPatcherAppLogic::SetupLogging( void )
{GUCEF_TRACE;
    
    // Cleanup, in case invoked multiple times
    ShutdownLogging();
    
    CPatcherAppConfig& config = CPatcherAppGlobal::Instance()->GetConfig();
    
    if ( config.IsFileLoggerEnabled() )
    {
        // Setup file to log to with file logger
        m_logFile = new CORE::CFileAccess( config.GetLogFilePath(), "w" );

        // setup file logger
        m_fileLogger = new CORE::CStdLogger( *m_logFile );
        CORE::CCoreGlobal::Instance()->GetLogManager().AddLogger( m_fileLogger );
    }

    if ( config.IsConsoleLoggerEnabled() )
    {
        // setup console logger
        m_consoleLogger = new CORE::CPlatformNativeConsoleLogger();
        CORE::CCoreGlobal::Instance()->GetLogManager().AddLogger( m_consoleLogger->GetLogger() );
    }

    // flush startup log entries
    CORE::CCoreGlobal::Instance()->GetLogManager().FlushBootstrapLogEntriesToLogs();
}

/*-------------------------------------------------------------------------*/
    
void
CMainPatcherAppLogic::OnFirstAppCycle( CORE::CNotifier* notifier    ,
                                       const CORE::CEvent& eventid  ,
                                       CORE::CICloneable* eventdata )
{GUCEF_TRACE;

    try
    {
        CPatcherAppConfig& config = CPatcherAppGlobal::Instance()->GetConfig();

        if ( config.IsConsoleWindowEnabled() )
        {
            // Create console window for easy debugging interaction
            delete m_consoleWindow;
            m_consoleWindow = new CORE::CPlatformNativeConsoleWindow();
            m_consoleWindow->CreateConsole();
        }
        
        const CString& windowManagerName = config.GetWindowManagerName();
        if ( windowManagerName.IsNULLOrEmpty() )
        {
            GUCEF_ERROR_LOG( CORE::LOGLEVEL_CRITICAL, "There is no window manager defined, unable to start" );
            CORE::CCoreGlobal::Instance()->GetApplication().Stop();
            return;
        }

        GUI::TWindowManagerBackendPtr windowMngrBackend = GUI::CGuiGlobal::Instance()->GetWindowManager().GetBackend( windowManagerName );
        if ( NULL != windowMngrBackend )
        {
            GUCEF_LOG( CORE::LOGLEVEL_NORMAL, "Successfully obtained window manager backend " + windowManagerName );

            // Setup a window context for each GUI driver
            if ( SetupWindowContext( windowMngrBackend, windowManagerName, config.GetGuiBackendName() ) )
            {
                GUCEF_LOG( CORE::LOGLEVEL_NORMAL, "Successfully created a window context using GUI backend " + config.GetGuiBackendName() );
            }
            else
            {
                GUCEF_ERROR_LOG( CORE::LOGLEVEL_CRITICAL, "Failed to setup a window context for GUI driver " + config.GetGuiBackendName() );
                CORE::CCoreGlobal::Instance()->GetApplication().Stop();
            }
        }
        else
        {
            GUCEF_ERROR_LOG( CORE::LOGLEVEL_CRITICAL, "Failed to obtain window management backend" );
            CORE::CCoreGlobal::Instance()->GetApplication().Stop();
        }
    }
    catch ( ... )
    {
        #ifdef GUCEF_GUI_DEBUG_MODE
        CORE::GUCEF_PrintCallstack();
        CORE::GUCEF_DumpCallstack( "gucefGUI_TestApp_callstack.txt" );
        #endif /* GUCEF_GUI_DEBUG_MODE ? */

        CORE::ShowErrorMessage( "Unknown exception"                                                                 ,
                                "Unhandled exception during program execution, the application will now terminate"  );
        CORE::CCoreGlobal::Instance()->GetApplication().Stop();
    }
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace PATCHERAPP */
}; /* namespace GUCEF */

/*-------------------------------------------------------------------------*/