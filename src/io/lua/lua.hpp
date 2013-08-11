#ifndef LUA_HPP
#define LUA_HPP

#include "../io.hpp"

namespace io {
	namespace lua {
		extern lua_State* L;
		extern CAutoUnRef io;

		class table {
			private:
				static std::vector<table*> m_tables;
			public:
				table() {
					m_tables.push_back(this);
				}

				virtual void Register() = 0;
				static 	void RegisterAll() {
					for(long i = 0; i < (long)m_tables.size(); i++) {
						m_tables.at(i)->Register();
					}
				}
		};
	}
}

#undef  LUA
#define LUA modulemanager->GetLuaInterface(io::lua::L)

#define SETMEMBER(__TABLE__, __INDEX__) __TABLE__->SetMember(#__INDEX__, __INDEX__)

#endif//LUA_HPP