#include "CwAPI3D.h"
#include "Logger.h"

CWAPI3D_PLUGIN bool plugin_x64_init(CwAPI3D::ControllerFactory *aFactory);

bool plugin_x64_init(CwAPI3D::ControllerFactory *aFactory) {
    auto lLogger = getLogger();
    if (!aFactory) {
        // auto lMessage = std::format<std::string>("ControllerFactory is null in file {0}, line {1}, function {2}",
        //                                          lWhere.file_name(), lWhere.line(), lWhere.function_name());
        lLogger->log("ControllerFactory is null");
        return false;
    }

    // lLogger->log("ControllerFactory successfully initialized");
    const auto lVisibleIdentifiableElementIds = aFactory->getElementController()->getVisibleIdentifiableElementIDs();
    // lLogger->log(std::format<std::string>("VisibleIdentifiableElementIDs count: {0}",
    //                                       std::to_string(lVisibleIdentifiableElementIds->count())));
    lLogger->log("VisibleIdentifiableElementIDs count: " + std::to_string(lVisibleIdentifiableElementIds->count()));
    return true;
}
