#include "CwAPI3D.h"
#include <iostream>
#include <source_location>
#include <format>
#include "Logger.h"


CWAPI3D_PLUGIN bool plugin_x64_init(CwAPI3D::ControllerFactory *aFactory);

bool plugin_x64_init(CwAPI3D::ControllerFactory *aFactory) {
    const std::source_location &lWhere = std::source_location::current();
    auto lLogger = getLogger();

    if (!aFactory) {
        auto lMessage = std::format<std::string>("ControllerFactory is null in file {0}, line {1}, function {2}",
                                                 lWhere.file_name(), lWhere.line(), lWhere.function_name());
        lLogger->log(lMessage);
        return false;
    }

    lLogger->log("ControllerFactory successfully initialized");
    const auto lVisibleIdentifiableElementIds = aFactory->getElementController()->getVisibleIdentifiableElementIDs();
    lLogger->log(std::format<std::string>("VisibleIdentifiableElementIDs count: {0}",
                                          std::to_string(lVisibleIdentifiableElementIds->count())));
    return true;
}
