# CwAPI3D.Integration.Test

This repository serves as a testing ground for the compatibility of CwAPI3D. The primary goal is to ensure that the API functions as expected across different environments and use-cases.

To achieve this, we employ a logging mechanism that records the operations and results of the API during runtime. This log file is then compared against a reference log, which represents the expected behavior of the API.

Any discrepancies between the generated log file and the reference log are flagged as deviations. These deviations could indicate potential compatibility issues with the API, which can then be investigated and addressed.

By continuously monitoring and comparing these logs, we can maintain the robustness of CwAPI3D and ensure its reliable performance across various scenarios.

[![CI](https://github.com/Brunner246/CwAPI3D.Integration.Test/actions/workflows/main.yml/badge.svg)](https://github.com/Brunner246/CwAPI3D.Integration.Test/actions/workflows/main.yml)
