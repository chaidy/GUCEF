/*
 *  ProjectGenerator: Tool to generate module/project files
 *  Copyright (C) 2002 - 2011.  Dinand Vanvelzen
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

#ifndef GUCEF_CORE_CDSTORECODECREGISTRY_H
#include "CDStoreCodecRegistry.h"
#define GUCEF_CORE_CDSTORECODECREGISTRY_H
#endif /* GUCEF_CORE_CDSTORECODECREGISTRY_H ? */

#ifndef GUCEF_CORE_CDSTORECODECPLUGINMANAGER_H
#include "CDStoreCodecPluginManager.h"
#define GUCEF_CORE_CDSTORECODECPLUGINMANAGER_H
#endif /* GUCEF_CORE_CDSTORECODECPLUGINMANAGER_H ? */

#ifndef GUCEF_CORE_CTRACER_H
#include "CTracer.h"
#define GUCEF_CORE_CTRACER_H
#endif /* GUCEF_CORE_CTRACER_H ? */

#ifndef GUCEF_CORE_DVCPPSTRINGUTILS_H
#include "dvcppstringutils.h"
#define GUCEF_CORE_DVCPPSTRINGUTILS_H
#endif /* GUCEF_CORE_DVCPPSTRINGUTILS_H ? */

#ifndef GUCEF_CORE_LOGGING_H
#include "gucefCORE_Logging.h"
#define GUCEF_CORE_LOGGING_H
#endif /* GUCEF_CORE_LOGGING_H ? */

#include "gucefProjectGenerator_CXmlProjectGenerator.h"

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCEF {
namespace PROJECTGENERATOR {

/*-------------------------------------------------------------------------//
//                                                                         //
//      UTILITIES                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

bool
WriteProjectInfoDataTreeToDisk( const TProjectInfo& projectInfo         ,
                                const CORE::CString& outputInfoFilename )
{GUCEF_TRACE;

    GUCEF_LOG( CORE::LOGLEVEL_NORMAL, "Preparing to write all project information to disk file \"" + outputInfoFilename + "\"" );

    CORE::CDStoreCodecRegistry::TDStoreCodecPtr codec = GetXmlDStoreCodec();
    if ( NULL != codec )
    {
        CORE::CDataNode info;
        if ( SerializeProjectInfo( projectInfo, info ) )
        {
            GUCEF_LOG( CORE::LOGLEVEL_NORMAL, "Successfully generated a data tree with all project information" );

            if ( codec->StoreDataTree( &info, outputInfoFilename ) )
            {
                GUCEF_LOG( CORE::LOGLEVEL_NORMAL, "Successfully wrote all project information to disk file \"" + outputInfoFilename + "\"" );
                return true;
            }
        }
    }
    GUCEF_ERROR_LOG( CORE::LOGLEVEL_NORMAL, "Failed to write all project information to disk file \"" + outputInfoFilename + "\"" );
    return false;
}

/*--------------------------------------------------------------------------*/

CXmlProjectGenerator::CXmlProjectGenerator( void )
{GUCEF_TRACE;

}

/*--------------------------------------------------------------------------*/
    
CXmlProjectGenerator::~CXmlProjectGenerator()
{GUCEF_TRACE;

}

/*-------------------------------------------------------------------------*/
    
bool
CXmlProjectGenerator::GenerateProject( TProjectInfo& projectInfo            ,
                                       const CORE::CString& outputDir       ,
                                       bool addGeneratorCompileTimeToOutput )
{GUCEF_TRACE;

    // Write all the project information we gathered to disk 
    CORE::CString projectinfoFilename = outputDir;
    CORE::AppendToPath( projectinfoFilename, "Project.xml" );
    return WriteProjectInfoDataTreeToDisk( projectInfo, projectinfoFilename );
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace PROJECTGENERATOR */
}; /* namespace GUCEF */

/*-------------------------------------------------------------------------*/
