#include "Transform.h"

bool JREngine::Transform::Write(const rapidjson::Value& value) const
{
    return true;
}

bool JREngine::Transform::Read(const rapidjson::Value& value)
{
    READ_DATA(value, position);
    READ_DATA(value, scale);
    READ_DATA(value, rotation);

    return true;
}
