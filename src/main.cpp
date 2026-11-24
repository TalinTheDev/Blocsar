// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#include "Kesar/types.hpp"
#include <Kesar/app.hpp>
#include <Kesar/events.hpp>
#include <Kesar/kesar.hpp>
#include <Kesar/log.hpp>
#include <Kesar/mesh.hpp>
#include <Kesar/renderer.hpp>
#include <Kesar/window.hpp>

using namespace Kesar::log;
using namespace Kesar::keys;
using namespace Kesar::actions;

Kesar::Vector3 cameraPos = {0.0f, 0.0f, 3.0f};

void keyCallback(Kesar::Window *window, int key, int action) {
  if (key == escape && action == press) {
    window->close();
  }
  if (key == w && action == press) {
    cameraPos.z -= 0.1;
  }
  if (key == s && action == press) {
    cameraPos.z += 0.1;
  }
  if (key == a && action == press) {
    cameraPos.x -= 0.1;
  }
  if (key == d && action == press) {
    cameraPos.x += 0.1;
  }
}

int main() {
  info("Blocsar initialized");
  info("Loaded Kesar v" + Kesar::version());

  Kesar::App app;
  app.onError(error);

  Kesar::Window &window = app.createWindow(1000, 800, "Blocsar");
  window.onKey(keyCallback);

  Kesar::Camera camera{};
  camera.setPosition(cameraPos);
  camera.setTarget({0.0f, 0.0f, 0.0f});

  camera.perspective(60, 1000.0f / 800.0f, 0.1, 10);
  Kesar::Renderer &render =
      window.getRenderer(Kesar::Color{1.0f, 1.0f, 1.0f, 1.0f});

  render.setCamera(camera);

  Kesar::Mesh triangle;
  triangle.vertices(
      {{0.0f, 0.5f, 0.0f}, {-0.5f, -0.5f, 0.0f}, {0.5f, -0.5f, 0.0f}});

  triangle.colors({{1.0f, 0.0f, 0.0f, 1.0f},
                   {0.0f, 1.0f, 0.0f, 1.0f},
                   {0.0f, 0.0f, 1.0f, 1.0f}});

  window.run([&render, &triangle]() { render.draw(triangle); },
             [&camera]() { camera.setPosition(cameraPos); });

  return 0;
}
