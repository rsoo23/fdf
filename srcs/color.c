/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 08:34:23 by rsoo              #+#    #+#             */
/*   Updated: 2023/06/08 13:33:41 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
True Color Standard
- with the minilibx, we need to make the color fit into an int datatype. That means
that we need the int datatype to be 32 bits on our system
*/

/*
Encode RGB
- takes the red, green, and blue colors as input and combines them into a single number
that represents a specific color in the RGB format.
- uses shifting and birwise OR operations to create this combined value
- example: 0xFF00FF
	- red is FF / 255
	- green is 0
	- blue is FF / 255
*/
int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}
