#include <stdio.h>
#include <string.h>

#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

#include "Shlwapi.h"


static int l_isdir (lua_State *L) {
	const char *path = luaL_checkstring(L, 1);
	lua_pushboolean(L, PathIsDirectory(path) == FILE_ATTRIBUTE_DIRECTORY);
	return 1;
}

static int l_exists (lua_State *L) {
	const char *path = luaL_checkstring(L, 1);
	lua_pushboolean(L, PathFileExists(path));
	return 1;
}

static const struct luaL_Reg sfs_lib [] = {
	{"is_dir", l_isdir},
	{"exists", l_exists},
	{NULL, NULL}
};

int __declspec(dllexport) luaopen_sfs (lua_State *L) {
	luaL_newlib(L, sfs_lib);
	return 1;
}
