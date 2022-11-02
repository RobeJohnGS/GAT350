#pragma once
#include <string>

namespace JREngine
{
	class Resource
	{
	public:
		virtual bool Create(const std::string name, ...) = 0;
	};
}