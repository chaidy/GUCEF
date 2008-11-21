/*
 *  gucefCOMCORE: GUCEF module providing basic communication facilities
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

#include "CTCPServerConnection.h"       /* header for this class */

#include "CTCPServerSocket.h"           /* parent server socket */
#include "tsprinting.h"			/* threadsafe printing */

#ifdef GUCEF_MSWIN_BUILD

#ifndef DVWINSOCK_H
#include "dvwinsock.h"
#define DVWINSOCK_H
#endif /* DVWINSOCK_H ? */

#include <winsock2.h>                   /* windows networking API */

#endif /* GUCEF_MSWIN_BUILD ? */

#ifdef ACTIVATE_MEMORY_MANAGER
  #ifndef GUCEF_NEW_ON_H
  #include "gucef_new_on.h"   /* Use the GUCEF memory manager instead of the standard manager ? */
  #define GUCEF_NEW_ON_H
  #endif /* GUCEF_NEW_ON_H ? */
#endif /* ACTIVATE_MEMORY_MANAGER ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCEF {
namespace COMCORE {

/*-------------------------------------------------------------------------//
//                                                                         //
//      CONSTANTS                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

#define BUFFER_READ_SIZE	25

/*-------------------------------------------------------------------------//
//                                                                         //
//      TYPES                                                              //
//                                                                         //
//-------------------------------------------------------------------------*/

struct STCPServerConData
{
        UInt32 sockid;
        CORE::CString clientip;
        struct sockaddr_in clientaddr;
        struct timeval timeout;         /* timeout for blocking operations */
};
typedef struct STCPServerConData TTCPServerConData;

/*-------------------------------------------------------------------------//
//                                                                         //
//      UTILITIES                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

/**
 *      Constructor,
 *      init vars
 */
CTCPServerConnection::CTCPServerConnection( CTCPServerSocket *tcp_serversock ,
                                            UInt32 connection_idx            )
        : CTCPConnection()                    ,
          _active( false )                    ,
          m_maxreadbytes( 0 )                 ,
          m_parentsock( tcp_serversock )      ,
          m_connectionidx( connection_idx )   ,
          _blocking( false )
          
{GUCEF_TRACE;
        
        _data = new TTCPServerConData;        
}

/*-------------------------------------------------------------------------*/

CTCPServerConnection::~CTCPServerConnection()
{GUCEF_TRACE;

        Close();      
        
        delete _data;
}

/*-------------------------------------------------------------------------*/

const CORE::CString&
CTCPServerConnection::GetRemoteHostName( void ) const
{GUCEF_TRACE;

    return _data->clientip;
}

/*-------------------------------------------------------------------------*/

CIPAddress
CTCPServerConnection::GetRemoteIP( void ) const
{GUCEF_TRACE;

    return CIPAddress( _data->clientaddr.sin_addr.S_un.S_addr, _data->clientaddr.sin_port );
}

/*-------------------------------------------------------------------------*/

UInt16
CTCPServerConnection::GetRemoteTCPPort( void ) const
{GUCEF_TRACE;

    return ntohs( _data->clientaddr.sin_port );
}

/*-------------------------------------------------------------------------*/

void
CTCPServerConnection::Close( void )
{GUCEF_TRACE;

        _datalock.Lock();
        
        closesocket( _data->sockid ); 
        _active = false;
        
        NotifyObservers( DisconnectedEvent );
        
        m_parentsock->OnClientConnectionClosed( this            ,
                                                m_connectionidx ,
                                                false           );
                                                                        
        _datalock.Unlock();
}

/*-------------------------------------------------------------------------*/

bool
CTCPServerConnection::Send( const void* dataSource , 
                            const UInt32 length    )
{GUCEF_TRACE;
        
        _datalock.Lock();
        int error;
        Int32 wbytes = WSTS_send( _data->sockid ,  
                                  dataSource    , 
                                  length        , 
                                  0             , 
                                  &error        );
                   
        _datalock.Unlock();                   

     /*   if ( Active() )
        {
        	if ( parent->IFace() ) parent->IFace()->OnClientWrite( *parent, index, data, length );
        }      */


        return wbytes >= 0;
}

/*-------------------------------------------------------------------------*/

void
CTCPServerConnection::SetMaxRead( UInt32 mr )
{GUCEF_TRACE;

        /*
         *      Although the setting of the int value may be atomic we must
         *      use a mutex lock so that a current read proccess will not be
         *      affected. Thus the setting will take effect on the next read
         *      cycle.
         */
        _datalock.Lock();
        m_maxreadbytes = mr;
        _datalock.Unlock();          
}

/*-------------------------------------------------------------------------*/

UInt32
CTCPServerConnection::GetMaxRead( void ) const
{GUCEF_TRACE;

        return m_maxreadbytes;
}

/*-------------------------------------------------------------------------*/

bool
CTCPServerConnection::Read( char *dest     , 
                            UInt32 size    , 
                            UInt32 &wbytes , 
                            Int32 timeout  )
{GUCEF_TRACE;

     //   _datalock.Lock();
     //   recv( _data->sockid              ,
     //         _readbuffer.GetBufferPtr() ,
     //         _readbuffer.GetSize()      ,
     //         0                          );
              
        
     /*
        if ( !datalock.Lock_Mutex() ) return false;
	rb_dest = dest;
        rb_size = size;
        rb_wbytes = &wbytes;
	read_flag = true;
        datalock.Unlock_Mutex();

        return Wait_Untill_Read( timeout );   */
        return false;
}

/*-------------------------------------------------------------------------*/

void
CTCPServerConnection::CheckRecieveBuffer( void )
{GUCEF_TRACE;
                                 
        /*
         *      Since this is a non-blocking socket we need to poll for received data
         */
        int bytesrecv;
        UInt16 totalrecieved( 0 );
        int errorcode;
        UInt32 readblocksize;
        m_maxreadbytes ? readblocksize = m_maxreadbytes : readblocksize = 1024;
        do
        {                 
                m_readbuffer.SetDataSize( m_readbuffer.GetDataSize()+readblocksize );
                bytesrecv = WSTS_recv( _data->sockid                                                 , 
                                       static_cast<char*>(m_readbuffer.GetBufferPtr())+totalrecieved ,
                                       readblocksize                                                 ,
                                       0                                                             ,
                                       &errorcode                                                    );
                                       
                if ( (  0 == totalrecieved ) &&
                     (  0 == bytesrecv     )  )
                {
                        /*
                         *      we arrived here because the read flag was set, however no data is available
                         *      This means that the client closed the connection
                         */
                        closesocket( _data->sockid ); 
                        _active = false;
                        
                        NotifyObservers( DisconnectedEvent );
                        
                        m_parentsock->OnClientConnectionClosed( this            ,
                                                                m_connectionidx ,
                                                                true            );                         
                        return; 
                }                     
                totalrecieved += bytesrecv;
                m_readbuffer.SetDataSize( totalrecieved );
                
                if ( m_maxreadbytes )
                {
                        if ( m_maxreadbytes <= totalrecieved )
                        {
                                break;
                        }
                }
        }
        while ( bytesrecv == readblocksize );
        
        if ( totalrecieved > 0 )
        {
                UInt16 keepbytes(0);
                
                TDataRecievedEventData eData( &m_readbuffer );
                NotifyObservers( DataRecievedEvent, &eData );
        }                              
}

/*-------------------------------------------------------------------------*/

void 
CTCPServerConnection::Update( void )
{GUCEF_TRACE;

        if ( !_blocking && _active )
        {       
                fd_set readfds;      /* Setup the read variable for the select function */        
                fd_set exceptfds;    /* Setup the except variable for the select function */

                FD_ZERO( &readfds );
                FD_ZERO( &exceptfds );
        
                _datalock.Lock();
                
                FD_SET( _data->sockid, &readfds );
                FD_SET( _data->sockid, &exceptfds );                
                
                int errorcode = 0;
                if ( select( _data->sockid+1   , 
                             &readfds          , 
                             NULL              , // We don't care about socket writes here
                             &exceptfds        , 
                             &_data->timeout   ) != SOCKET_ERROR ) 
                {
                        /* something happened on the socket */
                        
                        if ( FD_ISSET( _data->sockid, &exceptfds ) )
                        {
                                TSocketErrorEventData eData( errorcode );
                                NotifyObservers( SocketErrorEvent, &eData );
                                
                                Close();
                                _datalock.Unlock();
                                return;                                                                   
                        }
                        else
                        if ( FD_ISSET( _data->sockid, &readfds ) )
                        {
                                /* data can be read from the socket */
                                CheckRecieveBuffer();
                        }                                                
                }
                else
                {
                        /* select call failed */
                        TSocketErrorEventData eData( errorcode );
                        NotifyObservers( SocketErrorEvent, &eData );
                }
                _datalock.Unlock(); 
        }               
}

/*-------------------------------------------------------------------------*/

bool 
CTCPServerConnection::IsActive( void ) const
{GUCEF_TRACE;

        return _active;
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace COMCORE */
}; /* namespace GUCEF */

/*-------------------------------------------------------------------------*/