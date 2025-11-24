@echo off
REM CI helper script for Windows (cmd)
REM Steps:
REM 1. mkdir build
REM 2. cd build
REM 3. cmake ..
REM 4. cmake --build .
REM 5. ctest

echo [ci.bat] Starting CI script

if not exist build (
    mkdir build
)

cd build
if errorlevel 1 exit /b 1

echo [ci.bat] Configuring project with CMake
cmake .. -DCMAKE_BUILD_TYPE=Release
if errorlevel 1 exit /b 1

echo [ci.bat] Building project
cmake --build . --config Release
if errorlevel 1 exit /b 1

echo [ci.bat] Running tests (ctest)
ctest --output-on-failure
if errorlevel 1 (
    echo [ci.bat] Some tests failed
    exit /b 1
)

echo [ci.bat] CI script finished successfully
