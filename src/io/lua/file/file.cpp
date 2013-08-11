#include "file.hpp"

namespace io {
	namespace lua {
		int file::Find(lua_State* L) {
			Lua()->CheckType(1, GarrysMod::Lua::Type::STRING);

			const char* path = Lua()->GetString(1);

			Bootil::String::List files;
			Bootil::String::List folders;

			int count = Bootil::File::Find(&files, &folders, path, true);

			int i_folders = 0;
			int i_files = 0;

			CAutoUnRef t_folders = Lua()->GetNewTable();
			CAutoUnRef t_files = Lua()->GetNewTable();

			BOOTIL_FOREACH_CONST(folder, folders, Bootil::String::List) {
				i_folders++;
				t_folders->SetMember(i_folders, ((Bootil::BString)*folder).c_str());
			}
			BOOTIL_FOREACH_CONST(file, files, Bootil::String::List) {
				i_files++;
				t_files->SetMember(i_files, ((Bootil::BString)*file).c_str());
			}

			Lua()->Push(t_folders);
			Lua()->Push(t_files);
			Lua()->Push(count);

			return 3;
		}
		int file::Exists(lua_State* L) {
			Lua()->CheckType(1, GarrysMod::Lua::Type::STRING);

			const char* path = Lua()->GetString(1);

			Lua()->Push(Bootil::File::Exists(path) == 1);

			return 1;
		}
		int file::GetFilesInFolder(lua_State* L) {
			Lua()->CheckType(1, GarrysMod::Lua::Type::STRING);

			const char* path = Lua()->GetString(1);
			bool recursive = false;

			if(Lua()->GetType(2) == GarrysMod::Lua::Type::STRING)
				recursive = Lua()->GetBool(2);

			Bootil::String::List files;

			int count = Bootil::File::GetFilesInFolder(path, files, recursive);

			int i_files = 0;
			CAutoUnRef t_files = Lua()->GetNewTable();

			BOOTIL_FOREACH_CONST(file, files, Bootil::String::List) {
				i_files++;
				t_files->SetMember(i_files, ((Bootil::BString)*file).c_str());
			}

			Lua()->Push(t_files);
			Lua()->Push(count);

			return 2;
		}

		int file::Size(lua_State* L) {
			Lua()->CheckType(1, GarrysMod::Lua::Type::STRING);

			const char* path = Lua()->GetString(1);

			Lua()->Push((double)Bootil::File::Size(path));

			return 1;
		}
		int file::Read(lua_State* L) {
			Lua()->CheckType(1, GarrysMod::Lua::Type::STRING);

			const char* path = Lua()->GetString(1);
			Bootil::BString data;

			if(Bootil::File::Read(path, data))
				Lua()->Push(data.c_str());
			else
				Lua()->Push("");

			return 1;
		}
		int file::Write(lua_State* L) {
			Lua()->CheckType(1, GarrysMod::Lua::Type::STRING);
			Lua()->CheckType(2, GarrysMod::Lua::Type::STRING);

			const char* path = Lua()->GetString(1);
			const char* data = Lua()->GetString(2);

			Lua()->Push(Bootil::File::Write(path, data));

			return 1;
		}
		int file::Append(lua_State* L) {
			Lua()->CheckType(1, GarrysMod::Lua::Type::STRING);
			Lua()->CheckType(2, GarrysMod::Lua::Type::STRING);

			const char* path = Lua()->GetString(1);
			const char* data = Lua()->GetString(2);

			Lua()->Push(Bootil::File::Append(path, data));

			return 1;
		}

		int file::Copy(lua_State* L) {
			Lua()->CheckType(1, GarrysMod::Lua::Type::STRING);
			Lua()->CheckType(2, GarrysMod::Lua::Type::STRING);

			const char* path_from 	= Lua()->GetString(1);
			const char* path_to 	= Lua()->GetString(2);

			Lua()->Push(Bootil::File::Copy(path_from, path_to));

			return 1;
		}
		int file::Move(lua_State* L) {
			Lua()->CheckType(1, GarrysMod::Lua::Type::STRING);
			Lua()->CheckType(2, GarrysMod::Lua::Type::STRING);

			const char* path_from 	= Lua()->GetString(1);
			const char* path_to 	= Lua()->GetString(2);

			Lua()->Push(
				Bootil::File::Copy(path_from, path_to) &&
				Bootil::File::RemoveFile(path_from)
			);

			return 1;
		}
		int file::Remove(lua_State* L) {
			Lua()->CheckType(1, GarrysMod::Lua::Type::STRING);

			const char* path = Lua()->GetString(1);

			Lua()->Push(Bootil::File::RemoveFile(path));

			return 1;
		}

		int file::GetTempDir(lua_State* L) {
			Lua()->Push(Bootil::File::GetTempDir().c_str());
			return 1;
		}
		int file::GetTempFilename(lua_State* L) {
			Lua()->Push(Bootil::File::GetTempFilename().c_str());
			return 1;
		}
	}
}