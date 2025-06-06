#include <SDL.h>

extern SDL_Surface *plat_sdl_screen;
extern SDL_Overlay *plat_sdl_overlay;
extern int plat_sdl_gl_active;
extern void (*plat_sdl_resize_cb)(int w, int h);
extern void (*plat_sdl_quit_cb)(void);
extern int plat_sdl_no_overlay2x;

int plat_sdl_init(void);
int plat_sdl_is_windowed(void);
int plat_sdl_is_fullscreen(void);
int plat_sdl_change_video_mode(int w, int h, int force);
void plat_sdl_overlay_clear(void);
void plat_sdl_event_handler(void *event_);
void plat_sdl_gl_scaling(int type);
void plat_sdl_gl_vsync(int on);
void plat_sdl_finish(void);
