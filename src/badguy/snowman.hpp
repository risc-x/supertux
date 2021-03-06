//  SuperTux
//  Copyright (C) 2010 Ingo Ruhnke <grumbel@gmail.com>
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

#ifndef HEADER_SUPERTUX_BADGUY_SNOWMAN_HPP
#define HEADER_SUPERTUX_BADGUY_SNOWMAN_HPP

#include "badguy/walking_badguy.hpp"

class Snowman final : public WalkingBadguy
{
public:
  Snowman(const ReaderMapping& reader);
  virtual std::string get_class() const override {
    return "snowman";
  }
  virtual std::string get_display_name() const override {
    return _("Snowman");
  }

protected:
  void loose_head();
  virtual HitResponse collision_bullet(Bullet& bullet, const CollisionHit& hit) override;
  virtual bool collision_squished(GameObject& object) override;

};

#endif

/* EOF */
