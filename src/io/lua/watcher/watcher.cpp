#include "watcher.hpp"

namespace io {
	namespace lua {
		std::map<std::string, cmonitor*> watcher::m_monitors;

		int watcher::Think(lua_State* L) {
			for(std::map<std::string, cmonitor*>::iterator pair = m_monitors.begin(); pair != m_monitors.end(); ++pair) {
				std::string name 	= pair->first;
				cmonitor* monitor 	= pair->second;

				if(monitor->changeMonitor.HasChanges()) {
					monitor->callback->Push();
					Lua()->Push(monitor->changeMonitor.FolderName().c_str());
					Lua()->Push(monitor->changeMonitor.GetChange().c_str());
					Lua()->Call(3);
				}
			}

			return 0;
		}
		int watcher::Add(lua_State* L) {
			Lua()->CheckType(1, GarrysMod::Lua::Type::STRING);
			Lua()->CheckType(2, GarrysMod::Lua::Type::STRING);
			Lua()->CheckType(3, GarrysMod::Lua::Type::FUNCTION);

			const char* name = Lua()->GetString(1);
			const char* path = Lua()->GetString(2);
			CAutoUnRef  func = Lua()->GetObject(3);

			bool watch_subtree = false;

			if(Lua()->GetType(4) == GarrysMod::Lua::Type::BOOL)
				watch_subtree = Lua()->GetBool(4);

			cmonitor* monitor = new cmonitor();
			Bootil::File::ChangeMonitor changeMonitor;

			bool result = changeMonitor.WatchFolder(path, watch_subtree);

			if(result) {
				monitor->callback 		= func;
				monitor->changeMonitor 	= changeMonitor;

				if(m_monitors.find(name) != m_monitors.end()) {
					Lua()->Push(watcher::Remove);
					Lua()->Push(name);
					Lua()->Call(1);
				}

				m_monitors[name] = monitor;
			}

			Lua()->Push(result);

			return 1;
		}
		int watcher::Remove(lua_State* L) {
			Lua()->CheckType(1, GarrysMod::Lua::Type::STRING);

			const char* name = Lua()->GetString(1);

			m_monitors.erase(name);

			return 0;
		}
	}
}