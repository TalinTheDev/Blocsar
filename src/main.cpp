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

std::unordered_map<unsigned int, bool> keyboardState{};
const int WIDTH = 1000;
const int HEIGHT = 800;

void keyCallback(Kesar::Window *window, int key, int action) {
  if (action == press) {
    keyboardState[key] = true;
  } else if (action == release) {
    keyboardState[key] = false;
  }
}

int main() {
  info("Blocsar initialized");
  info("Loaded Kesar v" + Kesar::version());

  Kesar::App app;
  app.onError(error);

  Kesar::Window &window = app.createWindow(WIDTH, HEIGHT, "Blocsar");
  window.onKey(keyCallback);

  Kesar::Camera camera{};
  camera.setPosition({0.0f, 0.0f, 3.0f});
  camera.setRotation({0, 90, 0});
  camera.setSpeed(0.05);

  camera.perspective(45, (float)WIDTH / (float)HEIGHT, 0.01, 100);
  Kesar::Renderer &render =
      window.getRenderer(Kesar::Color{1.0f, 1.0f, 1.0f, 1.0f});

  render.setCamera(camera);

  Kesar::Mesh triangle;
  triangle.vertices(
      {{0.0f, 0.5f, 0.0f}, {-0.5f, -0.5f, 0.0f}, {0.5f, -0.5f, 0.0f}});

  triangle.colors({{1.0f, 0.0f, 0.0f, 1.0f},
                   {0.0f, 1.0f, 0.0f, 1.0f},
                   {0.0f, 0.0f, 1.0f, 1.0f}});

  Kesar::Mesh cube;
  cube.vertices({{-0.5f, 0.5f, -0.5f},
                 {-0.5f, 0.5f, 0.5f},
                 {0.5f, 0.5f, 0.5f},
                 {0.5f, 0.5f, -0.5f},
                 {0.5f, -0.5f, -0.5f},
                 {0.5f, -0.5f, 0.5f},
                 {-0.5f, -0.5f, 0.5f},
                 {-0.5f, -0.5f, -0.5f}});
  cube.indices({0, 1, 2, 2, 3, 0, 0, 7, 4, 4, 3, 0, 0, 7, 6,
                6, 1, 0, 3, 2, 5, 5, 4, 3, 5, 4, 6, 6, 7, 4});

  window.run([&render, &cube]() { render.draw(cube); },
             [&camera, &window, &app]() {
               if (keyboardState[escape])
                 window.close();
               camera.updateFly(app.deltaTime(), keyboardState);
             });

  return 0;
}
