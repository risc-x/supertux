//  SuperTux - Boss "GhostTree"
//  Copyright (C) 2007 Matthias Braun <matze@braunis.de>
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

#ifndef HEADER_SUPERTUX_BADGUY_GHOSTTREE_HPP
#define HEADER_SUPERTUX_BADGUY_GHOSTTREE_HPP

#include "badguy/badguy.hpp"

class TreeWillOWisp;
class Lantern;

class GhostTree final : public BadGuy
{
public:
  GhostTree(const ReaderMapping& lisp);

  virtual bool is_flammable() const override { return false; }
  virtual bool is_freezable() const override { return false; }
  virtual void kill_fall() override { }

  virtual void activate() override;
  virtual void active_update(float elapsed_time) override;
  void willowisp_died(TreeWillOWisp* willowisp);
  virtual void draw(DrawingContext& context) override;

  virtual bool collides(GameObject& other, const CollisionHit& hit) const override;
  virtual HitResponse collision(GameObject& other, const CollisionHit& hit) override;

  void die();
  virtual std::string get_class() const override {
    return "ghosttree";
  }
  virtual std::string get_display_name() const override {
    return _("Ghost tree");
  }

private:
  enum MyState {
    STATE_IDLE, STATE_SUCKING, STATE_SWALLOWING, STATE_DYING
  };
  MyState mystate;
  Timer willowisp_timer;
  float willo_spawn_y;
  float willo_radius;
  float willo_speed;
  int   willo_color;

  SpritePtr glow_sprite;
  Timer colorchange_timer;
  Timer suck_timer;
  Timer root_timer;
  int   treecolor;
  Color suck_lantern_color;

  Lantern* suck_lantern; /**< Lantern that is currently being sucked in */

  std::vector<std::shared_ptr<TreeWillOWisp> > willowisps;

  bool is_color_deadly(Color color) const;
  void spawn_lantern();

private:
  GhostTree(const GhostTree&);
  GhostTree& operator=(const GhostTree&);
};

#endif

/* EOF */
