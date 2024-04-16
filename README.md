# CwAPI3D.Integration.Test

This repository serves as a testing ground for the compatibility of CwAPI3D. The primary goal is to ensure that the API functions as expected across different environments and use-cases.

To achieve this, we employ the `spdlog` library to record the operations and results of the API during runtime. `spdlog` is a fast, header-only/compiled, C++ logging library. It offers a variety of sinks (such as rotating files, console, syslog, etc.) and a feature-rich formatting system.


[![CI](https://github.com/Brunner246/CwAPI3D.Integration.Test/actions/workflows/main.yml/badge.svg)](https://github.com/Brunner246/CwAPI3D.Integration.Test/actions/workflows/main.yml)

## Running the tests

```cmd
cadwork.dir\ci_start.exe "C:\...\debugFile.3d" /PLUGIN=CwAPI3D.Integration.Test
```

