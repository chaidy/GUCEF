/*
 *  gucefMT: GUCEF module providing multithreading solutions
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
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef GUCEF_MT_CCRITICALSECTION_H
#define GUCEF_MT_CCRITICALSECTION_H

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCEF_MT_ETYPES_H
#include "gucefMT_ETypes.h"           /* simple types used */
#define GUCEF_MT_ETYPES_H
#endif /* GUCEF_MT_ETYPES_H ? */

#ifndef GUCEF_MT_MACROS_H
#include "gucefMT_macros.h"           /* often used gucef macros */
#define GUCEF_MT_MACROS_H
#endif /* GUCEF_MT_MACROS_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCEF {
namespace MT {

/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/

/**
 *      O/S Wrapper class for a critical section.
 *
 *      A critical section object provides synchronization similar to that
 *      provided by a mutex object, except that a critical section can be used
 *      only by the threads of a single process. Event, mutex, and semaphore
 *      objects can also be used in a single-process application, but critical
 *      section objects provide a slightly faster, more efficient mechanism
 *      for mutual-exclusion synchronization (a processor-specific test and set
 *      instruction). Like a mutex object, a critical section object can be
 *      owned by only one thread at a time, which makes it useful for protecting
 *      a shared resource from simultaneous access. There is no guarantee about
 *      the order that threads obtain ownership of the critical section,
 *      however, the system is fair to all threads. Unlike a mutex object, there
 *      is no way to tell whether a critical section has been abandoned.
 *
 */
class GUCEF_MT_PUBLIC_CPP CCriticalSection
{
        private:
        void* _data;
        CCriticalSection( const CCriticalSection& ); /* copy's arent allowed */
        CCriticalSection& operator=( const CCriticalSection& );        /* copy's arent allowed */

        public:

        CCriticalSection( void );

        ~CCriticalSection();

        /**
         *      Signals a willingness to start using protected data/code.
         *      blocks until the thread can take ownership of the critical
         *      section.
         */
        void Enter( void );

        /**
         *      Signals that we are done with the protected data/code.
         */
        void Leave( void );
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace MT */
}; /* namespace GUCEF */

/*--------------------------------------------------------------------------*/

#endif /* GUCEF_MT_CCRITICALSECTION_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 16-10-2004 :
       - Designed and implemented this class.

-----------------------------------------------------------------------------*/
