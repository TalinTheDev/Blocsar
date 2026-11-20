# Copyright (c) 2026 Talin Sharma
# SPDX-License-Identifier: MIT

cmake -S . -B build -G Ninja -DFETCHCONTENT_SOURCE_DIR_KESAR="../Kesar"
cmake --build build --parallel

if ($LASTEXITCODE -eq 0) {
    .\build\Blocsar.exe
}
