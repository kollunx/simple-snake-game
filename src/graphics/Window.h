#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <string>
#include <string_view>

class Window {
public:
  Window(std::string_view title, int x, int y, int width, int height);

  Window(const Window &) = delete;
  Window(Window &&) = delete;
  Window &operator=(const Window &) = delete;
  Window &operator=(Window &&) = delete;

  virtual ~Window();

  void maximize();
  void minimize();
  void focus();
  void restore();
  void show();
  void hide();

  std::string_view getTitle() const noexcept {
    return m_title;
  } // TODO: data type should be changed
  int getX() const noexcept;
  int getY() const noexcept;
  int getWidth() const noexcept;
  int getHeight() const noexcept;

  void setTitle(std::string_view title);
  void setPosition(int x, int y);
  void setX(int x);
  void setY(int y);
  void setSize(int width, int height);
  void setWidth(int width);
  void setHeight(int height);
  void setFullscreen();
  void setFullscreenDesktop();
  void setWindowed();
  void setGrab(bool grabbed);
  void setKeyboardGrab(bool grabbed);
  void setMouseGrab(bool grabbed);

  bool isGrabbed();
  bool isKeyboardGrabbed();
  bool isMouseGrabbed();

private:
  SDL_Window *m_window{nullptr};
  std::string m_title;

  friend class Renderer;
};

#endif
