/*
 * KubOS Core Flight Services
 * Copyright (C) 2016 Kubos Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "kubos-core/k_alloc_malloc.h"
#include <stdlib.h>

void * malloc_new(size_t size)
{
    return malloc(size);
}

void malloc_free(void * ptr)
{
    if (NULL != ptr)
        free(ptr);
}

void * malloc_realloc(void * buff, size_t old_size, size_t new_size)
{
#ifdef TARGET_LIKE_MSP430
    #warning msp430 needs a realloc implementation
#else
    return realloc(buff, new_size);
#endif
}

void k_alloc_malloc_init()
{
    malloc_alloc._new = malloc_new;
    malloc_alloc._free = malloc_free;
    malloc_alloc._realloc = malloc_realloc;
}
