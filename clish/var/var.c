/*
 * var.c
 *
 * This file provides the implementation of the "var" class
 */
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "lub/string.h"
#include "private.h"

/*--------------------------------------------------------- */
static void clish_var_init(clish_var_t *this, const char *name)
{
	this->name = lub_string_dup(name);
	this->dynamic = BOOL_FALSE;
	this->value = NULL;
	this->action = clish_action_new();
	this->saved = NULL;
}

/*--------------------------------------------------------- */
static void clish_var_fini(clish_var_t *this)
{
	lub_string_free(this->name);
	lub_string_free(this->value);
	lub_string_free(this->saved);
	clish_action_delete(this->action);
}

/*--------------------------------------------------------- */
clish_var_t *clish_var_new(const char *name)
{
	clish_var_t *this = malloc(sizeof(clish_var_t));
	if (this)
		clish_var_init(this, name);
	return this;
}

/*--------------------------------------------------------- */
void clish_var_delete(void *data)
{
	clish_var_t *this = (clish_var_t *)data;
	clish_var_fini(this);
	free(this);
}

CLISH_GET_STR(var, name);
CLISH_SET(var, bool_t, dynamic);
CLISH_GET(var, bool_t, dynamic);
CLISH_SET_STR(var, value);
CLISH_GET_STR(var, value);
CLISH_SET_STR(var, saved);
CLISH_GET_STR(var, saved);
CLISH_GET(var, clish_action_t *, action);

/*--------------------------------------------------------- */
int clish_var_compare(const void *first, const void *second)
{
	const clish_var_t *f = (const clish_var_t *)first;
	const clish_var_t *s = (const clish_var_t *)second;
	return lub_string_nocasecmp(f->name, s->name);
}

/*--------------------------------------------------------- */
int clish_var_fn_find_by_name(const void *key, const void *data) {
	const char *name = (const char *)key;
	const clish_var_t *d = (const clish_var_t *)data;
	return lub_string_nocasecmp(name, clish_var__get_name(d));
}
