/** @file kdb.h
 *
 * @brief Klish db
 */

#ifndef _klish_kdb_h
#define _klish_kdb_h

#include <stdint.h>

// Current API version
#define KDB_MAJOR 1
#define KDB_MINOR 0

// Shared object filename template. Insert db ID or db "name" field
// instead "%s". Consider db ID as an "internal native name". The "name"
// field can differ from ID and it's just used within scheme to refer db.
// Consider it as alias of ID.
#define KDB_SONAME_FMT "libkdb_%s.so"

// db's API version symbols
#define KDB_MAJOR_FMT "kdb_%s_major"
#define KDB_MINOR_FMT "kdb_%s_minor"

// db's init and fini functions
#define KDB_INIT_FMT "kdb_%s_init"
#define KDB_FINI_FMT "kdb_%s_fini"

// db's load and deploy functions
#define KDB_INIT_FMT "kdb_%s_load_scheme"
#define KDB_FINI_FMT "kdb_%s_deploy_scheme"


typedef struct kdb_s kdb_t;


C_DECL_BEGIN

kdb_t *kdb_new(const char *name, const char *sofile);
void kdb_free(kdb_t *db);

const char *kdb_name(const kdb_t *db);
const char *kdb_sofile(const kdb_t *db);
const char *kdb_options(const kdb_t *db);
bool_t kdb_set_options(kdb_t *db, const char *options);

C_DECL_END

#endif // _klish_kdb_h