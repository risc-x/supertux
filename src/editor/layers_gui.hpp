//  SuperTux
//  Copyright (C) 2015 Hume2 <teratux.mail@gmail.com>
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

#ifndef HEADER_SUPERTUX_EDITOR_LAYERS_GUI_HPP
#define HEADER_SUPERTUX_EDITOR_LAYERS_GUI_HPP

#include <stdexcept>

#include "control/input_manager.hpp"
#include "supertux/screen.hpp"

class LayerIcon;
class GameObject;
class Vector;
class Tip;
class DrawingContext;

class EditorLayersGui final
{
  public:
    EditorLayersGui();

    void draw(DrawingContext&);
    void update(float elapsed_time);
    bool event(SDL_Event& ev);
    void setup();
    void resize();

    void refresh_sector_text();
    void sort_layers();

    std::vector<std::unique_ptr<LayerIcon>> layers;
    void add_layer(GameObject* layer);

    GameObject *selected_tilemap;

  private:
    int Ypos;
    const int Xpos = 32;
    int Width;

    std::string sector_text;
    int sector_text_width;

    Vector get_layer_coords(const int pos) const;
    int get_layer_pos(const Vector& coords) const;
    void update_tip();

    static bool less_z_pos(const std::unique_ptr<LayerIcon>& lhs, const std::unique_ptr<LayerIcon>& rhs);

    typedef enum {
      HI_NONE, HI_SPAWNPOINTS, HI_SECTOR, HI_LAYERS
    }HoveredItem;

    HoveredItem hovered_item;
    unsigned int hovered_layer;

    std::unique_ptr<Tip> object_tip;

    EditorLayersGui(const EditorLayersGui&);
    EditorLayersGui& operator=(const EditorLayersGui&);
};

#endif // HEADER_SUPERTUX_EDITOR_LAYERS_GUI_HPP

/* EOF */
