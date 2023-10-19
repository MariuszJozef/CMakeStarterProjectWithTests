# A simple project with tests and mocks to get started with (modern) CMake, CMakePresets.json, CTest, GTest and GMock

This project should serve as a convenient starting template for coding more elaborate projects with tests and mocks. Parametrised tests, fixtures, and mocks are exemplified and can be easily extended. 

```
.
├── CMakeLists.txt
├── CMakePresets.json
├── CMakeUtils
│   ├── FindOrFetch
│   │   └── FindOrFetchGTestGMock.cmake
│   ├── Handy
│   │   ├── DisallowInSourceBuilds.cmake
│   │   ├── DisplayGenericInfo.cmake
│   │   └── SelectCompilerViaFlagIfNotUsingCMakePresets.cmake
│   └── Presets
│       ├── BuildType.json
│       ├── Compilers.json
│       ├── Platforms.json
│       └── SingleConfigGenerators.json
├── Code
│   ├── CMakeLists.txt
│   └── StarterProject
│       ├── hdr
│       │   └── StarterProject.hpp
│       └── src
│           ├── MainStarterProject.cpp
│           └── StarterProject.cpp
├── Mock
│   ├── hdr
│   │   ├── IRealEntity.hpp
│   │   └── MockEntity.hpp
│   └── src
│       └── TestMockEntity.cpp
├── README.md
└── Tests
    ├── CMakeLists.txt
    └── UnitTestStarterProject
        ├── hdr
        │   ├── StarterProject_FixtureTests.hpp
        │   ├── StarterProject_ParametrisedFixtureTests.hpp
        │   └── StarterProject_ParametrisedTests.hpp
        └── src
            ├── StarterProject_FixtureTests.cpp
            ├── StarterProject_ParametrisedFixtureTests.cpp
            ├── StarterProject_ParametrisedTests.cpp
            └── StarterProject_StandAloneTests.cpp
```

The program and tests can be executed by either:
- a flag appended to cmake build command: **--target run runUnitTest**: 
`cmake --build <buildDir> -j <number of CPU cores> --target run runUnitTest`
or
`cmake --build --preset <presetName> --target run runUnitTest`
- or via ctest command: `ctest --test-dir <buildDir> -j <number of CPU cores> --output-on-failure`

Only one set from the below command examples (not exhaustive) is needed, choose whichever suits:

**N.B.**

- On Windows 11 it is preferable to issue the commands from **"Developer Command Prompt for VS 2022"** instead of regular PowerShell or CMD because the former has predefined Visual Studio environment variables which enable compilation with VS compiler.
- If nevertheless using PowerShell/CMD, or on Windows 10, one must first run some appropriate *.bat scripts that define VS environment variables.

## CMake commands to configure, build, and run the program unit tests *without* CMakePresets.json

### Ninja single-config, VS (cl.exe) compiler
```
cmake -S . -B buildNinja/Msvc -G Ninja -D linkGTestAsSharedLibrary=<ON/OFF> -D setCompiler=msvc -D CMAKE_BUILD_TYPE=Debug
cmake --build buildNinja/Msvc -j8 --target run runUnitTest
ctest --test-dir buildNinja/Msvc -j8 --output-on-failure -D CMAKE_BUILD_TYPE=Debug

OR

cmake -S . -B buildNinja/Msvc -G Ninja -D linkGTestAsSharedLibrary=<ON/OFF> -D setCompiler=msvc -D CMAKE_BUILD_TYPE=Release
cmake --build buildNinja/Msvc -j8 --target run runUnitTest
ctest --test-dir buildNinja/Msvc -j8 --output-on-failure -D CMAKE_BUILD_TYPE=Release

OR

cmake -S . -B buildNinja/Msvc -G Ninja -D linkGTestAsSharedLibrary=<ON/OFF> -D setCompiler=msvc -D CMAKE_BUILD_TYPE=RelWithDebInfo
cmake --build buildNinja/Msvc -j8 --target run runUnitTest
ctest --test-dir buildNinja/Msvc -j8 --output-on-failure -D CMAKE_BUILD_TYPE=RelWithDebInfo

OR

cmake -S . -B buildNinja/Msvc -G Ninja -D linkGTestAsSharedLibrary=<ON/OFF> -D setCompiler=msvc -D CMAKE_BUILD_TYPE=MinSizeRel
cmake --build buildNinja/Msvc -j8 --target run runUnitTest
ctest --test-dir buildNinja/Msvc -j8 --output-on-failure -D CMAKE_BUILD_TYPE=MinSizeRel
```

