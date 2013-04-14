/*
 * plasma_atomic - portable macros for processor-specific atomic operations
 *
 *   inline assembly and compiler intrinsics for atomic operations
 *
 *
 * Copyright (c) 2012, Glue Logic LLC. All rights reserved. code()gluelogic.com
 *
 *  This file is part of mcdb.
 *
 *  mcdb is free software: you can redistribute it and/or modify it under
 *  the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 2.1 of the License, or
 *  (at your option) any later version.
 *
 *  mcdb is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with mcdb.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "plasma_atomic.h"

/* inlined functions defined in header
 * (generate external linkage definition in GCC versions earlier than GCC 4.3)
 * (disable C99INLINE and re-include header to generate external linkage) */
#if defined(NO_C99INLINE)||(defined(__GNUC__) && !defined(__GNUC_STDC_INLINE__))
#undef  NO_C99INLINE
#undef  C99INLINE
#define C99INLINE
#undef INCLUDED_PLASMA_ATOMIC_H
#include "plasma_atomic.h"
#endif

/* inlined functions defined in header
 * (generate external linkage definition in C99-compliant compilers)
 * (need to -duplicate- definition from header for non-C99-compliant compiler)
 */
#if !defined(__GNUC__) || defined(__GNUC_STDC_INLINE__)
extern inline
bool
plasma_atomic_CAS_ptr (void ** const restrict ptr,
                       void * restrict cmpval, void * const restrict newval);
bool
plasma_atomic_CAS_ptr (void ** const restrict ptr,
                       void * restrict cmpval, void * const restrict newval);

extern inline
bool
plasma_atomic_CAS_64 (uint64_t * const restrict ptr,
                      uint64_t cmpval, const uint64_t newval);
bool
plasma_atomic_CAS_64 (uint64_t * const restrict ptr,
                      uint64_t cmpval, const uint64_t newval);

extern inline
bool
plasma_atomic_CAS_32 (uint32_t * const restrict ptr,
                      uint32_t cmpval, const uint32_t newval);
bool
plasma_atomic_CAS_32 (uint32_t * const restrict ptr,
                      uint32_t cmpval, const uint32_t newval);
#endif


/* mutex-based fallback implementation, enabled by preprocessor define */
#if defined(PLASMA_ATOMIC_MUTEX_FALLBACK)

#include <pthread.h>
static pthread_mutex_t plasma_atomic_global_mutex = PTHREAD_MUTEX_INITIALIZER;

bool
plasma_atomic_CAS_64_impl (uint64_t * const ptr,
                           uint64_t cmpval, const uint64_t newval)
{
    bool result;
    pthread_mutex_lock(&plasma_atomic_global_mutex);
    if ((result = (*ptr == cmpval)))
        *ptr = newval;
    pthread_mutex_unlock(&plasma_atomic_global_mutex);
    return result;
}

bool
plasma_atomic_CAS_32_impl (uint32_t * const ptr,
                           uint32_t cmpval, const uint32_t newval)
{
    bool result;
    pthread_mutex_lock(&plasma_atomic_global_mutex);
    if ((result = (*ptr == cmpval)))
        *ptr = newval;
    pthread_mutex_unlock(&plasma_atomic_global_mutex);
    return result;
}

#endif   /* PLASMA_ATOMIC_MUTEX_FALLBACK */
