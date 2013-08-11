#ifndef LUA_FILE_HPP
#define LUA_FILE_HPP

#include "../lua.hpp"

namespace io {
	namespace lua {
		class file : table {
			public:
				static int Find(lua_State* L);
				static int Exists(lua_State* L);
				static int GetFilesInFolder(lua_State* L);

				static int Size(lua_State* L);
				static int Read(lua_State* L);
				static int Write(lua_State* L);
				static int Append(lua_State* L);

				static int Copy(lua_State* L);
				static int Move(lua_State* L);
				static int Remove(lua_State* L);

				static int GetTempDir(lua_State* L);
				static int GetTempFilename(lua_State* L);

				void Register() {
					CAutoUnRef t_file = LUA->GetNewTable();
						t_file->SetMember("Find", Find);
						t_file->SetMember("Exists", Exists);
						t_file->SetMember("GetFilesInFolder", GetFilesInFolder);

						t_file->SetMember("Size", Size);
						t_file->SetMember("Read", Read);
						t_file->SetMember("Write", Write);
						t_file->SetMember("Append", Append);

						t_file->SetMember("Copy", Copy);
						t_file->SetMember("Move", Move);
						t_file->SetMember("Remove", Remove);

						t_file->SetMember("GetTempDir", GetTempDir);
						t_file->SetMember("GetTempFilename", GetTempFilename);
					lua::io->SetMember("file", t_file);
				}
		};
	}
}

extern io::lua::file* g_file = new io::lua::file();

#endif//LUA_FILE_HPP