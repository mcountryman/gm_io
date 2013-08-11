#include "ILuaObject.h"

#ifndef CAUTOUNREF_H
#define CAUTOUNREF_H

#ifdef _WIN32
#pragma once
#endif

class CAutoUnRef
{
public:
	ILuaObject *luaObject;

	CAutoUnRef() : luaObject(NULL)
	{
	};

	CAutoUnRef(ILuaObject *obj) : luaObject(obj)
	{
	};

	~CAutoUnRef()
	{
		if(!luaObject)
			return;

		luaObject->UnReference();
	};

	ILuaObject* operator -> () const
	{
		return luaObject;
	};

	operator ILuaObject*()
	{
		return luaObject;
	};

	operator ILuaObject*() const
	{
		return luaObject;
	};

	const CAutoUnRef& operator=(const ILuaObject *obj)
	{
		luaObject = (ILuaObject *)obj;
		return *this;
	}
};

#endif // CAUTOUNREF_H