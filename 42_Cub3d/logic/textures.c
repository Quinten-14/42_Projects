/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:25:50 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/16 14:25:54 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	fetch_pistol_textures(t_textures *t, char *path, t_mlx *mlx)
{
	char	*filename;
	int		i;

	i = 0;
	while (++i <= 24)
	{
		filename = get_texture_filename(path, i);
		t->pistol_text[i].id = i;
		t->pistol_text[i].x = 1080;
		t->pistol_text[i].y = 720;
		t->pistol_text[i].text_img = mlx_xpm_file_to_image(mlx->ptr, filename,
				&t->tex_size, &t->tex_size);
		t->pistol_text[i].data = mlx_get_data_addr(t->pistol_text[i].text_img,
				&t->pistol_text[i].bpp, &t->pistol_text[i].size_line,
				&t->pistol_text[i].endian);
		if (t->pistol_text[i].text_img == NULL)
			printf("Failed to load pistol textures\n");
		free(filename);
	}
}

static void	fetch_shotgun_textures(t_textures *t, char *path, t_mlx *mlx)
{
	char	*filename;
	int		i;

	i = 0;
	while (++i <= 24)
	{
		filename = get_texture_filename(path, i);
		t->shotgun_text[i].id = i;
		t->shotgun_text[i].x = 1080;
		t->shotgun_text[i].y = 720;
		t->shotgun_text[i].text_img = mlx_xpm_file_to_image(mlx->ptr, filename,
				&t->tex_size, &t->tex_size);
		t->shotgun_text[i].data = mlx_get_data_addr(t->shotgun_text[i].text_img,
				&t->shotgun_text[i].bpp, &t->shotgun_text[i].size_line,
				&t->shotgun_text[i].endian);
		if (t->shotgun_text[i].text_img == NULL)
			printf("Failed to load shotgun textures\n");
		free(filename);
	}
}

static void	fetch_ar_textures(t_textures *text, char *path, t_mlx *mlx)
{
	char	*filename;
	int		i;

	i = 0;
	while (++i <= 24)
	{
		filename = get_texture_filename(path, i);
		text->ar_text[i].id = i;
		text->ar_text[i].x = 1080;
		text->ar_text[i].y = 720;
		text->ar_text[i].text_img = mlx_xpm_file_to_image(mlx->ptr, filename,
				&text->tex_size, &text->tex_size);
		text->ar_text[i].data = mlx_get_data_addr(text->ar_text[i].text_img,
				&text->ar_text[i].bpp, &text->ar_text[i].size_line,
				&text->ar_text[i].endian);
		if (text->ar_text[i].text_img == NULL)
			printf("Failed to load ar textures\n");
		free(filename);
	}
}

static void	fetch_weapon_ui(t_textures *text, t_mlx *mlx)
{
	text->weapon_ui[0].id = 0;
	text->weapon_ui[0].x = 128;
	text->weapon_ui[0].y = 64;
	text->weapon_ui[0].text_img = mlx_xpm_file_to_image(mlx->ptr,
			"textures/pistol.xpm", &text->ui_size, &text->ui_size);
	text->weapon_ui[0].data = mlx_get_data_addr(text->weapon_ui[0].text_img,
			&text->weapon_ui[0].bpp, &text->weapon_ui[0].size_line,
			&text->weapon_ui[0].endian);
	text->weapon_ui[1].id = 1;
	text->weapon_ui[1].x = 128;
	text->weapon_ui[1].y = 64;
	text->weapon_ui[1].text_img = mlx_xpm_file_to_image(mlx->ptr,
			"textures/shotgun.xpm", &text->ui_size, &text->ui_size);
	text->weapon_ui[1].data = mlx_get_data_addr(text->weapon_ui[1].text_img,
			&text->weapon_ui[1].bpp, &text->weapon_ui[1].size_line,
			&text->weapon_ui[1].endian);
	text->weapon_ui[2].id = 2;
	text->weapon_ui[2].x = 128;
	text->weapon_ui[2].y = 64;
	text->weapon_ui[2].text_img = mlx_xpm_file_to_image(mlx->ptr,
			"textures/ar.xpm", &text->ui_size, &text->ui_size);
	text->weapon_ui[2].data = mlx_get_data_addr(text->weapon_ui[2].text_img,
			&text->weapon_ui[2].bpp, &text->weapon_ui[2].size_line,
			&text->weapon_ui[2].endian);
}

void	fetch_weapon_textures(t_textures *text, t_mlx *mlx)
{
	fetch_pistol_textures(text, "textures/pistol/pistol_", mlx);
	fetch_shotgun_textures(text, "textures/shotgun/shotgun_", mlx);
	fetch_ar_textures(text, "textures/ar/ar_", mlx);
	fetch_weapon_ui(text, mlx);
}
