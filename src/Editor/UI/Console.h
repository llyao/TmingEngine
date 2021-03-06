//The MIT License
//
//Copyright(c) 2016 - 2020 littleblue
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this softwareand associated documentation files(the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
//copies of the Software, and to permit persons to whom the Software is furnished
//to do so, subject to the following conditions :
//
//The above copyright noticeand this permission notice shall be included in
//all copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
//FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR
//COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
//IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
//CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#pragma once
#ifndef console_h
#define console_h

#include "Core/SubSystem.h"
#include "Core/Context.h"
#include "Plantform/Windows/Widget.h"
#include "im.h"
#include "Core/Log/Log.h"


extern "C"
{
//#include "Scheme/include/scheme.h"
}


extern "C"
{
#include "lua.h"  
#include "lauxlib.h"  
#include "lualib.h"  
}

#include <angelscript.h>
#include <scriptstdstring/scriptstdstring.h>
#include <scriptbuilder/scriptbuilder.h>

namespace TmingEngine
{

	void ConfigureEngine(asIScriptEngine* engine);
	int  CompileScript(asIScriptEngine* engine);
	void PrintString(string& str);
	void PrintString_Generic(asIScriptGeneric* gen);
	void timeGetTime_Generic(asIScriptGeneric* gen);
	void LineCallback(asIScriptContext* ctx, DWORD* timeOut);



	class Console : public Widget
	{
	public:
		ImGuiTextBuffer     Buf;
		ImGuiTextFilter     Filter;
		ImVector<int>       LineOffsets;        // Index to lines offset
		bool                ScrollToBottom;

		Console(Context *context)
		{
		}
		~Console();

        void Begin();
        void Update();
        void End();
        
		void Clear();
		void AddLog(const char* fmt, ...);
		void Draw(const char* title, bool* p_open);
		//void Draw2(const char* title, bool* p_open);
		void TestLua();
		int TestAngleScript();
	};
}
#endif
