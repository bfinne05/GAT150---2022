#pragma once
#include "rapidjson/document.h" 
#include <string> 
#include <Vector>
#define READ_DATA(value, data) gre::json::Get(value, #data, data)

namespace gre
{
	struct Vector2;
	struct Color;
	struct Rect;

	namespace json
	{
		
		bool Load(const std::string& filename, rapidjson::Document& document);

		bool Get(const rapidjson::Value& value, const std::string& name, int& data);
		bool Get(const rapidjson::Value& value, const std::string& name, float& data);
		bool Get(const rapidjson::Value& value, const std::string& name, bool& data);
		bool Get(const rapidjson::Value& value, const std::string& name, std::string& data);
		bool Get(const rapidjson::Value& value, const std::string& name, gre::Vector2& data);
		bool Get(const rapidjson::Value& value, const std::string& name, gre::Color& data);
		bool Get(const rapidjson::Value& value, const std::string& name, gre::Rect& data);
		bool Get(const rapidjson::Value& value, const std::string& name, std::vector<std::string>& data);
		bool Get(const rapidjson::Value& value, const std::string& name, std::vector<int>& data);
	}
}