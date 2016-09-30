// cyCodeBase by Cem Yuksel
// [www.cemyuksel.com]
//-------------------------------------------------------------------------------
/// \file		cyMath.h 
/// \author		Cem Yuksel
/// \brief		Base class for math functions
//-------------------------------------------------------------------------------
//
// Copyright (c) 2016, Cem Yuksel <cem@cemyuksel.com>
// All rights reserved.
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy 
// of this software and associated documentation files (the "Software"), to deal 
// in the Software without restriction, including without limitation the rights 
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell 
// copies of the Software, and to permit persons to whom the Software is 
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all 
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE 
// SOFTWARE.
// 
//-------------------------------------------------------------------------------

#ifndef _CY_MATH_H_INCLUDED_
#define _CY_MATH_H_INCLUDED_

//-------------------------------------------------------------------------------

#ifndef _CY_CORE_MEMCPY_LIMIT
#define _CY_CORE_MEMCPY_LIMIT 256
#endif

//-------------------------------------------------------------------------------

#include <math.h>
#include <string.h>
#include <stdint.h>

//-------------------------------------------------------------------------------
namespace cy {
//-------------------------------------------------------------------------------

/// Base class for math functions with different types
template<typename TYPE> inline TYPE cySin ( TYPE a ) { return (TYPE) ::sin (a); }
template<typename TYPE> inline TYPE cyCos ( TYPE a ) { return (TYPE) ::cos (a); }
template<typename TYPE> inline TYPE cyTan ( TYPE a ) { return (TYPE) ::tan (a); }
template<typename TYPE> inline TYPE cyAbs ( TYPE a ) { return (TYPE) ::abs (a); }
template<typename TYPE> inline TYPE cySqrt( TYPE a ) { return (TYPE) ::sqrt(a); }

template<> inline float cySin <float>( float a ) { return ::sinf (a); }
template<> inline float cyCos <float>( float a ) { return ::cosf (a); }
template<> inline float cyTan <float>( float a ) { return ::tanf (a); }
template<> inline float cyAbs <float>( float a ) { return ::fabsf(a); }
template<> inline float cySqrt<float>( float a ) { return ::sqrtf(a); }

template<> inline double cyAbs ( double a ) { return ::fabs(a); }

//-------------------------------------------------------------------------------

#define CY_MEMCOPY(type,dest,source,n) \
	if ( !std::is_pod<type>() || (n)*sizeof(type) < _CY_CORE_MEMCPY_LIMIT ) { \
		for ( int i=0; i<n; i++ ) (dest)[i] = (source)[i]; \
	} else { \
		memcpy( dest, source, (n)*sizeof(type) ); \
	}

#define CY_MEMCONVERT(type,dest,source,n) { for ( int i=0; i<n; i++ ) (dest)[i] = type((source)[i]); }

#define CY_MEMCLEAR(type,dest,n) memset(dest,0,(n)*sizeof(type))

//-------------------------------------------------------------------------------

#ifndef _CY_IVDEP
# ifdef _MSC_VER
#  define _CY_IVDEP loop( ivdep )
# elif defined __GNUC__
#  define _CY_IVDEP GLL ivdep
# else
#  define _CY_IVDEP ivdep
# endif
#endif

//-------------------------------------------------------------------------------
} // namespace cy
//-------------------------------------------------------------------------------

#endif

