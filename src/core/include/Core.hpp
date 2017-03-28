/* ************************************************************************** *
 *   core.h
 *                                                       :::      ::::::::    *
 *                                                     :+: :+:    :+:    :+:  *
 *                                                    +:+   +:+   +:+    +:+  *
 *   By: THEIS Paul                                  +#++:++#++:  +#++:++#+   *
 *                                                   +#+     +#+  +#+         *
 *   Created: 20/03/17                               #+#     #+#  #+#         *
 *   Updated: 20/03/17                               #+#     #+#  #+#         *
 *   Project: cpp_arcade
 * ************************************************************************** */


#ifndef _CORE_HPP_
# define _CORE_HPP_

# include <iostream>
# include <string>
# include <map>
# include <functional>
# include <signal.h>

# include "Protocol.hpp"

namespace arcade
{
    class Core
    {
    public:
        static const std::string GMXConfig;
        static const std::string GFXConfig;
//    public:
//        Core(Vector2u const& gamedim);
//        ~Core(void);
//
//        void init(std::string const& lib, std::string const& conf);
//        void setLibGraphic(std::string const& lib);
//        void setLibGames(std::string const& lib);
//        bool play(void);
//    private:
//        std::map<GameState, std::function<void(float const, InputT const)> > _update;
//        void up_menu(float const delta, InputT const in);
//        void up_game(float const delta, InputT const in);
//
//        std::map<InputT, std::function<void(void)> > _input;
//        void closeWindow(void);
//        void prevLibGraph(void);
//        void nextLibGraph(void);
//        void prevLibGame(void);
//        void nextLibGame(void);
//        void restartGame(void);
//        void goToMenu(void);
//
//        void loadScore(void);
//
//        Chronometer _clock;
//        GameState _state;
//        Vector2u _gamedim;
//
//        SoLoader _loader[2];
//        IGraphic *_graphic;
//
//        std::string _currentGames;
//        std::string _currentGraph;
//        std::vector<std::string> _gamesPath;
//        std::vector<std::string> _graphPath;
//        std::vector<std::string> _scoreData;
//
//        ArcadeMenu *_menu;
//        ArcadeGame *_game;
    };
}

void  arcade_ragequit(int n);

#endif /* !_CORE_HPP_ */
