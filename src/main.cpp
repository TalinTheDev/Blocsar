// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#include "Kesar/transform.hpp"
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

float lastX = (float)WIDTH / 2.0f;
float lastY = (float)HEIGHT / 2.0f;
float xOffset = 0.0f;
float yOffset = 0.0f;
bool firstMove = true;
float mouseSensitivity = 0.1f;

void keyCallback(Kesar::Window *window, int key, int action) {
  if (action == press) {
    keyboardState[key] = true;
  } else if (action == release) {
    keyboardState[key] = false;
  }
}

void mouseCallback(Kesar::Window *window, float xPos, float yPos) {
  if (firstMove) {
    lastX = xPos;
    lastY = yPos;
    firstMove = false;
    return;
  }

  xOffset += (xPos - lastX) * mouseSensitivity;
  yOffset += (lastY - yPos) * mouseSensitivity;
  lastX = xPos;
  lastY = yPos;
}

int main() {
  info("Blocsar initialized");
  info("Loaded Kesar v" + Kesar::version());

  Kesar::App app;
  app.onError(error);

  Kesar::Window &window = app.createWindow(WIDTH, HEIGHT, "Blocsar");
  window.onKey(keyCallback);
  window.onMouse(mouseCallback);

  Kesar::Camera camera{};
  camera.setPosition({0.0f, 0.0f, 5.0f});
  camera.setRotation({0, 90, 0});
  camera.setSpeed(5);

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

  Kesar::Transform cubeT{
      {-1.0f, 1.0f, 0.0f}, {45.0f, 0.0f, 0.0f}, {2.0f, 1.0f, 1.0f}};
  Kesar::Transform triangleT{
      {1.0f, -1.0f, 0.0f}, {0.0f, 45.0f, 45.0f}, {1.0f, 1.0f, 2.0f}};

  window.run(
      [&]() {
        render.draw(cube, &cubeT);
        render.draw(triangle, &triangleT);
      },
      [&]() {
        if (keyboardState[escape])
          window.close();
        camera.updateFly(window.getDeltaTime(), keyboardState, xOffset,
                         yOffset);
        xOffset = 0.0f;
        yOffset = 0.0f;
      });

  return 0;
}
