//  SuperTux
//  Copyright (C) 2006 Matthias Braun <matze@braunis.de>
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

#ifndef HEADER_SUPERTUX_OBJECT_CAMERA_HPP
#define HEADER_SUPERTUX_OBJECT_CAMERA_HPP

#include <memory>
#include <string>

#include "math/size.hpp"
#include "math/vector.hpp"
#include "object/path_object.hpp"
#include "scripting/camera.hpp"
#include "scripting/exposed_object.hpp"
#include "supertux/game_object.hpp"
#include "supertux/timer.hpp"

class Sector;
class Path;
class PathWalker;
class ReaderMapping;
class CameraConfig;

class Camera final : public GameObject,
                     public ExposedObject<Camera, scripting::Camera>,
                     public PathObject
{
public:
  enum CameraMode
  {
    NORMAL, MANUAL, AUTOSCROLL, SCROLLTO
  };

private:
  /** The camera basically provides lookahead on the left or right
      side or is undecided. */
  enum LookaheadMode {
    LOOKAHEAD_NONE, LOOKAHEAD_LEFT, LOOKAHEAD_RIGHT
  };

public:
  Camera(Sector* sector, const std::string& name = std::string());
  virtual ~Camera();

  /** \addtogroup CameraAPI
   *  @{ */

  /** parse camera mode from lisp file */
  void parse(const ReaderMapping& reader);

  /** reset camera position */
  void reset(const Vector& tuxpos);

  /** return camera position */
  const Vector& get_translation() const;

  /** shake camera in a direction 1 time */
  void shake(float speed, float x, float y);

  void set_scrolling(int scroll_x, int scroll_y)
  {
    m_translation.x = static_cast<float>(scroll_x);
    m_translation.y = static_cast<float>(scroll_y);
  }

  /** scroll the upper left edge of the camera in scrolltime seconds
      to the position goal */
  void scroll_to(const Vector& goal, float scrolltime);
  void move(const int dx, const int dy);

  void reload_config();

  /** get the coordinates of the point directly in the center of this
      camera */
  Vector get_center() const;

  void set_mode(CameraMode mode_) { m_mode = mode_; }
  /** @} */

  /** \addtogroup GameObject
      @{ */

  virtual void update(float elapsed_time) override;
  virtual void draw(DrawingContext& ) override;

  virtual bool is_saveable() const override;
  virtual void save(Writer& writer) override;

  virtual std::string get_class() const override {
    return "camera";
  }
  virtual std::string get_display_name() const override {
    return _("Camera");
  }

  virtual ObjectSettings get_settings() override;
  virtual void after_editor_set() override;

  virtual const std::string get_icon_path() const override {
    return "images/engine/editor/camera.png";
  }

  /** @} */

private:
  void update_scroll_normal(float elapsed_time);
  void update_scroll_autoscroll(float elapsed_time);
  void update_scroll_to(float elapsed_time);
  void keep_in_bounds(Vector& vector);
  void shake();

private:
  CameraMode m_mode;
  CameraMode m_defaultmode;

  Size m_screen_size;

  Vector m_translation;

  Sector* m_sector;

  // normal mode
  LookaheadMode m_lookahead_mode;
  float m_changetime;
  Vector m_lookahead_pos;
  Vector m_peek_pos;
  Vector m_cached_translation;

  // shaking
  Timer m_shaketimer;
  float m_shakespeed;
  float m_shakedepth_x;
  float m_shakedepth_y;

  // scrollto mode
  Vector m_scroll_from;
  Vector m_scroll_goal;
  float m_scroll_to_pos;
  float m_scrollspeed;

  std::unique_ptr<CameraConfig> m_config;

private:
  Camera(const Camera&) = delete;
  Camera& operator=(const Camera&) = delete;
};

#endif

/* EOF */
