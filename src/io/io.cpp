#include "io.hpp"

namespace io {
	int Open(lua_State* L) {
		lua::L = L;
		lua::io = LUA->GetNewTable();

		lua::table::RegisterAll();

		LUA->SetGlobal("io", lua::io);

		return 0;
	}
	int Close(lua_State* L) {
		return 0;
	}
}