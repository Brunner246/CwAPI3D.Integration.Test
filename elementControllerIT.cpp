//
// Created by MichaelBrunner on 12/04/2024.
//

#include "elementControllerIT.h"
#include "spdlog/spdlog.h"


void CwApi3dTest::countVisibleIdentifiableElementIds(CwAPI3D::ElementController &aElementController) {

    spdlog::info("countVisibleIdentifiableElementIds started");
    const auto lVisibleIdentifiableElementIds = aElementController.getVisibleIdentifiableElementIDs();
    spdlog::info("VisibleIdentifiableElementIDs count: {}", lVisibleIdentifiableElementIds->count());
}

void CwApi3dTest::elementControllerIT(CwAPI3D::ElementController &aElementController) {

    spdlog::info("-------- elementControllerIT started --------");

    countVisibleIdentifiableElementIds(aElementController);

    spdlog::info("-------- elementControllerIT finished --------");
}
