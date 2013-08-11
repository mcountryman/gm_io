#ifndef WATCHER_HPP
#define WATCHER_HPP

#include "../lua.hpp"

namespace io {
	namespace lua {
		struct cmonitor {
			CAutoUnRef 					callback;
			Bootil::File::ChangeMonitor changeMonitor;
		};
		class watcher : table {
			private:
				static std::map<std::string, cmonitor*> m_monitors;
			public:
				static int Think(lua_State* L);
				static int Add(lua_State* L);
				static int Remove(lua_State* L);

				void Register() {
					CAutoUnRef t_watcher = LUA->GetNewTable();
						t_watcher->SetMember("Add", Add);
						t_watcher->SetMember("Remove", Remove);
					lua::io->SetMember("watcher", t_watcher);

					{ // hook.Add("Think", "io.watcher.Think", Think);
						CAutoUnRef hook = Lua()->Global()->GetMember("hook");
						CAutoUnRef Add 	= hook->GetMember("Add");

						Add->Push();
						LUA->Push("Think");
						LUA->Push("io.watcher.Think");
						LUA->Push(Think);
						LUA->Call(3);
					}
				}
		};
	}
}

extern io::lua::watcher* g_watcher = new io::lua::watcher();

#endif//WATCHER_HPP