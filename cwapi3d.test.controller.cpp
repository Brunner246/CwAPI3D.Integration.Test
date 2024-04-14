//
// Created by MichaelBrunner on 12/04/2024.
//

#include "cwapi3d.test.controller.h"
#include "spdlog/spdlog.h"

#include <locale>
#include <cwchar>
#include <optional>

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

std::optional<std::string> cwApi3dStringToStdString(CwAPI3D::Interfaces::ICwAPI3DString *const lValueKey) {
    char str[256];

    size_t convertedChars = 0;
    errno_t err = wcstombs_s(&convertedChars, str, sizeof(str), lValueKey->data(), _TRUNCATE);
    if (err != 0) {
        spdlog::error("wcstombs_s failed");
        return std::nullopt;
    }
    return std::string(str);
}

void CwAPI3D::Test::cwApi3dControllerIT(CwAPI3D::ControllerFactory *aControllerFactory) {

    spdlog::info("-------- cwApi3dControllerIT started --------");

    // Todo: Implement following in separate functions
    auto lElementMapQuery = aControllerFactory->createElementMapQuery();
    lElementMapQuery->setBySubgroup();
    const auto lVisibleElementIds = aControllerFactory->getElementController()->getVisibleIdentifiableElementIDs();
    const auto lElementIDListMap = aControllerFactory->getElementController()->mapElements(lVisibleElementIds,
                                                                                           lElementMapQuery);
    for (auto il{0}; il < lElementIDListMap->count(); il++) {
        const auto lValueKey = lElementIDListMap->valueAt(il);
        const auto lValueElements = lElementIDListMap->itemAt(il);
        char str[256];
        auto lValueKeyAsString = cwApi3dStringToStdString(lValueKey);
        if (!lValueKeyAsString) {
            spdlog::error("cwApi3dStringToStdString failed");
            return;
        }
        spdlog::info("Key: {} ; value count {}", lValueKeyAsString.value().c_str(), lValueElements->count());
    }

    // act
    countVisibleIdentifiableElementIds(*aControllerFactory->getElementController());
    createSnapshot(*aControllerFactory->getUtilityController());

    spdlog::info("-------- cwApi3dControllerIT finished --------");
}

