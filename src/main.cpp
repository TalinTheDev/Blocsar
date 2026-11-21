// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#include <Kesar/kesar.hpp>
#include <Kesar/log.hpp>

using namespace Kesar::log;

int main() {
  info("Blocsar initialized");
  info("Loaded Kesar v" + Kesar::version());

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
