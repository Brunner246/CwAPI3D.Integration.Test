//
// Created by MichaelBrunner on 12/04/2024.
//

#include "CwAPI3D.h"
#include "cwapi3d.test.controller.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"

CWAPI3D_PLUGIN bool plugin_x64_init(CwAPI3D::ControllerFactory *aFactory);

bool plugin_x64_init(CwAPI3D::ControllerFactory *aFactory) {
    auto lLogger = spdlog::basic_logger_mt("cwapi3d_logger", "logs/cwapi3d_logger.txt");
    spdlog::set_default_logger(lLogger);

    if (!aFactory) {
        spdlog::error("ControllerFactory is null");
        return false;
    }
    aFactory->getUtilityController()->printToConsole(L"ControllerFactory successfully initialized");
    spdlog::info("-------- ControllerFactory successfully initialized --------");

    CwAPI3D::Test::cwApi3dControllerIT(aFactory);

    return true;
}
