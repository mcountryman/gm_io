#include "directory.hpp"

namespace io {
	namespace lua {
		int directory::Exists(lua_State* L) {
			Lua()->CheckType(1, GarrysMod::Lua::Type::STRING);

			const char* path = Lua()->GetString(1);

			Lua()->Push(Bootil::File::IsFolder(path));

			return 1;
		}
		int directory::Create(lua_State* L) {
			Lua()->CheckType(1, GarrysMod::Lua::Type::STRING);

			const char* path = Lua()->GetString(1);
			bool recursive = false;

			if(Lua()->GetType(2) == GarrysMod::Lua::Type::BOOL)
				recursive = Lua()->GetBool(2);

			Lua()->Push(Bootil::File::CreateFolder(path, recursive));

			return 1;
		}
		int directory::Remove(lua_State* L) {
			Lua()->CheckType(1, GarrysMod::Lua::Type::STRING);

			const char* path = Lua()->GetString(1);
			bool recursive = false;

			if(Lua()->GetType(2) == GarrysMod::Lua::Type::BOOL)
				recursive = Lua()->GetBool(2);

			Lua()->Push(Bootil::File::RemoveFolder(path, recursive));

			return 1;
		}
	}
}