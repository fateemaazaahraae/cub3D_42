/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:30:00 by fbazaz            #+#    #+#             */
/*   Updated: 2025/01/17 17:03:21 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# define PI 3.14159265358979323846
// # define WALL_STRIP_WIDTH 3
# define LINE_SIZE 200

# define SCREEN_WIDTH 1500
# define SCREEN_HEIGHT 900
# define NUMBER_OF_RAYS SCREEN_WIDTH

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3
# define W 119
# define S 115
# define A 97
# define D 100
# define RIGHT 65363
# define LEFT 65361
# define ESC 65307

# define BLACK 0x00000000
# define WHITE 0xFFFFFFFF

typedef struct ray
{
	bool	isRayUp;
	bool	isRayDown;
	bool	isRayLeft;
	bool	isRayRight;
}	t_ray;

typedef struct color
{
	int		r;
	int		g;
	int		b;
}			t_color;

typedef struct point
{
	float	x;
	float	y;
	int		ver_inter;
}	t_point;

typedef	struct	s_player
{
	t_point	point;
	float	turn_direction;
	float	walk_direction;
	float	left_right;
	float	speed;
	float	fov_angle;
	float	rotation_angle;
	float	rotation_speed;
	float	current_ray_angle;
	int		tile;
}	t_player;

typedef struct s_texture
{
	char	*path;
	void	*img;
	void	*addr;
	int		texture_height;
	int		texture_width;
	int		b_per_pixel;
	int		line_length;
	int		endian;
}	t_texture;

typedef struct cub
{
	int			tile_map;
	char		*content;
	char		**map_content; // to free
	char		char_player;
	char 		c;
	t_texture	textures[4];
	
	t_color		floor_color;
	t_color		ceiling_color;
	t_player	player;
	void		*mlx;
	void		*win;
	void		*img;
	void		*add;
	int			bit_per_pixel;
	int			size_line;
	int			endian;
	int			height;
	int			width;
	float   	ray_distance;
    float   	distance_pp;
    float   	wall_strip_height;
    int     	wall_top_pixel;
    int     	wall_bottom_pixel;
	int			ray_id;
	int			is_ray_hit_door;
	int			texture_x;
	int			texture_y;
}			t_cub;


void		ft_parsing(t_cub *cub, char **av);
void		is_extension(char *str);
void		parse_map(t_cub *cub);
void		parse_line(char *line, t_cub *cub, int *flag);
void		parse_color(char *line, t_color *color, int *flag);
char		*parse_texture(char *line);
void		check_colors(t_cub *cub);
void		is_valid_map(t_cub *cub);
void		check_side_borders(t_cub *cub);
int			check_char(char c);
int    		check_other_char(char **map);
void		check_map(t_cub*cub);
void		check_player_position(t_cub *cub);
int 		is_all_whitespaces(char *str);
void    	check_textures(t_cub *cub);
void    	assign_color(t_cub *cub, char **split, char c);
void    	ft_norm_25_2(char *trim, t_cub *cub, int i, int *j);
void    	check_rgb(int *j, char *str, t_cub *cub, char *to_free);
void    	adjust_map(t_cub *cub);
int 		size_map(char **map);
void    	switch_spaces(t_cub *cub);
void    	adjust_length(t_cub *cub);
void    	check_player_spaces_position(t_cub *cub);
void    	init_mlx(t_cub *cub);
void		save_player_data(t_cub *cub, int i, int j);
void		fill_norm_25(t_cub *cub);


void		init_cub(t_cub *cub);
int    		draw(t_cub *cub);
void		my_mlx_pixel_put(t_cub *cub, int color, float x, float y);
void		render_3d(t_cub *cub);
void	    line(t_cub *cub, float x0, float y0, float x1, float y1);
void		free_2d(char **str);
void		free_all_map(t_cub *cub);
void		fre(char *str);
int			array_size(char **str);
char		*new_string(char a, int size);
int 		key_release(int key, t_cub* cub);
int			print2(int mouse, int x, int y, t_cub *cub);
int			ft_close(t_cub *cub);
int			key_press(int key, t_cub *cub);
void    	cast_all_rays(t_cub *cub);
void    	normalizing(t_cub *cub);
t_point		vertical_intersection(t_cub *cub, t_ray ray);
t_point		horizontal_intersection(t_cub *cub, t_ray ray);
void    	ray_direction(t_ray *ray, float rayAngle);
float   	get_distance(float x1, float y1, float x2, float y2);
bool    	is_a_wall(t_cub *cub, t_point point, char c, t_ray ray);
int			get_right_texture(t_cub *cub, t_point endPoint);
t_point		cast(t_cub *cub);
void    	draw_mini_map(t_cub *cub);
void		render_textures_wall(t_cub *cub, t_point point, int tex_index);




#endif