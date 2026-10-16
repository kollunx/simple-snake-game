#include "Renderer.h"
#include "Window.h"
#include <stdexcept>

Renderer::Renderer(Window &window) : m_window(window) {
  if (SDL_WasInit(SDL_INIT_VIDEO) != 0) {
  } else if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    throw std::runtime_error("Error: failed to initialize video in the 'Renderer.cpp' file!");
  }

  m_renderer = SDL_CreateRenderer(window.m_window, -1, 0);
}

void Renderer::setScreen(Screen screen) {
  hasScreen = true;
  m_screen = screen;
}

void Renderer::drawPoint(int x, int y) {
  if (hasScreen) {
    int widthMult = getWidthMultiplier();
    int heightMult = getHeightMultiplier();

    SDL_Rect rect{x * widthMult, y * heightMult, 1 * widthMult, 1 * heightMult};
    SDL_RenderFillRect(m_renderer, &rect);
    return;
  }

  SDL_RenderDrawPoint(m_renderer, x, y);
}

void Renderer::drawLine(int startX, int startY, int endX, int endY) {
  SDL_RenderDrawLine(m_renderer, startX, startY, endX, endY);
}

void Renderer::present() {
  SDL_RenderPresent(m_renderer);
}

void Renderer::clear() {
  SDL_RenderClear(m_renderer);
}

RGBA Renderer::getDrawColor() const noexcept {
  RGBA rgba{};
  SDL_GetRenderDrawColor(m_renderer, &rgba.r, &rgba.g, &rgba.b, &rgba.a);

  return rgba;
}

void Renderer::setDrawColor(RGBA color) {
  SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
}

Renderer::~Renderer() {
  SDL_DestroyRenderer(m_renderer);
}
