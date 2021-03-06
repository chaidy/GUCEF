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

#ifndef GUCEF_CORE_CTABSTRACTFACTORYWITHPARAM_H
#define GUCEF_CORE_CTABSTRACTFACTORYWITHPARAM_H

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#include <map>
#include "CTFactoryWithParam.h"
#include "CTFactoryBaseWithParam.h"
#include "CMsgException.h"

#ifndef GUCEF_CORE_LOGGING_H
#include "gucefCORE_Logging.h"
#define GUCEF_CORE_LOGGING_H
#endif /* GUCEF_CORE_LOGGING_H */

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCEF {
namespace CORE {

/*-------------------------------------------------------------------------//
//                                                                         //
//      TEMPLATES                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

/**
 *  Abstract factory template for the selection and utilization of concrete
 *  factories based on a criteria.
 *
 *  Note that when using this template it is mandatory for BaseClassType
 *  classes to define the following member function:
 *      SelectionCriteriaType GetType( void ) const;
 *
 */
template< typename SelectionCriteriaType, class BaseClassType, typename ConstructionParamType >
class CTAbstractFactoryWithParam
{
    public:
    typedef CTFactoryBaseWithParam< BaseClassType, ConstructionParamType > TConcreteFactory;

    explicit CTAbstractFactoryWithParam( const bool assumeFactoryOwnership = false );

    CTAbstractFactoryWithParam( const CTAbstractFactoryWithParam& src );

    virtual ~CTAbstractFactoryWithParam();

    CTAbstractFactoryWithParam& operator=( const CTAbstractFactoryWithParam& src );

    /**
     *  Constructs the concrete factory product
     *
     *  @return pointer to the base class of the constructed factory product
     */
    BaseClassType* Create( const SelectionCriteriaType& selectedType ,
                           const ConstructionParamType& param        );

    /**
     *  Destroys the concrete factory product
     *
     *  @param factoryProduct pointer to the base class of the constructed factory product
     */
    void Destroy( BaseClassType* factoryProduct );

    void RegisterConcreteFactory( const SelectionCriteriaType& selectedType ,
                                  TConcreteFactory* concreteFactory         );

    void UnregisterConcreteFactory( const SelectionCriteriaType& selectedType );

    bool IsConstructible( const SelectionCriteriaType& selectedType ) const;

    private:
    typedef std::map< SelectionCriteriaType, TConcreteFactory* >  TFactoryList;

    TFactoryList m_concreteFactoryList;
    bool m_assumeFactoryOwnership;
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      UTILITIES                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

template< typename SelectionCriteriaType, class BaseClassType, typename ConstructionParamType >
CTAbstractFactoryWithParam< SelectionCriteriaType, BaseClassType, ConstructionParamType >::CTAbstractFactoryWithParam( const bool assumeFactoryOwnership /* = false */ )
    : m_assumeFactoryOwnership( assumeFactoryOwnership )
{GUCEF_TRACE;

}

/*-------------------------------------------------------------------------*/

template< typename SelectionCriteriaType, class BaseClassType, typename ConstructionParamType >
CTAbstractFactoryWithParam< SelectionCriteriaType, BaseClassType, ConstructionParamType >::CTAbstractFactoryWithParam( const CTAbstractFactoryWithParam< SelectionCriteriaType, BaseClassType, ConstructionParamType >& /* src */ )
{GUCEF_TRACE;

}

/*-------------------------------------------------------------------------*/

template< typename SelectionCriteriaType, class BaseClassType, typename ConstructionParamType >
CTAbstractFactoryWithParam< SelectionCriteriaType, BaseClassType, ConstructionParamType >::~CTAbstractFactoryWithParam()
{GUCEF_TRACE;

}

/*-------------------------------------------------------------------------*/

template< typename SelectionCriteriaType, class BaseClassType, typename ConstructionParamType >
CTAbstractFactoryWithParam< SelectionCriteriaType, BaseClassType, ConstructionParamType >&
CTAbstractFactoryWithParam< SelectionCriteriaType, BaseClassType, ConstructionParamType >::operator=( const CTAbstractFactoryWithParam< SelectionCriteriaType, BaseClassType, ConstructionParamType >& /* src */ )
{GUCEF_TRACE;

    return *this;
}

/*-------------------------------------------------------------------------*/

template< typename SelectionCriteriaType, class BaseClassType, typename ConstructionParamType >
BaseClassType*
CTAbstractFactoryWithParam< SelectionCriteriaType, BaseClassType, ConstructionParamType >::Create( const SelectionCriteriaType& selectedType ,
																                                   const ConstructionParamType& param        )
{GUCEF_TRACE;

    typename TFactoryList::iterator i( m_concreteFactoryList.find( selectedType ) );
    if ( i != m_concreteFactoryList.end() )
    {
        return (*i).second->Create( param );
    }
    return NULL;
}

/*-------------------------------------------------------------------------*/

template< typename SelectionCriteriaType, class BaseClassType, typename ConstructionParamType >
void
CTAbstractFactoryWithParam< SelectionCriteriaType, BaseClassType, ConstructionParamType >::Destroy( BaseClassType* factoryProduct )
{GUCEF_TRACE;

    typename TFactoryList::iterator i( m_concreteFactoryList.find( factoryProduct->GetType() ) );
    if ( i != m_concreteFactoryList.end() )
    {
        (*i).second->Destroy( factoryProduct );
        return;
    }
    throw CMsgException( __FILE__, __LINE__, "CTAbstractFactory: Cannot find concrete factory capable of destroying the given product" );
}

/*-------------------------------------------------------------------------*/

template< typename SelectionCriteriaType, class BaseClassType, typename ConstructionParamType >
bool
CTAbstractFactoryWithParam< SelectionCriteriaType, BaseClassType, ConstructionParamType >::IsConstructible( const SelectionCriteriaType& selectedType ) const
{GUCEF_TRACE;

    return m_concreteFactoryList.find( selectedType ) != m_concreteFactoryList.end();
}

/*-------------------------------------------------------------------------*/

template< typename SelectionCriteriaType, class BaseClassType, typename ConstructionParamType >
void
CTAbstractFactoryWithParam< SelectionCriteriaType, BaseClassType, ConstructionParamType >::RegisterConcreteFactory( const SelectionCriteriaType& selectedType ,
                                                                                                                    TConcreteFactory* concreteFactory         )
{GUCEF_TRACE;

    m_concreteFactoryList[ selectedType ] = concreteFactory;
}

/*-------------------------------------------------------------------------*/

template< typename SelectionCriteriaType, class BaseClassType, typename ConstructionParamType >
void
CTAbstractFactoryWithParam< SelectionCriteriaType, BaseClassType, ConstructionParamType >::UnregisterConcreteFactory( const SelectionCriteriaType& selectedType )
{GUCEF_TRACE;

    typename TFactoryList::iterator i = m_concreteFactoryList.find( selectedType );
    if ( i != m_concreteFactoryList.end() )
    {
        if ( m_assumeFactoryOwnership )
        {
            delete (*i).second;
        }
        m_concreteFactoryList.erase( i );
    }
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace CORE */
}; /* namespace GUCEF */

/*-------------------------------------------------------------------------*/

#endif /* GUCEF_CORE_CTABSTRACTFACTORYWITHPARAM_H ? */
