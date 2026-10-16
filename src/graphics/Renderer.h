#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>

#include "Types.h"
#include "Window.h"

class Window;

struct Screen {
  int width{};
  int height{};
};

class Renderer {
public:
  explicit Renderer(Window &window);
  ~Renderer();

  Renderer(const Renderer &) = delete;
  Renderer(Renderer &&) = delete;
  Renderer &operator=(const Renderer &) = delete;
  Renderer &operator=(Renderer &&) = delete;

  void setScreen(Screen screen);
  void drawPoint(int x, int y);
  void drawLine(int startX, int startY, int endX, int endY);
  void present();
  void clear();

  [[nodiscard]] RGBA getDrawColor() const noexcept;
  SDL_Renderer *getRawRenderer() noexcept { return m_renderer; }

  void setDrawColor(RGBA color);
  void removeScreen() noexcept { hasScreen = false; }

private:
  SDL_Renderer *m_renderer{nullptr};
  Window &m_window;
  Screen m_screen{};
  bool hasScreen{};

  int getWidthMultiplier() { return m_window.getWidth() / m_screen.width; }
  int getHeightMultiplier() { return m_window.getHeight() / m_screen.height; }
};

#endif
