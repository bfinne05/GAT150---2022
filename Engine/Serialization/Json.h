#pragma once
#include "rapidjson/document.h" 

#include <string> 

namespace gre::json
{
	bool Load(const std::string& filename, rapidjson::Document& document);

	bool Get(const rapidjson::Value& value, const std::string& name, int& data);
	bool Get(const rapidjson::Value& value, const std::string& name, bool& data);
	
}