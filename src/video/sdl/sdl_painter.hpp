//  SuperTux
//  Copyright (C) 2014 Ingo Ruhnke <grumbel@gmail.com>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef HEADER_SUPERTUX_VIDEO_SDL_PAINTER_HPP
#define HEADER_SUPERTUX_VIDEO_SDL_PAINTER_HPP

#include "video/painter.hpp"

class SDLVideoSystem;
struct DrawingRequest;
struct SDL_Renderer;

class SDLPainter : public Painter
{
public:
  SDLPainter(SDLVideoSystem& video_system, SDL_Renderer* renderer);

  virtual void draw_texture(const DrawingRequest& request) override;
  virtual void draw_texture_batch(const DrawingRequest& request) override;
  virtual void draw_gradient(const DrawingRequest& request) override;
  virtual void draw_filled_rect(const DrawingRequest& request) override;
  virtual void draw_inverse_ellipse(const DrawingRequest& request) override;
  virtual void draw_line(const DrawingRequest& request) override;
  virtual void draw_triangle(const DrawingRequest& request) override;

private:
  SDLVideoSystem& m_video_system;
  SDL_Renderer* m_renderer;

private:
  SDLPainter(const SDLPainter&);
  SDLPainter& operator=(const SDLPainter&);
};

#endif

/* EOF */