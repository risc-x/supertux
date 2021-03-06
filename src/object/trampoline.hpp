//  SuperTux - Trampoline
//  Copyright (C) 2006 Wolfgang Becker <uafr@gmx.de>
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

#ifndef HEADER_SUPERTUX_OBJECT_TRAMPOLINE_HPP
#define HEADER_SUPERTUX_OBJECT_TRAMPOLINE_HPP

#include "object/rock.hpp"

/**
 * Jumping on a trampoline makes tux jump higher.
 */
class Trampoline final : public Rock
{
public:
  Trampoline(const ReaderMapping& reader);
  Trampoline(const Vector& pos, bool port);

  virtual HitResponse collision(GameObject& other, const CollisionHit& hit) override;
  virtual void update(float elapsed_time) override;

  virtual void grab(MovingObject&, const Vector& pos, Direction) override;
  virtual bool is_portable() const override;
  virtual std::string get_class() const override {
    return "trampoline";
  }
  virtual std::string get_display_name() const override {
    return _("Trampoline");
  }

  virtual ObjectSettings get_settings() override;

private:
  bool portable;

};

#endif

/* EOF */
