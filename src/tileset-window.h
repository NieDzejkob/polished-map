#ifndef TILESET_WINDOW_H
#define TILESET_WINDOW_H

#include <string>

#pragma warning(push, 0)
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#pragma warning(pop)

#include "tileset.h"
#include "map-buttons.h"
#include "palette-map.h"
#include "metatile.h"
#include "widgets.h"
#include "block-window.h"

#define PIXEL_ZOOM_FACTOR 18
#define ZOOMED_TILE_PX_SIZE (TILE_SIZE * PIXEL_ZOOM_FACTOR)

class Tileset_Window {
private:
	int _dx, _dy;
	const Tileset *_tileset;
	bool _canceled;
	Fl_Double_Window *_window;
	Label *_tileset_heading, *_tile_heading;
	Fl_Group *_tileset_group, *_tile_group;
	Deep_Tile_Button *_deep_tile_buttons[MAX_NUM_TILES], *_selected;
	Pixel *_pixels[TILE_SIZE * TILE_SIZE];
	Swatch *_swatch1, *_swatch2, *_swatch3, *_swatch4, *_chosen;
	Dropdown *_palette;
	OS_Check_Button *_priority;
	Default_Button *_ok_button;
	OS_Button *_cancel_button;
public:
	Tileset_Window(int x, int y);
	~Tileset_Window();
private:
	void initialize(void);
	void refresh(void);
public:
	void tileset(const Tileset *t);
	inline bool canceled(void) const { return _canceled; }
	inline void canceled(bool c) { _canceled = c; }
	void show(const Fl_Widget *p);
	void select(Deep_Tile_Button *dtb);
	void choose(Swatch *swatch);
	void flood_fill(Pixel *pxl, Hue f, Hue t);
	void substitute_hue(Hue f, Hue t);
	void palette(Palette p);
private:
	static void close_cb(Fl_Widget *w, Tileset_Window *tw);
	static void cancel_cb(Fl_Widget *w, Tileset_Window *tw);
	static void select_tile_cb(Deep_Tile_Button *dtb, Tileset_Window *tw);
	static void choose_swatch_cb(Swatch *s, Tileset_Window *tw);
	static void change_pixel_cb(Pixel *pxl, Tileset_Window *tw);
	static void change_palette_cb(Fl_Widget *wgt, Tileset_Window *tw);
};

#endif
