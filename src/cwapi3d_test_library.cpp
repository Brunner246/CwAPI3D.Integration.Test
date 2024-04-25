//
// Created by MichaelBrunner on 12/04/2024.
//

#include "CwAPI3D.h"
#include "SpdlogWrapper.h"
#include "cwapi3d_test_controller.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/fmt/fmt.h"

#include <filesystem>

CWAPI3D_PLUGIN bool plugin_x64_init(CwAPI3D::ControllerFactory* aFactory);

bool plugin_x64_init(CwAPI3D::ControllerFactory* aFactory)
{
  if (!aFactory)
  {
    spdlog::error("ControllerFactory is null");
    return false;
  }

  const std::filesystem::path lPluginDirectory = {aFactory->getUtilityController()->getPluginPath()->narrowData()};
  const std::filesystem::path lLogsDirectory = {"logs"};
  const auto lFilePath = lPluginDirectory / lLogsDirectory;
  if (!std::filesystem::exists(lFilePath))
  {
    std::filesystem::create_directory(lFilePath);
  }

  const auto lLoggerFilePath = fmt::format<std::string>("{}/CwAPI3D_Logger.json", lFilePath.string());

  // SpdlogWrapper::getInstance().init("CwAPI3D_Logger", lLoggerFilePath);

  const auto lLogger = spdlog::basic_logger_mt("CwAPI3D_Logger", lLoggerFilePath);
  spdlog::set_default_logger(lLogger);
  // spdlog::sinks::wincolor_stdout_sink
  lLogger->set_level(spdlog::level::trace); // warn

  lLogger->set_pattern(R"({"time": "%Y-%m-%d %H:%M:%S.%e", "level": "%^%l%$", "source location": "%@", "message": "%v"})");

  SPDLOG_LOGGER_CALL(lLogger.get(), spdlog::level::err, "Hello, {}!", "world");

  aFactory->getUtilityController()->printToConsole(L"ControllerFactory successfully initialized");
  spdlog::info("-------- ControllerFactory successfully initialized --------");

  CwAPI3D::Test::cwApi3dControllerIT(aFactory, lLogger);

  return true;
}
