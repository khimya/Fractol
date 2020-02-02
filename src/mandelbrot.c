/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 22:38:40 by ybenbrai          #+#    #+#             */
/*   Updated: 2020/02/02 23:00:59 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_data *data)
{
	data->mandel->row = -1;
	while (++data->mandel->row < height)
	{
		data->mandel->col = -1;
		while(++data->mandel->col < width)
		{
			data->mandel->c_re  = (data->mandel->col - width / data->mandel->right_left) * data->mandel->zoom_in / width;
        	data->mandel->c_im  = (data->mandel->row - height / data->mandel->up_down) * data->mandel->zoom_in / width;
        	data->mandel->x = 0;
			data->mandel->y = 0;
        	data->mandel->iteration = 0;
        	while (data->mandel->x * data->mandel->x + data->mandel->y * data->mandel->y <= 4 && data->mandel->iteration < data->mandel->quality)
			{
            	data->mandel->x_new = (data->mandel->x * data->mandel->x) - (data->mandel->y * data->mandel->y) + data->mandel->c_re;
            	data->mandel->y = (2 * data->mandel->x * data->mandel->y) + data->mandel->c_im;
            	data->mandel->x = data->mandel->x_new;
            	data->mandel->iteration++;
        	}
			if (data->mandel->iteration < data->mandel->quality)
			{
				data->mlx->img_data[data->mandel->row * width + data->mandel->col] = (data->mandel->iteration << data->mandel->hexa) | (data->mandel->iteration << data->mandel->octa) | (data->mandel->iteration);
				
			}
        	else 
				data->mlx->img_data[data->mandel->row * width + data->mandel->col] = 0x000000;
    }
	
	}
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr, data->mlx->img_ptr, 0, 0);
}