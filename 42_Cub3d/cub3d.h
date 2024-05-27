/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:24:59 by lpeeters          #+#    #+#             */
/*   Updated: 2024/05/22 22:16:59 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* LIBRARIES */

# include "libft/libft.h"       //Custom library functions
# include "mlx_linux/mlx.h"     //Minilibx library functions (Linux)
# include "mlx_linux/mlx_int.h" //X data struct
# include "mlx_macos/mlx.h"     //Minilibx library functions (MacOS)
# include <X11/X.h>             //mask and event macros
# include <X11/Xlib.h>          //XFlush, X threading
# include <X11/Xlibint.h>       //X threading
# include <errno.h>             //errno
# include <fcntl.h>             //open
# include <math.h>              //cos, sin, tan
# include <pthread.h>           //pthread and mutex
# include <stdarg.h>            //va_list, va_start
# include <stdbool.h>           //bool
# include <stdio.h>             //printf, perror
# include <string.h>            //strerror
# include <sys/stat.h>          //open macros

/* MACROS */

# define SUCCESS 0
# define FAILURE 1

// Grid size
# define GRID_SIZE 32

// one degree in radians
# define ONE_DEGREE 0.0174532925

// Screen width
# define SCREEN_WIDTH 1080

// Screen Height
# define SCREEN_HEIGHT 720

// Scale Factor for height of walls
# define SCALE_FACTOR 0.05

// Size of the textures to load
# define TEXTURE_SIZE 128

// Minimum mouse movement before register (can be used as sensitivity)
# define MOUSE_MOVE_THRESHOLD 25

/* KEY CODES */

# define ESCAPE 65307
# define M 109
# define UP 65362
# define W 119
# define LEFT 65361
# define A 97
# define DOWN 65364
# define S 115
# define RIGHT 65363
# define D 100
# define I 105
# define E 101
# define Q 113
# define R 114
# define F 102
# define ALT 65513
# define SPACE 32

/* DATA STRUCTURES */

// Types Of Objects
typedef enum e_obstacles
{
	OUT_OF_BOUNDS,
	AIR,
	WALL,
	DOOR,
	OPEN_DOOR,
	PISTOL_BUY,
	SHOTGUN_BUY,
	AR_BUY,
	ENEMY,
}	t_obstacles;

// Directions raycaster can hit
typedef enum e_directions
{
	NORTH,
	EAST,
	SOUTH,
	WEST,
}	t_axis;

// ID's for the weapons (easy for checks)
typedef enum e_weapons
{
	TESTING,
	PISTOL,
	SHOTGUN,
	AR,
}	t_weapons;

// Minimap Drawing Struct
typedef struct s_mini_drawer
{
	int		x;
	int		y;
	double	sx;
	double	sy;
	int		center;
	int		sampler_f;
	int		sampler_s;
	int		relative_x;
	int		relative_y;
	int		rot_x;
	int		rot_y;
	int		screen_x;
	int		screen_y;
}			t_mini_drawer;

// Player Data Struct
typedef struct s_player_drawer
{
	int		center;
	int		x;
	int		y;
	void	*img;
	int		img_width;
	int		img_height;
	char	*texture_path;
	int		bpp;
	int		size_line;
	int		endian;
	char	*img_data;
	int		color;
}			t_player_drawer;

// Raycast data structure
typedef struct s_ray_data
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	bool	hit;
	int		hit_object;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		wall_dir;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
	int		hit_x;
	int		hit_y;
}			t_ray_data;

// Collision Data Struct
typedef struct s_collision_data
{
	int	top_left_x;
	int	top_left_y;
	int	top_right_x;
	int	top_right_y;
	int	bottom_left_x;
	int	bottom_left_y;
	int	bottom_right_x;
	int	bottom_right_y;
	int	collision_box_size;
	int	x_offset;
	int	y_offset;
}		t_coll_data;

typedef struct s_bg_remover_data
{
	void	*img;
	char	*data;
	int		x;
	int		y;
	int		bpp;
	int		size_line;
	int		endian;
	int		color;
	int		i;
	int		j;
}			t_bg_remover;

