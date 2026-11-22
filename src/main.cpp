// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#include "Kesar/mesh.hpp"
#include <Kesar/app.hpp>
#include <Kesar/events.hpp>
#include <Kesar/kesar.hpp>
#include <Kesar/log.hpp>
#include <Kesar/renderer.hpp>
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

  Kesar::Window &window = app.createWindow(1000, 800, "Blocsar");
  window.onKey(keyCallback);

  const Kesar::Renderer &render =
      window.getRenderer(Kesar::Color{1.0f, 1.0f, 1.0f, 1.0f});

  Kesar::Mesh triangle;
  triangle.vertices(
      {{0.0f, 0.5f, 0.0f}, {-0.5f, -0.5f, 0.0f}, {0.5f, -0.5f, 0.0f}});

  window.run([&render, &triangle]() { render.draw(triangle); }, []() {});

  return 0;
}
