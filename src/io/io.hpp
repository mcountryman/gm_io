#ifndef _IO
#define _IO

// stl
	#include <map>
	#include <string>
// Garry's Mod
	#include "ILuaModuleManager.h"
// Bootil
	#include "Bootil/Bootil.h"
// io
	#include "lua/lua.hpp"

namespace io {
	int Open(lua_State*);
	int Close(lua_State*);
}

#endif//_IO