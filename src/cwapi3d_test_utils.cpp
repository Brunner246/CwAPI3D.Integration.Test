//
// Created by MichaelBrunner on 15/04/2024.
//

#include "cwapi3d_test_utils.h"
#include "spdlog/spdlog.h"

std::optional<std::string> CwAPI3D::Test::Utils::cwApi3dStringToStdString(CwAPI3D::Interfaces::ICwAPI3DString& aValueKey)
{
  char str[256];
  size_t convertedChars = 0;
  errno_t err = wcstombs_s(&convertedChars, str, sizeof(str), aValueKey.data(), _TRUNCATE);
  if (err != 0)
  {
    spdlog::error("wcstombs_s failed");
    return std::nullopt;
  }
  return std::string(str);
}
