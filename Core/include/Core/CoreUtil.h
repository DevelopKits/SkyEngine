#pragma once

#include <string>
#include <assert.h>
#include "boost/smart_ptr.hpp"

#define CORE_NEW(x) ( new x )
#define CORE_DELETE(x) { if(x) delete x; x = 0; }
#define UNUSED(x) (void)x

template <typename To, typename From>
inline To check_cast( From p ){
	assert( dynamic_cast<To>(p) == static_cast<To>(p) );
	return static_cast<To>(p);
}

SKYENGINE_CORE_API std::wstring& Convert( std::wstring & strDest, std::string const & strSrc );

template< typename T >
inline boost::shared_ptr<T> MakeSharedPtr()
{
	return boost::shared_ptr<T>( new T, boost::checked_deleter<T>() );
}

template <typename T, typename A1> 
inline boost::shared_ptr<T> MakeSharedPtr(A1 const & a1)
{
    return boost::shared_ptr<T>(new T(a1), boost::checked_deleter<T>());
}

template <typename T, typename A1> 
inline boost::shared_ptr<T> MakeSharedPtr(A1& a1) 
{   
    return boost::shared_ptr<T>(new T(a1), boost::checked_deleter<T>());
}   

template <typename T, typename A1, typename A2> 
inline boost::shared_ptr<T> MakeSharedPtr(A1 const & a1, A2 const & a2) 
{   
    return boost::shared_ptr<T>(new T(a1, a2), boost::checked_deleter<T>());
}   

template <typename T, typename A1, typename A2> 
inline boost::shared_ptr<T> MakeSharedPtr(A1& a1, A2& a2) 
{   
    return boost::shared_ptr<T>(new T(a1, a2), boost::checked_deleter<T>());
}   

template <typename T, typename A1, typename A2, typename A3> 
inline boost::shared_ptr<T> MakeSharedPtr(A1 const & a1, A2 const & a2, A3 const & a3) 
{   
    return boost::shared_ptr<T>(new T(a1, a2, a3), boost::checked_deleter<T>());
}   

template <typename T, typename A1, typename A2, typename A3> 
inline boost::shared_ptr<T> MakeSharedPtr(A1& a1, A2& a2, A3& a3) 
{
    return boost::shared_ptr<T>(new T(a1, a2, a3), boost::checked_deleter<T>());
}

template <typename T, typename A1, typename A2, typename A3, typename A4>
inline boost::shared_ptr<T> MakeSharedPtr(A1 const & a1, A2 const & a2, A3 const & a3, A4 const & a4)
{
    return boost::shared_ptr<T>(new T(a1, a2, a3, a4), boost::checked_deleter<T>());
}

template <typename T, typename A1, typename A2, typename A3, typename A4>
inline boost::shared_ptr<T> MakeSharedPtr(A1& a1, A2& a2, A3& a3, A4& a4)
{
    return boost::shared_ptr<T>(new T(a1, a2, a3, a4), boost::checked_deleter<T>());
}

template <typename T, typename A1, typename A2, typename A3, typename A4, typename A5>
inline boost::shared_ptr<T> MakeSharedPtr(A1 const & a1, A2 const & a2, A3 const & a3, A4 const & a4,
    A5 const & a5)
{
    return boost::shared_ptr<T>(new T(a1, a2, a3, a4, a5), boost::checked_deleter<T>());
}

template <typename T, typename A1, typename A2, typename A3, typename A4, typename A5>
inline boost::shared_ptr<T> MakeSharedPtr(A1& a1, A2& a2, A3& a3, A4& a4, A5& a5)
{
    return boost::shared_ptr<T>(new T(a1, a2, a3, a4, a5), boost::checked_deleter<T>());
}

template <typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline boost::shared_ptr<T> MakeSharedPtr(A1 const & a1, A2 const & a2, A3 const & a3, A4 const & a4,
    A5 const & a5, A6 const & a6)
{
    return boost::shared_ptr<T>(new T(a1, a2, a3, a4, a5, a6), boost::checked_deleter<T>());
}

	
template <typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
inline boost::shared_ptr<T> MakeSharedPtr(A1& a1, A2& a2, A3& a3, A4& a4, A5& a5, A6& a6)
{
    return boost::shared_ptr<T>(new T(a1, a2, a3, a4, a5, a6), boost::checked_deleter<T>());
}

template <typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6,
    typename A7>
inline boost::shared_ptr<T> MakeSharedPtr(A1 const & a1, A2 const & a2, A3 const & a3, A4 const & a4,
    A5 const & a5, A6 const & a6, A7 const & a7)
{
    return boost::shared_ptr<T>(new T(a1, a2, a3, a4, a5, a6, a7), boost::checked_deleter<T>());
}

template <typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6,
    typename A7>
inline boost::shared_ptr<T> MakeSharedPtr(A1& a1, A2& a2, A3& a3, A4& a4, A5& a5, A6& a6, A7& a7)
{
    return boost::shared_ptr<T>(new T(a1, a2, a3, a4, a5, a6, a7), boost::checked_deleter<T>());
}

template <typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6,
    typename A7, typename A8>
inline boost::shared_ptr<T> MakeSharedPtr(A1 const & a1, A2 const & a2, A3 const & a3, A4 const & a4,
    A5 const & a5, A6 const & a6, A7 const & a7, A8 const & a8)
{
    return boost::shared_ptr<T>(new T(a1, a2, a3, a4, a5, a6, a7, a8), boost::checked_deleter<T>());
}

template <typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6,
    typename A7, typename A8>
inline boost::shared_ptr<T> MakeSharedPtr(A1& a1, A2& a2, A3& a3, A4& a4, A5& a5, A6& a6, A7& a7,
    A8& a8)
{
    return boost::shared_ptr<T>(new T(a1, a2, a3, a4, a5, a6, a7, a8), boost::checked_deleter<T>());
}

template <typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6,
    typename A7, typename A8, typename A9>
inline boost::shared_ptr<T> MakeSharedPtr(A1 const & a1, A2 const & a2, A3 const & a3, A4 const & a4,
    A5 const & a5, A6 const & a6, A7 const & a7, A8 const & a8, A9 const & a9)
{
    return boost::shared_ptr<T>(new T(a1, a2, a3, a4, a5, a6, a7, a8, a9), boost::checked_deleter<T>());
}

template <typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6,
    typename A7, typename A8, typename A9>
inline boost::shared_ptr<T> MakeSharedPtr(A1& a1, A2& a2, A3& a3, A4& a4, A5& a5, A6& a6, A7& a7,
    A8& a8, A9& a9)
{
    return boost::shared_ptr<T>(new T(a1, a2, a3, a4, a5, a6, a7, a8, a9), boost::checked_deleter<T>());
}

template <typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6,
    typename A7, typename A8, typename A9, typename A10>
inline boost::shared_ptr<T> MakeSharedPtr(A1 const & a1, A2 const & a2, A3 const & a3, A4 const & a4,
    A5 const & a5, A6 const & a6, A7 const & a7, A8 const & a8, A9 const & a9, A10 const & a10)
{
    return boost::shared_ptr<T>(new T(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10), boost::checked_deleter<T>());
}

template <typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6,
    typename A7, typename A8, typename A9, typename A10>
inline boost::shared_ptr<T> MakeSharedPtr(A1& a1, A2& a2, A3& a3, A4& a4, A5& a5, A6& a6, A7& a7,
    A8& a8, A9& a9, A10& a10)
{
    return boost::shared_ptr<T>(new T(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10), boost::checked_deleter<T>());
}