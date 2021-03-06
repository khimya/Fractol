/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 01:09:26 by ybenbrai          #+#    #+#             */
/*   Updated: 2020/02/03 19:24:25 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int    keypress(int key, void *param)
{
    t_core *core;

    core = (void *)param;
    if (key == 4)
        core->mandel.quality += 1;
    else if (key == 37)
        core->mandel.quality -= 1;
    if (key == 8)
            core->mandel.hexa += 1;
    if (key == 69)
        {
                core->mandel.zoom_in -= 0.05;
        printf("zoom in ----->%f\n", core->mandel.zoom_in);
        }

    if (key == 78)
    {
                core->mandel.zoom_in += 0.05;

    }
    if (key == 123) 
            core->mandel.right_left += 0.05;
    if (key == 124)
            core->mandel.right_left -= 0.05;
    if (key == 126)
            core->mandel.up_down += 0.05;
    if (key == 125)
            core->mandel.up_down -= 0.05;
    mandelbrot(core);
    return (0);     
}
int     mouse_press(int button, int x, int y, void *param)
{
    t_core *core;
        printf("t%d\tt%d\n", x, y);
    core = (void *)param;
    if (button == 4)
    {

        // printf("hey\n");
        core->mandel.zoom_in += 0.05;
        core->mandel.right_left += 0.05;
    }
    else if (button == 5)
    {
        core->mandel.zoom_in -= 0.05;
        core->mandel.right_left -= 0.05;
    }

    mandelbrot(core);
    return (0);
} 