// Weapon Data Struct
typedef struct s_weapon_data
{
	char				*name;
	int					range;
	int					damage;
	int					max_ammo;
	int					ammo;
	int					player_ammo;
	int					max_player_ammo;
	int					auto_speed;
	float				walk_speed;
	float				reload_speed;
	bool				full_auto;
	int					weapon_id;
	bool				reloading;
	pthread_mutex_t		lock;
}						t_weapon_data;

// Player Data Structure
typedef struct s_player_data
{
	double			posx;
	double			posy;
	double			deltax;
	double			deltay;
	double			newy;
	double			newx;
	double			playerangle;
	double			movespeed;
	int				minimap_size;
	int				fov;
	t_coll_data		coll_data;
	t_weapon_data	weapon_data;
	bool			in_range_door;
	int				points;
}					t_player_data;

// MiniMap Data Structure
typedef struct s_minimap
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				radius;
	int				img_size;
	t_player_data	*player;
	char			**map;
	int				map_x;
	int				map_y;
}					t_minimap;

// Map position data strucutre
typedef struct s_pos
{
	int					y;
	int					x;
	bool				bought;
}						t_pos;

// Map optimiser data structure
typedef struct s_opt
{
	int	ya;
	int	yz;
	int	xa;
	int	xz;
}		t_opt;

// Scene data structure
typedef struct s_scene
{
	char	**nt_path;
	char	**et_path;
	char	**st_path;
	char	**wt_path;
	char	**dt_path;
	char	**ot_path;
	char	**tt_path;
	char	**zt_path;
	char	**c_clr;
	char	**f_clr;
	int		*c;
	int		*f;
	char	**map;
	t_opt	*opt;
	char	**opt_map;
	int		height;
	int		width;
	t_pos	**dpos;
	t_pos	**zpos;
	int		oy;
	int		ox;
	int		ty;
	int		tx;
	int		dy;
	int		dx;
	int		zy;
	int		zx;
	int		py;
	int		px;
	char	d;
}			t_scene;

typedef struct s_single_texture
{
	int		id;
	void	*text_img;
	char	*data;
	int		x;
	int		y;
	int		bpp;
	int		size_line;
	int		endian;
	int		color;
}			t_single_texture;

typedef struct s_textures
{
	t_single_texture	pistol_text[25];
	t_single_texture	shotgun_text[25];
	t_single_texture	ar_text[25];
	t_single_texture	weapon_ui[3];
	t_single_texture	crosshairs[2];
	t_single_texture	font[10];
	t_single_texture	money_font[11];
	int					tex_size;
	int					ui_size;
	int					crosshair_size;
	int					money_font_size;
	int					font_size;
}						t_textures;

// MLX data structure
typedef struct s_mlx
{
	void				*ptr;
	void				*win;
	void				*nt;
	void				*et;
	void				*st;
	void				*wt;
	void				*dt;
	void				*ot;
	void				*tt;
	void				*zt;
	char				*addr;
	char				*weapon_addr;
	char				*ui_addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					wall_color;
	int					size;
	void				*img;
	void				*weapon_img;
	void				*ui_img;
	bool				reloading_anim_running;
	t_minimap			*map;
	t_scene				scene;
	t_textures			weapon_textures;
	pthread_mutex_t		lock;
	bool				alt_mode;
}						t_mlx;

/* FUNCTIONS */

/***************************/
/*         cub3d.c         */
/***************************/

// Parse scene, handle errors, convert into an interactive 3D video game
int		main(int ac, char **av);

/**************************/
/*      exit/error.c      */
/**************************/

// Print error messages
int		prnt_err(char *str);

// Loop through gnl to clean the buffer
void	clean_gnl(char *line, int fd);

// Clean positions
void	clean_arr(void **ptr);

// Handle resources when an error occured
void	clean_scene(t_scene *scene);

/**************************/
/* parser/scene_checker.c */
/**************************/

// Master scene handler
int		scene_handler(char *file_name, t_scene *scene, t_mlx *mlx);

/****************************/
/* parser/texture_checker.c */
/****************************/

// Convert textures into mlx images
int		fetch_textures(t_scene *scene, t_mlx *mlx, int *size);

// Store texture paths
void	fetch_texture_paths(char *line, t_scene *scene, bool *error);

/**************************/
/* parser/color_checker.c */
/**************************/

