#pragma once
#include <windows.h>
#include <iostream>
#include <vector>
#include <math.h>

struct vec3 { float x, y, z; };

vec3 Add(vec3 stc, vec3 dst);

namespace mem
{
	void Patch(BYTE* dst, BYTE* src, unsigned int size);
	uintptr_t FindDMAAddy(uintptr_t ptr, std::vector<unsigned int> offsets);
}