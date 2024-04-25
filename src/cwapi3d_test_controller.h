//
// Created by MichaelBrunner on 12/04/2024.
//

#ifndef CWAPI3D_INTEGRATION_TEST_ELEMENTCONTROLLER_IT_H
#define CWAPI3D_INTEGRATION_TEST_ELEMENTCONTROLLER_IT_H

#include "CwAPI3D.h"

#include <memory>
#include "spdlog/spdlog.h"

namespace CwAPI3D::Test
{
  void cwApi3dControllerIT(CwAPI3D::ControllerFactory* aControllerFactory, const std::shared_ptr<spdlog::logger>& aLogger);
}



#endif //CWAPI3D_INTEGRATION_TEST_ELEMENTCONTROLLER_IT_H
