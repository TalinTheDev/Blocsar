// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#include <Kesar/app.hpp>
#include <Kesar/events.hpp>
#include <Kesar/kesar.hpp>
#include <Kesar/log.hpp>
#include <Kesar/window.hpp>

using namespace Kesar::log;
using namespace Kesar::keys;
using namespace Kesar::actions;

void keyCallback(Kesar::Window *window, int key, int action) {
  if (key == escape && action == press) {
    window->close();
  }
}

int main() {
  info("Blocsar initialized");
  info("Loaded Kesar v" + Kesar::version());

  Kesar::App app;

  app.onError(error);
  Kesar::Window *window = app.createWindow(1000, 800, "Blocsar");
  window->onKey(keyCallback);

  window->run([]() {}, []() {});

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