### Ninja single-config, GNU (gcc, g++) compiler
```
cmake -S . -B buildNinja/Gnu -G Ninja -D linkGTestAsSharedLibrary=<ON/OFF> -D setCompiler=gnu -D CMAKE_BUILD_TYPE=Debug
cmake --build buildNinja/Gnu -j8 --target run runUnitTest
ctest --test-dir buildNinja/Gnu -j8 --output-on-failure -D CMAKE_BUILD_TYPE=Debug

OR

cmake -S . -B buildNinja/Gnu -G Ninja -D linkGTestAsSharedLibrary=<ON/OFF> -D setCompiler=gnu -D CMAKE_BUILD_TYPE=Release
cmake --build buildNinja/Gnu -j8 --target run runUnitTest
ctest --test-dir buildNinja/Gnu -j8 --output-on-failure -D CMAKE_BUILD_TYPE=Release

OR

cmake -S . -B buildNinja/Gnu -G Ninja -D linkGTestAsSharedLibrary=<ON/OFF> -D setCompiler=gnu -D CMAKE_BUILD_TYPE=RelWithDebInfo
cmake --build buildNinja/Gnu -j8 --target run runUnitTest
ctest --test-dir buildNinja/Gnu -j8 --output-on-failure -D CMAKE_BUILD_TYPE=RelWithDebInfo

OR

cmake -S . -B buildNinja/Gnu -G Ninja -D linkGTestAsSharedLibrary=<ON/OFF> -D setCompiler=gnu -D CMAKE_BUILD_TYPE=MinSizeRel
cmake --build buildNinja/Gnu -j8 --target run runUnitTest
ctest --test-dir buildNinja/Gnu -j8 --output-on-failure -D CMAKE_BUILD_TYPE=MinSizeRel
```

### Ninja single-config, Clang (clang, clang++) compiler
```
cmake -S . -B buildNinja/Clang -G Ninja -D linkGTestAsSharedLibrary=<ON/OFF> -D setCompiler=clang -D CMAKE_BUILD_TYPE=Debug
cmake --build buildNinja/Clang -j8 --target run runUnitTest
ctest --test-dir buildNinja/Clang -j8 --output-on-failure -D CMAKE_BUILD_TYPE=Debug

OR

cmake -S . -B buildNinja/Clang -G Ninja -D linkGTestAsSharedLibrary=<ON/OFF> -D setCompiler=clang -D CMAKE_BUILD_TYPE=Release
cmake --build buildNinja/Clang -j8 --target run runUnitTest
ctest --test-dir buildNinja/Clang -j8 --output-on-failure -D CMAKE_BUILD_TYPE=Release

OR

cmake -S . -B buildNinja/Clang -G Ninja -D linkGTestAsSharedLibrary=<ON/OFF> -D setCompiler=clang -D CMAKE_BUILD_TYPE=RelWithDebInfo
cmake --build buildNinja/Clang -j8 --target run runUnitTest
ctest --test-dir buildNinja/Clang -j8 --output-on-failure -D CMAKE_BUILD_TYPE=RelWithDebInfo

OR

cmake -S . -B buildNinja/Clang -G Ninja -D linkGTestAsSharedLibrary=<ON/OFF> -D setCompiler=clang -D CMAKE_BUILD_TYPE=MinSizeRel
cmake --build buildNinja/Clang -j8 --target run runUnitTest
ctest --test-dir buildNinja/Clang -j8 --output-on-failure -D CMAKE_BUILD_TYPE=MinSizeRel
```

### Ninja multi-config, VS (cl.exe) compiler
```
cmake -S . -B buildNinjaMC/Msvc -G "Ninja Multi-Config" -D linkGTestAsSharedLibrary=<ON/OFF> -D setCompiler=msvc
cmake --build buildNinjaMC/Msvc -j8 --config Debug --target run runUnitTest
ctest --test-dir buildNinjaMC/Msvc -j8 --config Debug --output-on-failure

OR

cmake -S . -B buildNinjaMC/Msvc -G "Ninja Multi-Config" -D linkGTestAsSharedLibrary=<ON/OFF> -D setCompiler=msvc
cmake --build buildNinjaMC/Msvc -j8 --config Release --target run runUnitTest
ctest --test-dir buildNinjaMC/Msvc -j8 --config Release --output-on-failure

OR

cmake -S . -B buildNinjaMC/Msvc -G "Ninja Multi-Config" -D linkGTestAsSharedLibrary=<ON/OFF> -D setCompiler=msvc
cmake --build buildNinjaMC/Msvc -j8 --config RelWithDebInfo --target run runUnitTest
ctest --test-dir buildNinjaMC/Msvc -j8 --config RelWithDebInfo --output-on-failure

OR

cmake -S . -B buildNinjaMC/Msvc -G "Ninja Multi-Config" -D linkGTestAsSharedLibrary=<ON/OFF> -D setCompiler=msvc
cmake --build buildNinjaMC/Msvc -j8 --config MinSizeRel --target run runUnitTest
ctest --test-dir buildNinjaMC/Msvc -j8 --config MinSizeRel --output-on-failure
```

