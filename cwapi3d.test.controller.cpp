//
// Created by MichaelBrunner on 12/04/2024.
//

#include "cwapi3d.test.controller.h"
#include "spdlog/spdlog.h"
#include "cwapi3d.test.utils.h"
#include <cwchar>

void countVisibleIdentifiableElementIds(CwAPI3D::ElementController &aElementController) {
    const auto lVisibleIdentifiableElementIds = aElementController.getVisibleIdentifiableElementIDs();
    if (!lVisibleIdentifiableElementIds) {
        spdlog::error("VisibleIdentifiableElementIDs is null");
        return;
    }
    spdlog::info("VisibleIdentifiableElementIDs count: {}", lVisibleIdentifiableElementIds->count());
}

void createSnapshot(CwAPI3D::UtilityController &aUtilityController) {
    const auto lSnapshotBase64 = aUtilityController.createSnapshot(L"PNG");
    if (!lSnapshotBase64) {
        spdlog::error("SnapshotBytes is null");
        return;
    }
    aUtilityController.printToConsole(lSnapshotBase64->data());
    spdlog::info("Snapshot size: {}", std::wcslen(lSnapshotBase64->data()));
}

void
printElementNames(CwAPI3D::ControllerFactory &aControllerFactory, const std::vector<CwAPI3D::elementID> &elementIds) {
    CwAPI3D::Test::Utils::applyFunctionToElements([&aControllerFactory](CwAPI3D::elementID aElementId) {
        auto lName = aControllerFactory.getAttributeController()->getName(aElementId);
        lName->length() > 0 ? spdlog::info("\tName: {}", lName->narrowData()) : spdlog::error("Name is null");
    }, elementIds);
}

void printElementIDListMapInfo(CwAPI3D::Interfaces::ICwAPI3DElementIDListMap *lElementIDListMap) {
    for (auto il{0}; il < lElementIDListMap->count(); il++) {
        const auto lValueKey = lElementIDListMap->valueAt(il);
        const auto lValueElements = lElementIDListMap->itemAt(il);

        if (lValueKey->length() < 1) {
            spdlog::error("cwApi3dStringToStdString failed");
            return;
        }
        spdlog::info("Key: {} ; value count {}", lValueKey->narrowData(), lValueElements->count());
    }
}

void CwAPI3D::Test::cwApi3dControllerIT(CwAPI3D::ControllerFactory *aControllerFactory) {
    spdlog::info("-------- cwApi3dControllerIT started --------");

    auto lElementMapQuery = aControllerFactory->createElementMapQuery();
    lElementMapQuery->setBySubgroup();
    const auto lVisibleElementIds = aControllerFactory->getElementController()->getVisibleIdentifiableElementIDs();

    countVisibleIdentifiableElementIds(*aControllerFactory->getElementController());
    createSnapshot(*aControllerFactory->getUtilityController());

    const auto lVisibleElementIdsVector = CwAPI3D::Test::Utils::toVector<CwAPI3D::elementID>(lVisibleElementIds);
    printElementNames(*aControllerFactory, lVisibleElementIdsVector);

    const auto lMaterialIdList = aControllerFactory->getMaterialController()->getAllMaterials();
    const auto lMaterialIdListVector = CwAPI3D::Test::Utils::toVector<CwAPI3D::materialID>(lMaterialIdList);

    const auto lElementIDListMap = aControllerFactory->getElementController()->mapElements(lVisibleElementIds,
                                                                                           lElementMapQuery);
    printElementIDListMapInfo(lElementIDListMap);

    spdlog::info("-------- cwApi3dControllerIT finished --------");
}
