#include <curses.h>
#include "game_console.h"
#include "core_functions/bass.h"

extern char **game_map;
extern struct dimension player_pos;
extern int attack;
extern char deathblock;
extern struct opponent opp;
extern struct dimension map_size;
void att(int direction){
    int i;
    if(direction == KEY_DOWN){
        for(i = player_pos.y; (i < (player_pos.y + attack)) && (i < map_size.y); i++){
            if((game_map[i][player_pos.x] == deathblock) || (game_map[i][player_pos.x] == opp.rival))
                game_map[i][player_pos.x] = ' ';
        }
    }
    else if(direction == KEY_UP){
        for(i = player_pos.y; (i > (player_pos.y - attack)) && (i > 0); i--){
            if((game_map[i][player_pos.x] == deathblock) || (game_map[i][player_pos.x] == opp.rival))
                game_map[i][player_pos.x] = ' ';
            debug_output(i, player_pos.y);
        }
    }
    else if(direction == KEY_RIGHT){
        for(i = player_pos.x; (i < (player_pos.x + attack) )&& (i < map_size.x); i++){
            if((game_map[player_pos.y][i] == deathblock) || (game_map[player_pos.y][i] == opp.rival))
                game_map[player_pos.y][i] = ' ';
            debug_output(player_pos.y, i);
        }
    }
    else if(direction == KEY_LEFT){
        for(i = player_pos.x; (i > (player_pos.x - attack)) && (i > 0); i--){
            if((game_map[player_pos.y][i] == deathblock) || (game_map[player_pos.y][i] == opp.rival))
                game_map[player_pos.y][i] = ' ';
        }
        debug_output(player_pos.y, i);
    }
}