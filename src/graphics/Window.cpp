#include "Window.h"
#include <stdexcept>
#include <string>

Window::Window(std::string_view title, int x, int y, int width, int height) : m_title(title) {
  if (SDL_WasInit(SDL_INIT_VIDEO) != 0) {
  } else if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    throw std::runtime_error("Error: failed to initialize video in the 'Window.cpp' file!");
  }

  m_window = SDL_CreateWindow(m_title.c_str(), x, y, width, height,
                              SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE); // TODO: It's resizable
}

void Window::maximize() {
  SDL_MaximizeWindow(m_window);
}

void Window::minimize() {
  SDL_MinimizeWindow(m_window);
}

void Window::focus() {
  SDL_RaiseWindow(m_window);
}

void Window::restore() {
  SDL_RestoreWindow(m_window);
}

void Window::show() {
  SDL_ShowWindow(m_window);
}

void Window::hide() {
  SDL_HideWindow(m_window);
}

int Window::getX() const noexcept {
  int x{};
  SDL_GetWindowPosition(m_window, &x, nullptr);
  return x;
}

int Window::getY() const noexcept {
  int y{};
  SDL_GetWindowPosition(m_window, nullptr, &y);

  return y;
}

int Window::getWidth() const noexcept {
  int w{};
  SDL_GetWindowSize(m_window, &w, nullptr);

  return w;
}

int Window::getHeight() const noexcept {
  int h{};
  SDL_GetWindowSize(m_window, nullptr, &h);

  return h;
}

void Window::setTitle(std::string_view title) {
  m_title = title;

  SDL_SetWindowTitle(m_window, m_title.c_str());
}

void Window::setPosition(int x, int y) {
  SDL_SetWindowPosition(m_window, x, y);
}

void Window::setX(int x) {
  setPosition(x, getY());
}

void Window::setY(int y) {
  setPosition(getX(), y);
}

void Window::setSize(int width, int height) {
  SDL_SetWindowSize(m_window, width, height);
}

void Window::setWidth(int width) {
  setSize(width, getHeight());
}

void Window::setHeight(int height) {
  setSize(getWidth(), height);
}

void Window::setFullscreen() {
  SDL_SetWindowFullscreen(m_window, SDL_WINDOW_FULLSCREEN);
}

void Window::setFullscreenDesktop() {
  SDL_SetWindowFullscreen(m_window, SDL_WINDOW_FULLSCREEN_DESKTOP);
}

void Window::setWindowed() {
  SDL_SetWindowFullscreen(m_window, 0);
}

void Window::setGrab(bool grabbed) {
  SDL_SetWindowGrab(m_window, static_cast<SDL_bool>(grabbed));
}

void Window::setKeyboardGrab(bool grabbed) {
  SDL_SetWindowKeyboardGrab(m_window, static_cast<SDL_bool>(grabbed));
}

void Window::setMouseGrab(bool grabbed) {
  SDL_SetWindowMouseGrab(m_window, static_cast<SDL_bool>(grabbed));
}

bool Window::isGrabbed() {
  return SDL_GetWindowGrab(m_window);
}

bool Window::isKeyboardGrabbed() {
  return SDL_GetWindowKeyboardGrab(m_window);
}

bool Window::isMouseGrabbed() {
  return SDL_GetWindowMouseGrab(m_window);
}

Window::~Window() {
  SDL_DestroyWindow(m_window);
}
