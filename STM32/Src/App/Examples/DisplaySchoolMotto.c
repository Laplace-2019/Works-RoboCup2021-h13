/*
 * DisplaySchoolMotto.c
 *
 *  Created on: 2021��10��23��
 *      Author: h13
 */

#include "DisplaySchoolMotto.h"
#include "SimpleUI.h"

extern const unsigned char SchoolMotto[24180];

void DisplaySchoolMotto(void)
{
	DrawPicture(0, 18, 130, 93, (uint16_t *)SchoolMotto);
}
