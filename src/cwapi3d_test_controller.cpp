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
    spdlog::error("Controller: {} Function: {}: Description: {}", "ElementController", "getVisibleIdentifiableElementIDs", "ElementIds are null");
    return;
  }
  spdlog::info("Controller: {} Function: {}: Description: {}", "ElementController", "getVisibleIdentifiableElementIDs", lVisibleIdentifiableElementIds->count());
}

void createSnapshot(CwAPI3D::UtilityController& aUtilityController)
{
  const auto lSnapshotBase64 = aUtilityController.createSnapshot(L"PNG");
  if (lSnapshotBase64 == nullptr)
  {
    spdlog::error("Controller: {} Function: {}: Description: {}", "UtilityController", "createSnapshot", "snapshot is null");
    return;
  }
  aUtilityController.printToConsole(lSnapshotBase64->data());
  spdlog::info("Controller: {} Function: {}: Description: {}", "UtilityController", "createSnapshot", std::wcslen(lSnapshotBase64->data()));
}

void printElementNames(CwAPI3D::ControllerFactory& aControllerFactory, const std::vector<CwAPI3D::elementID>& elementIds)
{
  auto lNameGetter = [&aControllerFactory](const CwAPI3D::elementID aElementId) {
    if (const auto lName = aControllerFactory.getAttributeController()->getName(aElementId);
        lName == nullptr)
    {
      spdlog::error("Controller: {} Function: {}: Description: {}", "AttributeController", "getName", "Name is null");
    }
    else
    {
      spdlog::info("Controller: {} Function: {}: Description: {}", "AttributeController", "getName", lName->narrowData());
    }
  };

  CwAPI3D::Test::Utils::applyFunctionToElements(lNameGetter, elementIds);
}

void printElementIDListMapInfo(CwAPI3D::Interfaces::ICwAPI3DElementIDListMap* lElementIDListMap)
{
  for (auto il{0}; il < lElementIDListMap->count(); il++)
  {
    const auto lValueKey = lElementIDListMap->valueAt(il);
    const auto lValueElements = lElementIDListMap->itemAt(il);

    if (lValueKey->length() < 1 || lValueElements == nullptr)
    {
      spdlog::error("Controller: {} Function: {}: Description: {}", "CwAPI3D", "ElementIDListMap", "no key or value");
      return;
    }
    spdlog::info("Controller: {} Function: {}: Description: key: {} value(count):{}", "CwAPI3D", "ElementIDListMap", lValueKey->narrowData(), lValueElements->count());
  }
}

void import3dcFile(CwAPI3D::FileController& aFileController, CwAPI3D::Interfaces::ICwAPI3DImport3dcOptions* api3DImport3DcOptions, const std::filesystem::path& aFilePath, const std::shared_ptr<spdlog::logger>& aLogger)
{
  const auto lFile = aFileController.import3dcFileWithOptions(aFilePath.c_str(), api3DImport3DcOptions);
  if (lFile == nullptr)
  {
    spdlog::error("Controller: {} Function: {}: Description: {}", "FileController", "import3dcFileWithOptions", "File is null");
    return;
  }
  if (lFile->count() < 1)
  {
    spdlog::error("Controller: {} Function: {}: Description: {}", "FileController", "import3dcFileWithOptions", "File content is empty");
    return;
  }
  if (lFile->count() != 3)
  {
    SPDLOG_LOGGER_CALL(aLogger.get(), spdlog::level::err, "Hello, {}!", "world");
    spdlog::error("Controller: {} Function: {}: Description: {}", "FileController", "import3dcFileWithOptions", "File content is wrong - 3 elements expected");
  }
  spdlog::info("Controller: {} Function: {}: Description: {}", "FileController", "import3dcFileWithOptions", lFile->count());
}

auto buildPathTo3dcFile(CwAPI3D::ControllerFactory* aControllerFactory)
{
  const auto lPluginPath = aControllerFactory->getUtilityController()->getPluginPath();
  std::filesystem::path lFilePath = lPluginPath->data();
  lFilePath /= "static-symbol.3dc";
  return lFilePath;
}
auto set3dcImportFileOptions(CwAPI3D::ControllerFactory* aControllerFactory)
{
  const auto lApi3dImport3DcOptions = aControllerFactory->createImport3dcOptions();
  lApi3dImport3DcOptions->setImportExportSolids(true);
  lApi3dImport3DcOptions->setImportSavedScenes(true);
  return lApi3dImport3DcOptions;
}
void CwAPI3D::Test::cwApi3dControllerIT(CwAPI3D::ControllerFactory* aControllerFactory, const std::shared_ptr<spdlog::logger>& aLogger)
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

  const auto lApi3dImport3DcOptions = set3dcImportFileOptions(aControllerFactory);
  import3dcFile(*aControllerFactory->getFileController(), lApi3dImport3DcOptions, buildPathTo3dcFile(aControllerFactory), const std::shared_ptr<spdlog::logger>& aLogger);

  spdlog::info("-------- cwApi3dControllerIT finished --------");
}