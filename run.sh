# clang -I./inc -I./libft/libft/inc -I./mlx/mlx -L./mlx/mlx -lmlx -L./libft/libft -lft -lm -framework OpenGL -framework AppKit src/*.c src/*/*.c -o Cub3d
# clang -I./inc -I./libft/inc -I./mlx -lmlx -Llibft -lft -lm -framework OpenGL -framework AppKit src/*.c src/*/*.c -o Cub3d

#clang -I./inc -I./libft/inc -I./mlx/mlx -L./mlx/mlx -lmlx -L./libft -lft -lm -framework OpenGL -framework AppKit src/*.c src/*/*.c -o Cub3d && ./cub3D map.cub 
clang -I./inc -I./libft/inc -I./mlx/mlx_old_version -L./mlx/mlx_old_version -lmlx -L./libft -lft -lm -framework OpenGL -framework AppKit src/*.c src/*/*.c -o Cub3d && ./cub3D map.cub 