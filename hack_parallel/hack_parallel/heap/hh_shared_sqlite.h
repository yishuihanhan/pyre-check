/**
 * Copyright (c) 2015, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the "hack" directory of this source tree.
 *
 */

#ifndef HH_SHARED_SQLITE_H
#define HH_SHARED_SQLITE_H

#ifdef _WIN32
#include <windows.h>
#else
#include <stdint.h>
#endif

#ifndef NO_SQLITE3
#include <sqlite3.h>
#endif


#ifndef NO_SQLITE3
typedef sqlite3 *sqlite3_ptr;
#else
typedef void *sqlite3_ptr;
#endif

#ifndef NO_SQLITE3
#define assert_sql(x, y) (assert_sql_with_line((x), (y), __LINE__))
#endif


void assert_sql_with_line(
  int result,
  int correct_result,
  int line_number);

#ifndef NO_SQLITE3
void make_all_tables(sqlite3 *db);

void hhfi_insert_row(
  sqlite3_ptr db,
  int64_t hash,
  const char *name,
  int64_t kind,
  const char *filespec
);
#endif

char *hhfi_get_filespec(
  sqlite3_ptr db,
  int64_t hash
);

void hhfi_init_db(const char *path);
void hhfi_free_db(void);
sqlite3_ptr hhfi_get_db(void);
#endif
