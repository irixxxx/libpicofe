
// Convert 0000bbb0 ggg0rrr0 0000bbb0 ggg0rrr0
// to      00000000 rrr00000 ggg00000 bbb00000 ...
// TODO: rm when gp2x/emu.c is no longer used

void vidConvCpyRGB32  (void *to, void *from, int pixels)
{
	unsigned short *ps = from;
	unsigned int   *pd = to;

	for (; pixels; pixels--, ps++, pd++)
	{
		*pd = ((*ps<<20)&0xe00000) | ((*ps<<8)&0xe000) | ((*ps>>4)&0xe0);
		*pd |= *pd >> 3;
	}
}

void vidConvCpyRGB32sh(void *to, void *from, int pixels)
{
	unsigned short *ps = from;
	unsigned int   *pd = to;

	for (; pixels; pixels--, ps++, pd++)
	{
		*pd = ((*ps<<20)&0xe00000) | ((*ps<<8)&0xe000) | ((*ps>>4)&0xe0);
		*pd >>= 1;
		*pd |= *pd >> 3;
	}
}

void vidConvCpyRGB32hi(void *to, void *from, int pixels)
{
	unsigned short *ps = from;
	unsigned int   *pd = to;

	for (; pixels; pixels--, ps++, pd++)
	{
		*pd = ((*ps<<20)&0xe00000) | ((*ps<<8)&0xe000) | ((*ps>>4)&0xe0);
		continue;
		*pd += 0x00404040;
		if (*pd & 0x01000000) *pd |= 0x00e00000;
		if (*pd & 0x00010000) *pd |= 0x0000e000;
		if (*pd & 0x00000100) *pd |= 0x000000e0;
		*pd &= 0x00e0e0e0;
		*pd |= *pd >> 3;
	}
}

void vidcpy_m2(void *dest, void *src, int m32col, int with_32c_border)
{
	unsigned char *pd = dest, *ps = src;
	int i, u;

	if (m32col) {
		for (i = 0; i < 224; i++)
		{
			ps += 8;
			pd += 32;
			for (u = 0; u < 256; u++)
				*pd++ = *ps++;
			ps += 64;
			pd += 32;
		}
	} else {
		for (i = 0; i < 224; i++)
		{
			ps += 8;
			for (u = 0; u < 320; u++)
				*pd++ = *ps++;
		}
	}
}

void vidcpy_m2_rot(void *dest, void *src, int m32col, int with_32c_border)
{
}

void rotated_blit8 (void *dst, void *linesx4, int y, int is_32col)
{
}

void rotated_blit16(void *dst, void *linesx4, int y, int is_32col)
{
}
