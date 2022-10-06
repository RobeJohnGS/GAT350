#pragma once
#include <string>

namespace JREngine
{
	class Resource
	{
	public:
		virtual bool Create(std::string name, ...) = 0;
	};
}
