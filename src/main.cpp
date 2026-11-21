// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#include <Kesar/kesar.hpp>
#include <Kesar/log.hpp>

int main() {
  kesar::Log log;
  log.info("Blocsar initialized");
  log.info("Loaded Kesar v" + kesar::version());

  return 0;
}

/*
 * kesar::App app()
 * kesar::Window* window = app.createWindow(width, height, title):
 *
 * void runWindowA(){ // do window rendering stuff }
 *
 * window->run(runWindowA);
 *
 */
