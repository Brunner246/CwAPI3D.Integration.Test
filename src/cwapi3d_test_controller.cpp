//
// Created by MichaelBrunner on 12/04/2024.
//

#include "cwapi3d_test_controller.h"
#include "spdlog/spdlog.h"
#include "cwapi3d_test_utils.h"
#include <cwchar>
#include <filesystem>

void countVisibleIdentifiableElementIds(CwAPI3D::ElementController& aElementController)
{
  const auto lVisibleIdentifiableElementIds = aElementController.getVisibleIdentifiableElementIDs();
  if (lVisibleIdentifiableElementIds == nullptr)
  {
    spdlog::error("{}: VisibleIdentifiableElementIDs is null", __FUNCTION__);
    return;
  }
  spdlog::info("VisibleIdentifiableElementIDs count: {}", lVisibleIdentifiableElementIds->count());
}

void createSnapshot(CwAPI3D::UtilityController& aUtilityController)
{
  const auto lSnapshotBase64 = aUtilityController.createSnapshot(L"PNG");
  if (lSnapshotBase64 == nullptr)
  {
    spdlog::error("{}: SnapshotBytes is null", __FUNCTION__);
    return;
  }
  aUtilityController.printToConsole(lSnapshotBase64->data());
  spdlog::info("Snapshot size: {}", std::wcslen(lSnapshotBase64->data()));
}

void printElementNames(CwAPI3D::ControllerFactory& aControllerFactory, const std::vector<CwAPI3D::elementID>& elementIds)
{
  CwAPI3D::Test::Utils::applyFunctionToElements([&aControllerFactory](const CwAPI3D::elementID aElementId) {
    if (const auto lName = aControllerFactory.getAttributeController()->getName(aElementId);
        lName->length() < 1)
    {
      spdlog::error("{}: Name is null", __FUNCTION__);
    }
    else
    {
      spdlog::info("\tName: {}", lName->narrowData());
    }
  },
                                                elementIds);
}

void printElementIDListMapInfo(CwAPI3D::Interfaces::ICwAPI3DElementIDListMap* lElementIDListMap)
{
  for (auto il{0}; il < lElementIDListMap->count(); il++)
  {
    const auto lValueKey = lElementIDListMap->valueAt(il);
    const auto lValueElements = lElementIDListMap->itemAt(il);

    if (lValueKey->length() < 1 || lValueElements == nullptr)
    {
      spdlog::error("{}: Key is null", __FUNCTION__);
      return;
    }
    spdlog::info("Key: {} ; value count {}", lValueKey->narrowData(), lValueElements->count());
  }
}

void import3dcFile(CwAPI3D::FileController& aFileController, CwAPI3D::Interfaces::ICwAPI3DImport3dcOptions* api3DImport3DcOptions, const std::filesystem::path& aFilePath)
{
  const auto lFile = aFileController.import3dcFileWithOptions(aFilePath.c_str(), api3DImport3DcOptions);
  if (lFile == nullptr)
  {
    spdlog::error("{}: File is null", __FUNCTION__);
    return;
  }
  if (lFile->count() < 1)
  {
    spdlog::error("{}: File count is 0", __FUNCTION__);
    return;
  }
  spdlog::info("File: {}", lFile->count());
}

void CwAPI3D::Test::cwApi3dControllerIT(CwAPI3D::ControllerFactory* aControllerFactory)
{
  spdlog::info("-------- cwApi3dControllerIT started --------");

  const auto lElementMapQuery = aControllerFactory->createElementMapQuery();
  lElementMapQuery->setBySubgroup();
  const auto lVisibleElementIds = aControllerFactory->getElementController()->getVisibleIdentifiableElementIDs();

  countVisibleIdentifiableElementIds(*aControllerFactory->getElementController());
  createSnapshot(*aControllerFactory->getUtilityController());

  const auto lVisibleElementIdsVector = CwAPI3D::Test::Utils::toVector<CwAPI3D::elementID>(lVisibleElementIds);
  printElementNames(*aControllerFactory, lVisibleElementIdsVector);

  const auto lMaterialIdList = aControllerFactory->getMaterialController()->getAllMaterials();
  auto lMaterialIdListVector = CwAPI3D::Test::Utils::toVector<CwAPI3D::materialID>(lMaterialIdList);

  const auto lElementIDListMap = aControllerFactory->getElementController()->mapElements(lVisibleElementIds,
                                                                                         lElementMapQuery);
  printElementIDListMapInfo(lElementIDListMap);

  const auto lPluginPath = aControllerFactory->getUtilityController()->getPluginPath();
  std::filesystem::path lFilePath = lPluginPath->data();
  lFilePath /= "static-symbol.3dc";
  const auto lApi3dImport3DcOptions = aControllerFactory->createImport3dcOptions();
  lApi3dImport3DcOptions->setImportExportSolids(true);
  lApi3dImport3DcOptions->setImportSavedScenes(true);
  import3dcFile(*aControllerFactory->getFileController(), lApi3dImport3DcOptions, lFilePath);

  spdlog::info("-------- cwApi3dControllerIT finished --------");
}