// Validate the colors given with the ceiling or floor
int		check_colors(char *arg);

// Check ceiling and floor color data
int		fetch_colors(char *line, t_scene *scene, bool *error);

// Convert colors into int array
int		convert_rgb(char **clr_in, int **clr_out);

/**************************/
/*  parser/map_checker.c  */
/**************************/

// Fetch player position
int		get_player_position(char **map, int *y, int *x);

// Master map algorithm
int		map_algo(t_mlx *mlx, t_scene *scene, char **map);

// Master map handler
int		map_handler(char *line, int fd, t_scene *scene);

/****************************/
/* parser/fetch_positions.c */
/****************************/

// Fetch object positions
int		get_positions(t_mlx *mlx, t_scene *s, int *y, int *x);

// Check if a character is unreachable
int		check_sur(char **map, int y, int x);

/***************************/
/*  parser/optimize_map.c  */
/***************************/

// Reconstruct the map out of only what can be reached
int		opt_map(t_mlx *mlx, t_scene *scene, t_opt *opt);

/**************************/
/*    minimap/drawer.c    */
/**************************/

// Sets the player location and starting angle
int		find_player(char **map, t_player_data *player);

// Draw player on the minimap
void	draw_player(t_minimap *map, t_mlx *mlx);

// Update walls on minimap
void	update_walls(t_minimap *map, t_mlx *mlx);

/**************************/
/*   minimap/checkers.c   */
/**************************/

// Check if point is inside minimap
bool	in_minimap(int x, int y, t_minimap *map);

// Check what object is on a certain position
int		obj_check(double x, double y, t_minimap *mini);

/**************************/
/*      logic/init.c      */
/**************************/

// Initialize position values
void	init_pos(t_scene *scene);

// Initialize player and minimap data (mostly)
void	init_data(t_player_data *player, t_minimap *map, t_mlx *mlx);

// Initialize new optimized map
int		init_opt_map(t_scene *scene);

// Initialization of an image array
void	init_img_arr(t_single_texture *arr, short n);

/**************************/
/*      logic/info.c      */
/**************************/

// Print the map
void	prnt_map(char **map);

// Print the scene
void	prnt_scene(t_scene *scene);

// Print locations
void	prnt_pos(t_pos **pos, char id);

// Print basic info (playerAngle, position player, ...)
void	print_debug(t_mlx *mlx);

/**************************/
/*    logic/movement.c    */
/**************************/

// Function that makes the player turn left and right
void	rotate_player(t_player_data *player, int direction);

// Move the player either up, down, left or right
void	move_dir(t_player_data *player, int direction);

// Move the player after keypress
int		move(t_mlx *mlx, t_minimap *map, t_player_data *player, int direction);

/**************************/
/*   logic/collisions.c   */
/**************************/

// calculate offsets for the collision box
void	calculate_offsets(t_player_data *player);

// calculate corners of the collision box around player
void	calculate_corners(t_coll_data *coll_data, int posX, int posY);

// check if there is a collision
int		is_collision(t_minimap *map, t_coll_data *coll_data);

/**************************/
/*     logic/events.c     */
/**************************/

// Exit in a clean way
int		close_window(t_mlx *mlx, int status);

// Defines what happens when certain keys are pressed
int		key_event(int keycode, t_mlx *mlx);

/**************************/
/*    bonus/shooting.c    */
/**************************/

// mouse hooks for clicking event
int		shoot_hook(int mouse_code, int x, int y, t_mlx *mlx);

// Reload weapon when mag empty or R pressed
void	*reload_weapon_thread(void *arg);

// Shoots out just one ray
float	single_ray(t_player_data *p, char **m, t_ray_data *d, bool s);

/**************************/
/* logic/drawer_helpers.c */
/**************************/

// my pixel put main image
void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);

// pixel put on weapon
void	my_mlx_pixel_put_weapon(t_mlx *data, int x, int y, int color);

// pixel put on UI image
void	my_mlx_pixel_put_ui(t_mlx *data, int x, int y, int color);

// create image
void	image_create(t_mlx *mlx);

// Converts rgb value to hex (used in MLX)
int		rgb_to_hex(int *clr);

// Remove background from image
void	remove_background(t_mlx *mlx, char *path, int color, int pos[2]);

