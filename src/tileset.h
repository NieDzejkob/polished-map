#ifndef TILESET_H
#define TILESET_H

#include <string>

#include "tile.h"
#include "palette-map.h"
#include "utils.h"

class Tileset {
public:
	enum Lighting { DAY, NITE, INDOOR };
	enum Result { GFX_OK, GFX_NO_PALETTE, GFX_BAD_FILE, GFX_BAD_EXT, GFX_BAD_DIMS,
		GFX_TOO_SHORT, GFX_TOO_LARGE, GFX_NOT_GRAYSCALE, GFX_BAD_CMD, GFX_NULL };
private:
	std::string _name;
	Palette_Map _palette_map;
	Tile *_tiles[MAX_NUM_TILES];
	size_t _num_tiles;
	Result _result;
public:
	Tileset();
	~Tileset();
	const char *name(void) const { return _name.c_str(); }
	void name(const char *name) { _name = name; }
	const Tile *tile(uint8_t i) const { return _tiles[i]; }
	size_t num_tiles(void) const { return _num_tiles; }
	Result result(void) const { return _result; }
	void clear(void);
	Palette_Map::Result read_palette_map(const char *f);
	Result read_graphics(const char *f, Lighting l, bool skip_60_7f = false);
	static const char *error_message(Result result);
};

#endif
