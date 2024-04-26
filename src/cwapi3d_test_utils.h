//
// Created by MichaelBrunner on 15/04/2024.
//

#ifndef CWAPI3D_INTEGRATION_TEST_CWAPI3D_TEST_UTILS_H
#define CWAPI3D_INTEGRATION_TEST_CWAPI3D_TEST_UTILS_H


#include <optional>
#include <algorithm>
#include "ICwAPI3DString.h"
#include "CwAPI3D.h"

namespace CwAPI3D::Test::Utils
{

  std::optional<std::string> cwApi3dStringToStdString(CwAPI3D::Interfaces::ICwAPI3DString& aValueKey);

  template<typename T, typename Container>
  std::vector<T> toVector(Container* aContainer)
  { // use concepts in C++20
    std::vector<T> lVector(aContainer->count());
    for (auto il{0}; il < aContainer->count(); il++)
    {
      lVector.push_back(aContainer->at(il));
    }
    return lVector;
  }

  template<typename Func, typename Container>
  void applyFunctionToElements(Func aFunc, Container& args)
  {
    std::for_each(args.begin(), args.end(), aFunc);
  }

}
// CwAPI3D::Test::Utils

#endif //CWAPI3D_INTEGRATION_TEST_CWAPI3D_TEST_UTILS_H
