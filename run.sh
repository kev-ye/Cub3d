# clang -I./inc -I./libft/libft/inc -I./mlx/mlx -L./mlx/mlx -lmlx -L./libft/libft -lft -lm -framework OpenGL -framework AppKit src/*.c src/*/*.c -o Cub3d
# clang -I./inc -I./libft/inc -I./mlx -lmlx -Llibft -lft -lm -framework OpenGL -framework AppKit src/*.c src/*/*.c -o Cub3d

clang -I./inc -I./libft/libft/inc -I./mlx/old_mlx_version -L/mlx/old_mlx_version -lmlx -L./libft/libft -lft -lm -framework OpenGL -framework AppKit src/*.c src/*/*.c -o Cub3d