/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:47:20 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/06 11:47:24 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

/* Variables */

# define ANIMATION_FRAMES 6

/* DATA TYPES */

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

# define IDLE 0
# define RUN 1
# define ATTACK 2
# define RIGHT 3
# define LEFT 4

/* Structs */

typedef struct s_texture
{
	void				*img;
	int					bpp;
	int					line_len;
	int					endian;
	char				*addr;
	int					height;
	int					widht;
}						t_texture;

typedef struct s_animation
{
	void				*img;
	struct s_animation	*next;
}						t_animation;
typedef struct s_map
{
	int					height;
	int					width;
	int					player_x;
	int					player_y;
	int					enemy_x;
	int					enemy_y;
	char				**content;
	int					collectibles;
	int					exits;
	int					map_changed;
	int					enemy_present;
	int					player_count;
}						t_map;

typedef struct s_enemy
{
	t_animation			*right;
	int					player_dir;
}						t_enemy;
typedef struct s_player
{
	int					heigth;
	int					width;
	t_animation			*idle_right;
	t_animation			*idle_left;
	t_animation			*runing_right;
	t_animation			*runing_left;
	int					player_state;
	int					player_dir;
}						t_player;

typedef struct t_vars
{
	void				*mlx;
	void				*win;
	t_map				*map;
	t_texture			*floor;
	t_texture			*water;
	t_texture			*collectibles;
	t_texture			*exit;
	t_enemy				*enemy;
	void				*buffer_map;
	char				*buffer_addr;
	int					buffer_bpp;
	int					buffer_line_len;
	int					buffer_endian;
	int					moves;
	int					frames;
	t_player			*player;
	int					have_visited;
	int					static_enem_loc;
	int					collected;
}						t_vars;

int						free_n_returnt(char **str, char *temp, char *msg);
void					free_ifnot_null(char **str);
void					free_content(char **str);
int						check_file_type(char *str);
int						check_one(char *str, char c);
int						err_msg_std(char *msg);
int						count_lines(char *file);
void					get_hw(t_map *map);
void					init_buffer(t_vars *vars);
t_map					*init_map(void);
int						check_collectibles(t_map *map);
int						check_surrounded(t_map *map);
int						check_rectangular(t_map *map);
int						check_player(t_map *map);
int						check_exits(t_map *map);
int						read_map_files(t_map *map, char *file);
t_map					*map_pop(t_map *map, char *path);
int						check_map(t_map *map);
int						check_path(t_map *map);
t_map					*parse_map(char *path);
void					copy_texture_to_buffer(t_texture *tex, t_vars *vars,
							int map_x, int map_y);
char					**copy_map(t_map *map);
int						flood_filling(t_map *map, char **map_copy, int x,
							int y);
int						flood_fill(char **map, int x, int y, int *collectibles);
void					free_map(t_map *map);
int						free_error(char *msg, t_map *map);
t_vars					*init_vars(void);
t_enemy					*pop_enemy(t_vars *vars);
t_enemy					*init_enemy(void);
t_texture				*get_texture_for_tile(t_vars *vars, char tile_char);
int						init_mlx(t_vars *vars);
t_texture				*init_txt(void);
char					*int_to_str(int len, int num);
char					*get_img(char *path, int len, int i);
t_animation				*create_node(void *img);
void					add_node(t_animation **head, t_animation *new_node);
t_animation				*load_animation(t_vars *vars, char *path, int h, int w);
void					*load_texture(t_vars *vars, char *path, int h, int w);
t_texture				*create_texture(t_vars *vars, char *path);
t_player				*player_pop(t_vars *vars);
int						make_window(t_vars *vars);
int						render_player(t_vars *vars);
int						render_player_frame(t_vars *vars, t_animation *anim);
void					render_animation(t_vars *vars, t_animation *anim);
void					free_vars(t_vars *vars);
int						on_keypress(int keysym, t_vars *vars);
int						set_player_to_idle(int keysym, t_vars *vars);
void					replace_tile(t_vars *vars, int new_x, int new_y);
int						get_map(t_vars *vars, char *path);
int						get_textures(t_vars *vars);
int						get_player(t_vars *vars);
void					free_player(t_vars *vars, t_player *player);
void					free_texture(t_vars *vars, t_texture *texture);
void					free_animation(t_vars *vars, t_animation *animation);
void					draw_map(t_vars *vars);
int						on_destroy(t_vars *vars);
void					on_key_press_exit(t_vars *vars);
void					free_textures(t_vars *vars);
void					run_ani(t_vars *vars, t_animation *animation);
void					diter_dir(int keysym, t_vars *vars);
void					exited(t_vars *vars, int new_x, int new_y);
int						add_text_to_window(t_vars *vars, char *str, int number,
							int x);
void					clear_text_area(t_vars *vars, int x, int y);
void					free_enemy(t_vars *vars, t_enemy *enemy);
int						check_enemy(t_map *map);
void					render_enemy(t_vars *vars, t_animation *anim);
int						render_enemy_frame(t_vars *vars, t_animation *anim);
void					enemy_move(t_vars *vars);
int						set_enemy(t_vars *vars);
void					draw_background_tile(t_vars *vars, int tile_x,
							int tile_y);
int						check_for(char *str);
int						check_forbidden_chars(t_map *map);
#endif