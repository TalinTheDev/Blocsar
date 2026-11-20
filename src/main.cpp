// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#include <kesar.hpp>
#include <log.hpp>

int main() {
  kesar::Log log;
  log.info("Blocsar initialized");
  log.info("Loaded Kesar v" + kesar::version());

  log.warn("Warn test");
  log.error("Error test");
  log.debug("Debug test");

  return 0;
}
