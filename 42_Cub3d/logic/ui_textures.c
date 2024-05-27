/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:26:21 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/16 14:26:23 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	fetch_crosshairs(t_textures *text, t_mlx *mlx)
{
	text->crosshairs[0].id = 0;
	text->crosshairs[0].x = 32;
	text->crosshairs[0].y = 32;
	text->crosshairs[0].text_img = mlx_xpm_file_to_image(mlx->ptr,
			"textures/crosshair.xpm", &text->crosshair_size,
			&text->crosshair_size);
	if (!text->crosshairs[0].text_img)
		return ((void)printf("Couldn't fetch crosshair texture\n"));
	text->crosshairs[0].data = mlx_get_data_addr(text->crosshairs[0].text_img,
			&text->crosshairs[0].bpp, &text->crosshairs[0].size_line,
			&text->crosshairs[0].endian);
	text->crosshairs[1].id = 1;
	text->crosshairs[1].x = 32;
	text->crosshairs[1].y = 32;
	text->crosshairs[1].text_img = mlx_xpm_file_to_image(mlx->ptr,
			"textures/shotgun_crosshair.xpm", &text->crosshair_size,
			&text->crosshair_size);
	if (!text->crosshairs[1].text_img)
		return ((void)printf("Couldn't fetch crosshair texture\n"));
	text->crosshairs[1].data = mlx_get_data_addr(text->crosshairs[1].text_img,
			&text->crosshairs[1].bpp, &text->crosshairs[1].size_line,
			&text->crosshairs[1].endian);
}

static void	fetch_font(t_textures *text, t_mlx *mlx, char *path)
{
	char	*filename;
	char	*temp;
	char	*number;
	int		i;

	i = -1;
	while (++i < 10)
	{
		number = ft_itoa(i);
		temp = ft_strjoin(path, number);
		filename = ft_strjoin(temp, ".xpm");
		free(temp);
		free(number);
		text->font[i].id = i;
		text->font[i].x = 25;
		text->font[i].y = 25;
		text->font[i].text_img = mlx_xpm_file_to_image(mlx->ptr, filename,
				&text->font_size, &text->font_size);
		text->font[i].data = mlx_get_data_addr(text->font[i].text_img,
				&text->font[i].bpp, &text->font[i].size_line,
				&text->font[i].endian);
		free(filename);
	}
}

static void	fetch_dollar_sign(t_textures *text, t_mlx *mlx, char *path)
{
	char	*temp;
	char	*filename;

	temp = ft_strjoin(path, "$");
	filename = ft_strjoin(temp, ".xpm");
	free(temp);
	text->money_font[10].id = 10;
	text->money_font[10].x = 25;
	text->money_font[10].y = 25;
	text->money_font[10].text_img = mlx_xpm_file_to_image(mlx->ptr, filename,
			&text->money_font_size, &text->money_font_size);
	text->money_font[10].data = mlx_get_data_addr(text->money_font[10].text_img,
			&text->money_font[10].bpp, &text->money_font[10].size_line,
			&text->money_font[10].endian);
	free(filename);
}

static void	fetch_money_font(t_textures *txt, t_mlx *mlx, char *path)
{
	char	*filename;
	char	*temp;
	char	*number;
	int		i;

	i = -1;
	while (++i < 10)
	{
		number = ft_itoa(i);
		temp = ft_strjoin(path, number);
		filename = ft_strjoin(temp, ".xpm");
		free(temp);
		free(number);
		txt->money_font[i].id = i;
		txt->money_font[i].x = 25;
		txt->money_font[i].y = 25;
		txt->money_font[i].text_img = mlx_xpm_file_to_image(mlx->ptr, filename,
				&txt->money_font_size, &txt->money_font_size);
		txt->money_font[i].data = mlx_get_data_addr(txt->money_font[i].text_img,
				&txt->money_font[i].bpp, &txt->money_font[i].size_line,
				&txt->money_font[i].endian);
		free(filename);
	}
	fetch_dollar_sign(txt, mlx, path);
}

void	fetch_ui_textures(t_textures *text, t_mlx *mlx)
{
	fetch_crosshairs(text, mlx);
	fetch_font(text, mlx, "textures/font/");
	fetch_money_font(text, mlx, "textures/font/money/");
}
