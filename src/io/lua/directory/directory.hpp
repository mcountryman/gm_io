#ifndef LUA_DIRECTORY_HPP
#define LUA_DIRECTORY_HPP

#include "../lua.hpp"

namespace io {
	namespace lua {
		class directory : table {
			public:
				static int Exists(lua_State* L);
				static int Create(lua_State* L);
				static int Remove(lua_State* L);

				void Register() {
					CAutoUnRef t_directory = LUA->GetNewTable();
						t_directory->SetMember("Exists", Exists);
						t_directory->SetMember("Create", Create);
						t_directory->SetMember("Remove", Remove);
					lua::io->SetMember("directory", t_directory);
				}
		};
	}
}

extern io::lua::directory* g_directory = new io::lua::directory();

#endif//LUA_DIRECTORY_HPP