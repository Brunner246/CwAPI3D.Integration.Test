#include "CwAPI3D.h"
#include <iostream>
#include <source_location>
#include "Logger.h"
#include <cstdio>

CWAPI3D_PLUGIN bool plugin_x64_init(CwAPI3D::ControllerFactory *aFactory);

bool plugin_x64_init(CwAPI3D::ControllerFactory *aFactory) {
    const std::source_location &lWhere = std::source_location::current();
    auto lLogger = getLogger();

    if (!aFactory) {
        char lMessage[256];
        sprintf(lMessage, "ControllerFactory is null in file %s, line %d, function %s",
                lWhere.file_name(), lWhere.line(), lWhere.function_name());
        lLogger->log(lMessage);
        return false;
    }

    lLogger->log("ControllerFactory successfully initialized");
    const auto lVisibleIdentifiableElementIds = aFactory->getElementController()->getVisibleIdentifiableElementIDs();
    char lCountMessage[256];
    sprintf(lCountMessage, "VisibleIdentifiableElementIDs count: %d", lVisibleIdentifiableElementIds->count());
    lLogger->log(lCountMessage);
    return true;
}



// #include "CwAPI3D.h"
// #include <iostream>
// #include <source_location>
// #include <format>
// #include "Logger.h"


// CWAPI3D_PLUGIN bool plugin_x64_init(CwAPI3D::ControllerFactory *aFactory);

// bool plugin_x64_init(CwAPI3D::ControllerFactory *aFactory) {
//     const std::source_location &lWhere = std::source_location::current();
//     auto lLogger = getLogger();

//     if (!aFactory) {
//         auto lMessage = std::format<std::string>("ControllerFactory is null in file {0}, line {1}, function {2}",
//                                                  lWhere.file_name(), lWhere.line(), lWhere.function_name());
//         lLogger->log(lMessage);
//         return false;
//     }

//     lLogger->log("ControllerFactory successfully initialized");
//     const auto lVisibleIdentifiableElementIds = aFactory->getElementController()->getVisibleIdentifiableElementIDs();
//     lLogger->log(std::format<std::string>("VisibleIdentifiableElementIDs count: {0}",
//                                           std::to_string(lVisibleIdentifiableElementIds->count())));
//     return true;
// }
