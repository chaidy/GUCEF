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
 
#ifndef GUCEF_CORE_CVALUELIST_H
#define GUCEF_CORE_CVALUELIST_H

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#include <map>
#include <vector>

#ifndef GUCEF_CORE_EXCEPTIONMACROS_H
#include "ExceptionMacros.h"
#define GUCEF_CORE_EXCEPTIONMACROS_H
#endif /* GUCEF_CORE_EXCEPTIONMACROS_H ? */

#ifndef GUCEF_CORE_CDVSTRING_H
#include "CDVString.h"
#define GUCEF_CORE_CDVSTRING_H
#endif /* GUCEF_CORE_CDVSTRING_H ? */

#ifndef GUCEF_CORE_MACROS_H
#include "gucefCORE_macros.h"     /* often used gucef macros */
#define GUCEF_CORE_MACROS_H
#endif /* GUCEF_CORE_MACROS_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCEF {
namespace CORE {

/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/

class GUCEFCORE_EXPORT_CPP CValueList
{
    public:
    
    typedef std::vector< CString > TStringVector;
    
    CValueList( void );
    
    CValueList( const CValueList& src );
    
    CValueList& operator=( const CValueList& src );        
    
    virtual ~CValueList();
    
    /**
     *  Returns the first value associated with the
     *  given key.
     *
     *  @exception EUnknownKey thrown if the given key is unknown
     */
    CString& operator[]( const CString& key );
           
    /**
     *  Returns the first value associated with the
     *  given key.
     *
     *  @exception EUnknownKey thrown if the given key is unknown
     */
    const CString& operator[]( const CString& key ) const;
    
    void SetMultiple( const CString& keyandvalue ,
                      const char seperator       );
    
    void Set( const CString& keyAndValue );
    
    void Set( const CString& key   ,
              const CString& value );
    
    /**
     *  Returns the first value associated with the
     *  given key.
     *
     *  @exception EUnknownKey thrown if the given key is unknown
     */
    CString& GetValue( const CString& key );

    /**
     *  Returns the first value associated with the
     *  given key.
     *
     *  @exception EUnknownKey thrown if the given key is unknown
     */
    const CString& GetValue( const CString& key ) const;
    
    /**
     *  Returns the first value associated with the
     *  given key. This GetValue version differs from the others in
     *  that no exception will be thrown if the key does not exist
     *  instead it will return an empty string.
     */
    CString GetValueAlways( const CString& key ) const;

    /**
     *  Returns the first value associated with the
     *  given key index.
     *
     *  @exception EIndexOutOfRange thrown if the given key index is invalid
     */
    CString& GetValue( const UInt32 index );
    
    /**
     *  Returns the first value associated with the
     *  given key index.
     *
     *  @exception EIndexOutOfRange thrown if the given key index is invalid
     */
    const CString& GetValue( const UInt32 index ) const;
    
    /**
     *  Returns the value vector associated with the
     *  given key.
     *
     *  @exception EUnknownKey thrown if the given key is unknown
     */
    TStringVector& GetValueVector( const CString& key );
    
    /**
     *  Returns the value vector associated with the
     *  given key.
     *
     *  @exception EUnknownKey thrown if the given key is unknown
     */
    const TStringVector& GetValueVector( const CString& key ) const;

    CString GetPair( const CString& key ) const;
    
    CString GetPair( const UInt32 index ) const;

    /**
     *  Returns the key associated with the given index.
     *
     *  @exception EIndexOutOfRange thrown if the given key index is invalid
     */
    const CString& GetKey( const UInt32 index ) const;                
    
    bool HasKey( const CString& key ) const;
    
    void Delete( const CString& key );
    
    void DeleteAll( void );
    
    UInt32 GetCount( void ) const;
    
    void SetAllowDuplicates( const bool allowDuplicates );
    
    bool GetAllowDuplicates( void ) const;
    
    void SetAllowMultipleValues( const bool allowMultipleValues );
    
    bool GetAllowMultipleValues( void ) const;
    
    GUCEF_DEFINE_MSGEXCEPTION( GUCEFCORE_EXPORT_CPP, EUnknownKey );    
    GUCEF_DEFINE_MSGEXCEPTION( GUCEFCORE_EXPORT_CPP, EIndexOutOfRange );
    
    private:                       
    
    typedef std::map< CString, TStringVector > TValueMap;
            
    TValueMap m_list;
    bool m_allowDuplicates;
    bool m_allowMultipleValues;
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace CORE */
}; /* namespace GUCEF */

/*-------------------------------------------------------------------------*/

#endif /* GUCEF_CORE_CVALUELIST_H */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 18-08-2007 :
        - Updated to use STL containers and added the ability to map multiple
          values to a single key.
        - Instead of empty strings an exception will now be thrown if an invalid
          key name or index is used to access an entry.  
- 21-09-2005 :
        - initial version

--------------------------------------------------------------------------*/