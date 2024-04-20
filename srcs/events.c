/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obednaou <obednaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 12:57:34 by obednaou          #+#    #+#             */
/*   Updated: 2022/12/29 16:11:28 by obednaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

/**
 * @brief function that gets called when a key
 * in the keyboard is pressed.
 * @param keycode{int} the code of the key pressed
*/
void key_down(SDL_Event *event, t_global *g) {
    int keycode = event->key.keysym.sym;
    if (keycode == SDLK_UP || keycode == SDLK_DOWN) {
        g->keys[0] = keycode;
    } else if (keycode == SDLK_LEFT || keycode == SDLK_RIGHT) {
        g->keys[1] = keycode;
    } else if (keycode == SDLK_SPACE) {
        g->key_zoom[0] = keycode;
    } else if (keycode == SDLK_PLUS && g->key_zoom[0]) {
        g->key_zoom[1] = keycode;
    } else if (keycode == SDLK_MINUS && g->key_zoom[0]) {
        g->key_zoom[1] = keycode;
    } else if (keycode == SDLK_ESCAPE) {
        // Call destroy function if ESC key is pressed
        destroy(g);
    }
}

/**
 * @brief function that gets called in case of a
 * key release.
 * @param keycode{int} the code of the key released.
*/
void key_up(SDL_Event *event, t_global *g) {
    if (event->key.keysym.sym == SDLK_UP || event->key.keysym.sym == SDLK_DOWN) {
        g->keys[0] = 0;
    } else if (event->key.keysym.sym == SDLK_LEFT || event->key.keysym.sym == SDLK_RIGHT) {
        g->keys[1] = 0;
    } else if (event->key.keysym.sym == SDLK_SPACE) {
        g->key_zoom[0] = 0;
        g->key_zoom[1] = 0;
    } else if (event->key.keysym.sym == SDLK_PLUS || event->key.keysym.sym == SDLK_MINUS) {
        g->key_zoom[1] = 0;
    }
}

/**
 * @brief function that gets called in case
 * of mouse scroll up or down
 * @param botton{int} the code of the mouse botton
 * pressed.
 * @param x{int} the x coordinate of the position
 * of the mouse click in the window.
*/
int mouse_wheel(SDL_Event *event, t_global *g) {
    if (event->type == SDL_MOUSEWHEEL) {
        if (event->wheel.y != 0) { // Check if it's a wheel event
            g->mouse_zoom = (event->wheel.y > 0) ? SCROL_UP : SCROL_DOWN;
        }
        // Update mouse position
        g->mouse_pos[0] = event->wheel.x;
        g->mouse_pos[1] = event->wheel.y;
        return DONE;
    }
    return 0; // Return 0 if the event is not a mouse wheel event
}

/**
 * @brief function that gets called in case of
 * a mouse move (with or without a click)
 * @param x{int} x coordinate of the position of the cursor of the mouse
 * (not only inside the window).
*/
int mouse_move(SDL_Event *event, t_global *g) 
{
    g->mouse_pos[0] = event->motion.x;
    g->mouse_pos[1] = event->motion.y;
    return DONE;
}

/**
 * @brief the program exits with success 
 * status in case of destruction of the window
 * (pressing the red cross of the window).
*/
int	destroy(t_global *g)
{
    SDL_DestroyRenderer(g->renderer);
    SDL_DestroyWindow(g->window);
    SDL_Quit();
    exit(EXIT_SUCCESS);
    return (DONE);
}

// @brief handles the mouse, keyboard events
void event_handling(t_global *g) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_KEYDOWN:
                key_down(&event, g);
                break;
            case SDL_KEYUP:
                key_up(&event, g);
                break;
            case SDL_MOUSEWHEEL:
                mouse_wheel(&event, g);
                break;
            case SDL_MOUSEMOTION:
                mouse_move(&event, g);
                break;
            case SDL_QUIT:
                destroy(g);
                break;
            default:
                break;
        }
    }
}
