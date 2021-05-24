#pragma once

#include <inja/inja.hpp>

using Json = inja::json;

static inja::Environment env{"./templates/"};

#include <string>

namespace Render
{
    inline std::string render_file(const std::string& filePath, const Json& json)
    {
        return env.render_file(filePath,json);
    }

    inline std::string render_string(const std::string& str, const Json& json)
    {
        return inja::render(str,json);
    }
};

