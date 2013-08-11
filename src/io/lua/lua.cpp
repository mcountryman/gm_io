#include "lua.hpp"

namespace io {
	namespace lua {
		lua_State* L;
		CAutoUnRef io;

		std::vector<table*> table::m_tables;
	}
}