### Ninja multi-config, GNU (gcc, g++) compiler
```
cmake -S . -B buildNinjaMC/Gnu -G "Ninja Multi-Config" -D linkGTestAsSharedLibrary=<ON/OFF> -D setCompiler=gnu
cmake --build buildNinjaMC/Gnu -j8 --config Debug --target run runUnitTest
ctest --test-dir buildNinjaMC/Gnu -j8 --config Debug --output-on-failure

OR

cmake -S . -B buildNinjaMC/Gnu -G "Ninja Multi-Config" -D linkGTestAsSharedLibrary=<ON/OFF> -D setCompiler=gnu
cmake --build buildNinjaMC/Gnu -j8 --config Release --target run runUnitTest
ctest --test-dir buildNinjaMC/Gnu -j8 --config Release --output-on-failure

OR

cmake -S . -B buildNinjaMC/Gnu -G "Ninja Multi-Config" -D linkGTestAsSharedLibrary=<ON/OFF> -D setCompiler=gnu
cmake --build buildNinjaMC/Gnu -j8 --config RelWithDebInfo --target run runUnitTest
ctest --test-dir buildNinjaMC/Gnu -j8 --config RelWithDebInfo --output-on-failure

OR

cmake -S . -B buildNinjaMC/Gnu -G "Ninja Multi-Config" -D linkGTestAsSharedLibrary=<ON/OFF> -D setCompiler=gnu
cmake --build buildNinjaMC/Gnu -j8 --config MinSizeRel --target run runUnitTest
ctest --test-dir buildNinjaMC/Gnu -j8 --config MinSizeRel --output-on-failure
```

### Ninja multi-config, Clang (clang, clang++) compiler
```
cmake -S . -B buildNinjaMC/Clang -G "Ninja Multi-Config" -D linkGTestAsSharedLibrary=<ON/OFF> -D setCompiler=clang
cmake --build buildNinjaMC/Clang -j8 --config Debug --target run runUnitTest
ctest --test-dir buildNinjaMC/Clang -j8 --config Debug --output-on-failure

OR

cmake -S . -B buildNinjaMC/Clang -G "Ninja Multi-Config" -D linkGTestAsSharedLibrary=<ON/OFF> -D setCompiler=clang
cmake --build buildNinjaMC/Clang -j8 --config Release --target run runUnitTest
ctest --test-dir buildNinjaMC/Clang -j8 --config Release --output-on-failure

OR

cmake -S . -B buildNinjaMC/Clang -G "Ninja Multi-Config" -D linkGTestAsSharedLibrary=<ON/OFF> -D setCompiler=clang
cmake --build buildNinjaMC/Clang -j8 --config RelWithDebInfo --target run runUnitTest
ctest --test-dir buildNinjaMC/Clang -j8 --config RelWithDebInfo --output-on-failure

OR

cmake -S . -B buildNinjaMC/Clang -G "Ninja Multi-Config" -D linkGTestAsSharedLibrary=<ON/OFF> -D setCompiler=clang
cmake --build buildNinjaMC/Clang -j8 --config MinSizeRel --target run runUnitTest
ctest --test-dir buildNinjaMC/Clang -j8 --config MinSizeRel --output-on-failure
```

## CMake commands to configure, build, and run the program unit tests *with* CMakePresets.json

### Ninja single-config, VS (cl.exe) compiler
```
cmake --preset Ninja-Msvc-Debug -D linkGTestAsSharedLibrary=<ON/OFF>
cmake --build --preset Ninja-Msvc-Debug --target run runUnitTest
ctest --preset Ninja-Msvc-Debug --output-on-failure

OR

cmake --preset Ninja-Msvc-Release -D linkGTestAsSharedLibrary=<ON/OFF>
cmake --build --preset Ninja-Msvc-Release --target run runUnitTest
ctest --preset Ninja-Msvc-Release --output-on-failure

OR

cmake --preset Ninja-Msvc-RelWithDebInfo -D linkGTestAsSharedLibrary=<ON/OFF>
cmake --build --preset Ninja-Msvc-RelWithDebInfo --target run runUnitTest
ctest --preset Ninja-Msvc-RelWithDebInfo --output-on-failure

OR

cmake --preset Ninja-Msvc-MinSizeRel -D linkGTestAsSharedLibrary=<ON/OFF>
cmake --build --preset Ninja-Msvc-MinSizeRel --target run runUnitTest
ctest --preset Ninja-Msvc-MinSizeRel --output-on-failure
```

