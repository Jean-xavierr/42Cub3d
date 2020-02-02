
void	ft_draw_wall_texture(t_storage *storage, t_ray *ray, int x)
{
	if (ray->side == 1)
	{
		if (ray->raydirY >= 0)
		{
			while (drawstart < drawend)
			{

			}
		}
		else
		{
			while (drawstart < drawend)
			{
			}
		}
	}
	else
	{
		if (ray->raydirX >= 0)
		{
			while (drawstart < drawend)
			{
			}
		}
		else
		{
			while (drawstart < drawend)
			{
			}
		}
	}

}

void	ft_init_value(t_storage *storage, t_ray *ray, int x)
{
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		wallx;
	int		texturex;
	int		texturewidth;


	texturewidth = 54;
	lineheight = (int)(storage->info->ry / ray->perpwalldist);
	lineheight *= 1;
	drawstart = -lineheight / 2 + storage->info->ry / 2;
	if (drawstart < 0)
		drawstart = 0;
	drawend = lineheight / 2 + storage->info->ry / 2;
	if (drawend >= storage->info->ry)
		drawend = storage->info->ry - 1;	
	if (ray->side == 0)
		wallx = storage->player->posY + ray->perpwalldist * ray->dirY;
	else
		wallx = storage->player->posX + ray->perpwalldist * ray->dirX;
	wallx = floor(wallx);
	texturex = (int)(wallx * (double)texturewidth);
	if (ray->side == 0 && ray->raydirX > 0)
		texturex = texturewidth - texturex - 1;
	if (rayside == 1 && ray->raydirY < 0)
		texturex = texturewidth - texturex - 1;
}

void	ft_management_texture(t_storage *storage, t_ray *ray, int x)
{
	ft_init_texture();
	ft_init_value(storage, ray, x);
	ft_draw_wall_texture(storage, ray, x);

}