// Remove background weapon
void	remove_background_weapon(t_mlx *mlx, char *path, int color, int pos[2]);

void	test_remove_background(t_mlx *mlx, char *path, int color, int pos[2]);

/**************************/
/*     logic/utils.c      */
/**************************/

// Get Map sizes
void	get_sizes_matrix(t_minimap *map);

// get object that got hit and the location
bool	found_hit(t_ray_data *data, char **map, int x, int y);

// get object that got hit and location on a single ray
bool	found_single(t_ray_data *data, char **map, int x, int y);

/**************************/
/*   logic/3d_drawer.c    */
/**************************/

// Draws X segment (every x pixel draw vertical stripe)
void	draw_x_line(t_mlx *mlx, t_ray_data *data, int x);

// Get Color of certain pixel
int		get_pixel_color_hex(void *img_ptr, int x, int y);

// Setup all data for texture calculations
void	texture_setup(t_ray_data *data);

// Render the content of the screen
void	render(t_mlx *mlx);

/**************************/
/*   logic/raycaster.c    */
/**************************/

// setup for the DDA algorithm
void	setup_dda(t_ray_data *data);

// performs the DDA algorithm (Digital Differential Analyzer)
void	dda_algo(t_ray_data *data, char **map);

// Calculates the distance and line height
void	raycaster_calc(t_ray_data *data);

// setup all the data for the raycaster
void	ray_setup(t_ray_data *data);

// Draws the rays and walls
void	draw_rays(t_player_data *player, char **map, t_mlx *mlx);

/**************************/
/*      bonus/door.c      */
/**************************/

// bool return to check if a door is already bought or not
bool	door_bought(t_scene *scene, t_ray_data *data);

// Open & Close Doors
void	door_interaction(t_player_data *player, t_minimap *map, t_mlx *mlx);

/**************************/
/*     bonus/mouse.c      */
/**************************/

// Gets mouse input and rotates player based on mouse movement
int		mouse_move(int x, int y, t_mlx *mlx);

/**************************/
/*   logic/UI_drawers.c   */
/**************************/

// Our own mlx put string
void	better_mlx_string(t_mlx *mlx, int count, ...);

void	draw_crosshair(t_mlx *mlx);

void	ui_drawer(t_mlx *mlx, t_single_texture *tex, int color, int pos[2]);

/**************************/
/*     bonus/weapons.c    */
/**************************/

// Gives shotgun when player bought it
void	give_shotgun(t_weapon_data *weapon);

// Gives ar when player bought it
void	give_ar(t_weapon_data *weapon);

// weapon drawer function
void	weapon_drawer(t_weapon_data *weapon, t_mlx *mlx);

/**************************/
/*     bonus/wall_buy.c   */
/**************************/

void	buy_weapon(t_player_data *player, t_weapon_data *weapon, t_mlx *mlx);

int		which_buy_point(int object);

int		price_checker(int object, bool weapon_buy);

/**************************/
/*  logic/interaction.c   */
/**************************/

void	interaction_handler(t_mlx *mlx, t_player_data *player, t_minimap *map);

void	interaction_ui(t_mlx *mlx);

/**************************/
/*      bonus/enemy.c     */
/**************************/

void	damage_player(t_mlx *mlx);

/**************************/
/*      logic/hud.c       */
/**************************/

void	draw_ammo(t_mlx *mlx, int ammo_temp, int x, int y);

void	draw_hud(t_mlx *mlx, t_player_data *player, t_weapon_data *weapon);

void	draw_weapon(t_mlx *mlx, t_single_texture *tex, int color);

void	pistol_reloading(t_mlx *mlx);

void	shotgun_reloading(t_mlx *mlx);

void	ar_reloading(t_mlx *mlx);

void	fetch_weapon_textures(t_textures *text, t_mlx *mlx);

void	fetch_ui_textures(t_textures *text, t_mlx *mlx);

void	ui_imager(t_mlx *mlx, int color);

void	ui_colorizer(t_mlx *mlx);

void	minimap_draw_seg(t_mlx *mlx, int x, int y, int object);

void	create_reloading_thread(t_mlx *mlx);

char	*get_texture_filename(char *path, int frame_number);

#endif
