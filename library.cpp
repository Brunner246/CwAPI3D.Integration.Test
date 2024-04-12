#include "CwAPI3D.h"
#include "elementControllerIT.h"

CWAPI3D_PLUGIN bool plugin_x64_init(CwAPI3D::ControllerFactory *aFactory);

bool plugin_x64_init(CwAPI3D::ControllerFactory *aFactory) {
    auto lLogger = getLogger();
    if (!aFactory) {
        // auto lMessage = std::format<std::string>("ControllerFactory is null in file {0}, line {1}, function {2}",
        //                                          lWhere.file_name(), lWhere.line(), lWhere.function_name());
        lLogger->log("ControllerFactory is null");
        return false;
    }
    aFactory->getUtilityController()->printToConsole(L"ControllerFactory successfully initialized");

    lLogger->log("ControllerFactory successfully initialized");

    CwApi3dTest::elementControllerIT(*aFactory->getElementController());

    return true;
}
