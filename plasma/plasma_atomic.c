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

#define PLASMA_ATOMIC_C99INLINE_FUNCS

/* inlined functions defined in header
 * (generate external linkage definition in GCC versions earlier than GCC 4.3)*/
#if defined(NO_C99INLINE) \
 || defined(__clang__) || (defined(__GNUC__) && !defined(__GNUC_STDC_INLINE__))
#define PLASMA_ATOMIC_C99INLINE
#endif

#include "plasma_atomic.h"

/* inlined functions defined in header
 * (generate external linkage definition in C99-compliant compilers)
 * (need to -duplicate- definition from header for non-C99-compliant compilers)
 */
#if !defined(__GNUC__) || defined(__GNUC_STDC_INLINE__)
#ifdef __clang__
#undef  __attribute_regparm__
#define __attribute_regparm__(x)
#endif
__attribute_regparm__((3))
extern inline
bool
plasma_atomic_CAS_ptr (void ** const restrict ptr,
                       void * restrict cmpval, void * const restrict newval);
__attribute_regparm__((3))
bool
plasma_atomic_CAS_ptr (void ** const restrict ptr,
                       void * restrict cmpval, void * const restrict newval);

#ifndef plasma_atomic_not_implemented_64
__attribute_regparm__((3))
extern inline
bool
plasma_atomic_CAS_64 (uint64_t * const restrict ptr,
                      uint64_t cmpval, const uint64_t newval);
__attribute_regparm__((3))
bool
plasma_atomic_CAS_64 (uint64_t * const restrict ptr,
                      uint64_t cmpval, const uint64_t newval);
#endif

__attribute_regparm__((3))
extern inline
bool
plasma_atomic_CAS_32 (uint32_t * const restrict ptr,
                      uint32_t cmpval, const uint32_t newval);
__attribute_regparm__((3))
bool
plasma_atomic_CAS_32 (uint32_t * const restrict ptr,
                      uint32_t cmpval, const uint32_t newval);

__attribute_regparm__((1))
extern inline
void
plasma_atomic_lock_release (uint32_t * const ptr);
__attribute_regparm__((1))
void
plasma_atomic_lock_release (uint32_t * const ptr);

__attribute_regparm__((1))
extern inline
bool
plasma_atomic_lock_acquire (uint32_t * const ptr);
__attribute_regparm__((1))
bool
plasma_atomic_lock_acquire (uint32_t * const ptr);

#ifdef plasma_atomic_load_explicit_szof

#ifndef plasma_atomic_not_implemented_64
__attribute_regparm__((3))
extern inline
uint64_t
plasma_atomic_load_64_impl(const void * const restrict ptr,
                           const enum memory_order order,
                           const size_t bytes);
__attribute_regparm__((3))
uint64_t
plasma_atomic_load_64_impl(const void * const restrict ptr,
                           const enum memory_order order,
                           const size_t bytes);
#endif

__attribute_regparm__((3))
extern inline
uint32_t
plasma_atomic_load_32_impl(const void * const restrict ptr,
                           const enum memory_order order,
                           const size_t bytes);
__attribute_regparm__((3))
uint32_t
plasma_atomic_load_32_impl(const void * const restrict ptr,
                           const enum memory_order order,
                           const size_t bytes);

#endif /* plasma_atomic_load_explicit_szof */

#ifndef plasma_atomic_fetch_add_u32_impl
__attribute_regparm__((2))
extern inline
void *
plasma_atomic_fetch_add_ptr (void * const ptr, ptrdiff_t addval);
__attribute_regparm__((2))
void *
plasma_atomic_fetch_add_ptr (void * const ptr, ptrdiff_t addval);
#endif

#ifdef plasma_atomic_fetch_add_u64_implreturn
__attribute_regparm__((2))
extern inline
uint64_t
plasma_atomic_fetch_add_u64 (uint64_t * const ptr, uint64_t addval);
__attribute_regparm__((2))
uint64_t
plasma_atomic_fetch_add_u64 (uint64_t * const ptr, uint64_t addval);
#endif

