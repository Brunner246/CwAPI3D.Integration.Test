//
// Created by MichaelBrunner on 12/04/2024.
//

#ifndef CWAPI3D_INTEGRATION_TEST_ELEMENTCONTROLLER_IT_H
#define CWAPI3D_INTEGRATION_TEST_ELEMENTCONTROLLER_IT_H

#include "CwAPI3D.h"
#include "Logger.h"

namespace CwApi3dTest {
    void elementControllerIT(CwAPI3D::ElementController &aElementController);

    void countVisibleIdentifiableElementIds(CwAPI3D::ElementController &aElementController, LoggerInterface &aLogger);
}

#endif //CWAPI3D_INTEGRATION_TEST_ELEMENTCONTROLLER_IT_H
