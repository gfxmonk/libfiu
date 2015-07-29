
#ifndef _HASH_H
#define _HASH_H

/* Generic hash table. See hash.c for more information. */

#include <sys/types.h>		/* for size_t */
#include <stdint.h>		/* for int64_t */

typedef struct fiu_hash fiu_hash_t;

fiu_hash_t *fiu_hash_create(void (*destructor)(void *));
void fiu_hash_free(fiu_hash_t *h);

void *fiu_hash_get(fiu_hash_t *h, const char *key);
bool fiu_hash_set(fiu_hash_t *h, const char *key, void *value);
bool fiu_hash_del(fiu_hash_t *h, const char *key);


/* Generic cache. */

typedef struct fiu_cache fiu_cache_t;

fiu_cache_t *fiu_cache_create();
bool fiu_cache_resize(struct fiu_cache *c, size_t new_size);
void fiu_cache_free(fiu_cache_t *c);

bool fiu_cache_get(fiu_cache_t *c, const char *key, void **value);
bool fiu_cache_set(fiu_cache_t *c, const char *key, void *value);
bool fiu_cache_del(fiu_cache_t *c, const char *key);
bool fiu_cache_invalidate(fiu_cache_t *c);

#endif