#ifdef plasma_atomic_fetch_add_u32_implreturn
__attribute_regparm__((2))
extern inline
uint32_t
plasma_atomic_fetch_add_u32 (uint32_t * const ptr, uint32_t addval);
__attribute_regparm__((2))
uint32_t
plasma_atomic_fetch_add_u32 (uint32_t * const ptr, uint32_t addval);
#endif

#ifndef plasma_atomic_fetch_or_u32_impl
__attribute_regparm__((2))
extern inline
void *
plasma_atomic_fetch_or_ptr (void * const ptr, uintptr_t orval);
__attribute_regparm__((2))
void *
plasma_atomic_fetch_or_ptr (void * const ptr, uintptr_t orval);
#endif

#ifdef plasma_atomic_fetch_or_u64_implreturn
__attribute_regparm__((2))
extern inline
uint64_t
plasma_atomic_fetch_or_u64 (uint64_t * const ptr, uint64_t orval);
__attribute_regparm__((2))
uint64_t
plasma_atomic_fetch_or_u64 (uint64_t * const ptr, uint64_t orval);
#endif

#ifdef plasma_atomic_fetch_or_u32_implreturn
__attribute_regparm__((2))
extern inline
uint32_t
plasma_atomic_fetch_or_u32 (uint32_t * const ptr, uint32_t orval);
__attribute_regparm__((2))
uint32_t
plasma_atomic_fetch_or_u32 (uint32_t * const ptr, uint32_t orval);
#endif

#ifndef plasma_atomic_fetch_xor_u32_impl
__attribute_regparm__((2))
extern inline
void *
plasma_atomic_fetch_xor_ptr (void * const ptr, uintptr_t xorval);
__attribute_regparm__((2))
void *
plasma_atomic_fetch_xor_ptr (void * const ptr, uintptr_t xorval);
#endif

#ifdef plasma_atomic_fetch_xor_u64_implreturn
__attribute_regparm__((2))
extern inline
uint64_t
plasma_atomic_fetch_xor_u64 (uint64_t * const ptr, uint64_t xorval);
__attribute_regparm__((2))
uint64_t
plasma_atomic_fetch_xor_u64 (uint64_t * const ptr, uint64_t xorval);
#endif

#ifdef plasma_atomic_fetch_xor_u32_implreturn
__attribute_regparm__((2))
extern inline
uint32_t
plasma_atomic_fetch_xor_u32 (uint32_t * const ptr, uint32_t xorval);
__attribute_regparm__((2))
uint32_t
plasma_atomic_fetch_xor_u32 (uint32_t * const ptr, uint32_t xorval);
#endif

#ifndef plasma_atomic_fetch_and_u32_impl
__attribute_regparm__((2))
extern inline
void *
plasma_atomic_fetch_and_ptr (void * const ptr, uintptr_t andval);
__attribute_regparm__((2))
void *
plasma_atomic_fetch_and_ptr (void * const ptr, uintptr_t andval);
#endif

#ifdef plasma_atomic_fetch_and_u64_implreturn
__attribute_regparm__((2))
extern inline
uint64_t
plasma_atomic_fetch_and_u64 (uint64_t * const ptr, uint64_t andval);
__attribute_regparm__((2))
uint64_t
plasma_atomic_fetch_and_u64 (uint64_t * const ptr, uint64_t andval);
#endif

#ifdef plasma_atomic_fetch_and_u32_implreturn
__attribute_regparm__((2))
extern inline
uint32_t
plasma_atomic_fetch_and_u32 (uint32_t * const ptr, uint32_t andval);
__attribute_regparm__((2))
uint32_t
plasma_atomic_fetch_and_u32 (uint32_t * const ptr, uint32_t andval);
#endif

#endif /* !defined(__GNUC__) || defined(__GNUC_STDC_INLINE__) */


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
