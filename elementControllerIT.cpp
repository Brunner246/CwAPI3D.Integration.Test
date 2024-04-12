//
// Created by MichaelBrunner on 12/04/2024.
//

#include "elementControllerIT.h"

void CwApi3dTest::countVisibleIdentifiableElementIds(CwAPI3D::ElementController &aElementController,
                                                     LoggerInterface &aLogger) {

    const auto lVisibleIdentifiableElementIds = aElementController.getVisibleIdentifiableElementIDs();
    aLogger.log("VisibleIdentifiableElementIDs count: " + std::to_string(lVisibleIdentifiableElementIds->count()));
}

void CwApi3dTest::elementControllerIT(CwAPI3D::ElementController &aElementController) {
    auto lLogger = getLogger();
    lLogger->log("elementControllerIT started");

    countVisibleIdentifiableElementIds(aElementController, *lLogger);

    lLogger->log("elementControllerIT finished");
}
