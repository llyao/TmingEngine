//
//  Game.cpp
//  01_CaculateCode
//
//  Created by WangYiMing on 2019/5/15.
//

#include "Game.hpp"
TmingEngine::Game::~Game()
{
}

void TmingEngine::Game::Begin()
{
}

void TmingEngine::Game::Update()
{
    bool p_open = true;
    ImGui::SetNextWindowSize(ImVec2(350, 560), ImGuiCond_FirstUseEver);
    if (!ImGui::Begin("Game", &p_open))
    {
        ImGui::End();
        return;
    }
    ImTextureID my_tex_id = (void *)ImageId;
    float my_tex_w = 512;
    float my_tex_h = 280;
    
    ImGui::Text("%.0fx%.0f", my_tex_w, my_tex_h);
    //----------------------------------------------------------------- -1 -1  Image reversal
    ImGui::Image(my_tex_id, ImVec2(my_tex_w, my_tex_h), ImVec2(0, 0), ImVec2(-1, -1), ImColor(255, 255, 255, 255), ImColor(255, 255, 255, 128));
    
    ImGui::Text("this  is Detial Panel ");
    
    ImGui::End();
}

void TmingEngine::Game::End()
{
}