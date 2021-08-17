##
## EPITECH PROJECT, 2019
## PSU_my_sokoban_2019
## File description:
## Makefile
##

#flag#
CFLAGS = -Wall -Wextra -Wshadow -finline-functions

CPPFLAGS = -iquote $(IDIR)

DBGFLAGS = -g3 -ggdb

LDFLAGS = -lm

CSFML = -lcsfml-system -lcsfml-window -lcsfml-graphics -lcsfml-audio -lcsfml-network

LIBFLAGS = -L lib/ -lmy

#source#
SRC =	town/main.c							\
	town/monster/monster_animation.c				\
	town/monster/monster_hit_box.c					\
	town/event/menu_pause_event.c					\
	town/event/analyse_event.c					\
	town/event/view_event.c						\
	town/event/view_event_start.c					\
	town/event/save_event.c      					\
	town/event/load_event.c      					\
	town/parser/basic_parser/different_parsing.c			\
	town/parser/parser.c						\
	town/parser/str_to_tab.c					\
	town/parser/basic_parser/test_parser.c				\
	town/parser/basic_parser/function_to_go.c			\
	town/parser/png_quest_parser/png_quest_parser.c			\
	town/parser/basic_parser/other_stuff.c				\
	town/parser/basic_parser/full_fill.c 				\
	town/parser/basic_parser/fulfill_the_monster.c 			\
	town/parser/set_olivier.c 					\
	town/display/display_map.c					\
	town/display/display_object_as_map.c				\
	town/display/display_object.c					\
	town/display/object_in_mouvement.c				\
	town/parser/actualise_parser/actualise_parser.c			\
	town/parser/actualise_parser/actualise_monster_parser.c		\
	town/monster/monster_aggro.c					\
	town/monster/monster_aggro_move.c				\
	town/monster/monster_stats.c					\
	town/display/collision.c					\
	town/quest/png_quest.c						\
	town/quest/quest_monitor.c					\
	town/quest/draw_the_quest_menu.c				\
	town/quest/display_with_chrone.c				\
	town/quest/dialogue_process.c					\
	town/quest/png_range_for_quest.c				\
	town/save/draw_the_save_menu.c					\
	town/save/select_the_save_menu.c				\
	town/save/select_the_save_menu2.c				\
	town/event/save_event_else.c					\
	town/event/save_event_bis.c					\
	town/start_or_load_game.c					\
	town/my_getenv.c						\
	town/inventory/inventory_management.c				\
	town/inventory/inventory.c					\
	town/inventory/inventory_grab_and_drop.c			\
	town/inventory/inventory_get_info_with_parsing.c		\
	town/inventory/actualise_object_parser.c			\
	town/inventory/actualise_object_parser2.c			\
	town/inventory/actualise_obj_when_put_obj_in_inventory.c	\
	town/sound/set_music.c						\
	town/stat/display_stats.c					\
	town/stat/values_stats.c					\
	town/stat/capacities.c						\
	town/set/set_all.c						\
	town/set/set_enums.c						\
	town/set/set_png.c						\
	town/save/save_interface.c					\
	town/save/select_interface.c					\
	town/save/parser_to_tab_save.c					\
	town/save/load_from_menu.c					\
	town/game_over/game_over.c					\
	town/game_over/draw_game_over.c					\
	town/game_over/load_game_over.c					\
	town/hero/hero_mouvement.c					\
	town/hero/clock_hero.c						\
	town/hero/status_hero.c						\
	town/display/chest_obj.c					\
	town/parser/basic_parser/fulfill_the_chest.c			\
	town/inventory/inventory_management2.c				\
	town/inventory/inventory_special_case2.c			\
	town/inventory/inventory_special_case.c				\
	town/inventory/inventory_case2_to_spe.c				\
	town/inventory/inventory_case2_to_spe2.c			\
	town/switch_maps/switch_map.c					\
	town/switch_maps/switch_map_conditions.c			\
	town/display/gate_open_with_key.c				\
	town/display/gate_open_with_key2.c				\
	town/display/help_function_display.c				\
	town/save/reset_delta_time.c					\
	town/free_all.c							\
	town/inventory/get_elapsed_time.c				\
	$(wildcard menu_option/*.c)

OBJ = $(SRC:.c=.o)

NAME = my_rpg

IDIR = include

CC = gcc

#rules#
all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	$(CC) $(CSFML) -o $(NAME) $(OBJ) $(LIBFLAGS) $(LDFLAGS)

debug: CFLAGS += $(DBGFLAGS)
debug: $(NAME)

clean:
	rm -f $(OBJ)
	rm -f include/*.gc*
	rm -f vgcore*

fclean: clean
	rm -f $(NAME)
	rm -f $(OBJ)
	rm -f a.out

re: fclean all

lib:
	make -C lib/my

ex: $(OBJ)
	$(CC) $(CMPFLAGS) $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LIBFLAGS)
	rm -f $(OBJ)

mclean: fclean
	rm -f lib/libmy.a

.PHONY: fclean clean re all debug lib mclean ex

tests_run: LDFLAGS += -lcriterion --coverage

tests_run:
		$(CC) -o unit_tests tests/project.c $(CPPFLAGS) $(LDFLAGS) $(CFLAGS)
		./unit_tests
		gcovr -e tests/