### Ninja single-config, GNU (gcc, g++) compiler
```
cmake --preset Ninja-Gnu-Debug -D linkGTestAsSharedLibrary=<ON/OFF>
cmake --build --preset Ninja-Gnu-Debug --target run runUnitTest
ctest --preset Ninja-Gnu-Debug --output-on-failure

OR

cmake --preset Ninja-Gnu-Release -D linkGTestAsSharedLibrary=<ON/OFF>
cmake --build --preset Ninja-Gnu-Release --target run runUnitTest
ctest --preset Ninja-Gnu-Release --output-on-failure

OR

cmake --preset Ninja-Gnu-RelWithDebInfo -D linkGTestAsSharedLibrary=<ON/OFF>
cmake --build --preset Ninja-Gnu-RelWithDebInfo --target run runUnitTest
ctest --preset Ninja-Gnu-RelWithDebInfo --output-on-failure

OR

cmake --preset Ninja-Gnu-MinSizeRel -D linkGTestAsSharedLibrary=<ON/OFF>
cmake --build --preset Ninja-Gnu-MinSizeRel --target run runUnitTest
ctest --preset Ninja-Gnu-MinSizeRel --output-on-failure
```

### Ninja single-config, Clang (clang, clang++) compiler
```
cmake --preset Ninja-Clang-Debug -D linkGTestAsSharedLibrary=<ON/OFF>
cmake --build --preset Ninja-Clang-Debug --target run runUnitTest
ctest --preset Ninja-Clang-Debug --output-on-failure

OR

cmake --preset Ninja-Clang-Release -D linkGTestAsSharedLibrary=<ON/OFF>
cmake --build --preset Ninja-Clang-Release --target run runUnitTest
ctest --preset Ninja-Clang-Release --output-on-failure

OR

cmake --preset Ninja-Clang-RelWithDebInfo -D linkGTestAsSharedLibrary=<ON/OFF>
cmake --build --preset Ninja-Clang-RelWithDebInfo --target run runUnitTest
ctest --preset Ninja-Clang-RelWithDebInfo --output-on-failure

OR

cmake --preset Ninja-Clang-MinSizeRel -D linkGTestAsSharedLibrary=<ON/OFF>
cmake --build --preset Ninja-Clang-MinSizeRel --target run runUnitTest
ctest --preset Ninja-Clang-MinSizeRel --output-on-failure
```

### Ninja multi-config, VS (cl.exe) compiler
```
cmake --preset NinjaMC-Msvc -D linkGTestAsSharedLibrary=<ON/OFF>

cmake --build --preset NinjaMC-Msvc --config Debug --target run runUnitTest
cmake --build --preset NinjaMC-Msvc --config Release --target run runUnitTest
cmake --build --preset NinjaMC-Msvc --config RelWithDebInfo --target run runUnitTest

ctest --preset NinjaMC-Msvc --config Debug --output-on-failure
ctest --preset NinjaMC-Msvc --config Release --output-on-failure
ctest --preset NinjaMC-Msvc --config RelWithDebInfo --output-on-failure
```

### Ninja multi-config, GNU (gcc, g++) compiler
```
cmake --preset NinjaMC-Gnu -D linkGTestAsSharedLibrary=<ON/OFF>

cmake --build --preset NinjaMC-Gnu --config Debug --target run runUnitTest
cmake --build --preset NinjaMC-Gnu --config Release --target run runUnitTest
cmake --build --preset NinjaMC-Gnu --config RelWithDebInfo --target run runUnitTest

ctest --preset NinjaMC-Gnu --config Debug --output-on-failure
ctest --preset NinjaMC-Gnu --config Release --output-on-failure
ctest --preset NinjaMC-Gnu --config RelWithDebInfo --output-on-failure
```

### Ninja multi-config, Clang (clang, clang++) compiler
```
cmake --preset NinjaMC-Clang -D linkGTestAsSharedLibrary=<ON/OFF>

cmake --build --preset NinjaMC-Clang --config Debug --target run runUnitTest
cmake --build --preset NinjaMC-Clang --config Release --target run runUnitTest
cmake --build --preset NinjaMC-Clang --config RelWithDebInfo --target run runUnitTest

ctest --preset NinjaMC-Clang --config Debug --output-on-failure
ctest --preset NinjaMC-Clang --config Release --output-on-failure
ctest --preset NinjaMC-Clang --config RelWithDebInfo --output-on-failure
```
