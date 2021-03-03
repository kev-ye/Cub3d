# 42 project : Cub3d

## Index

* [Presentation](#Presentation)
* [How_to_run](#How_to_run)
* [Some_debug](#Some_debug)
* [Utils_docs](#Utils_docs)

## Presentation

Cub3D is a remarkable playground to explore the playful practical applications of mathematics without having to understand the specifics.

## How_to_run

    Program are tested in Macos and linux.

Mandadory part :

    make && ./cub3D map/map.cub

Bonus part :

    make bonus && ./cub3D_bonus map/map_bonus.cub

## Some_debug

    My program is not prefect because it have some "Still reachable" leaks in linux (found with valgrind).

    “still reachable” means your program is probably ok – it didn’t free some memory it could have. This is quite common and often reasonable. Don’t use –show-reachable=yes if you don’t want to see these reports.

Solution :

    Use the function "mlx_destroy_display(void *mlx_ptr)" to destroy your mlx pointer and free it.


## Utils_docs

[Link_getting_started_mlx](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)  
[Link_lodev_raycasting](https://lodev.org/cgtutor/raycasting.html)