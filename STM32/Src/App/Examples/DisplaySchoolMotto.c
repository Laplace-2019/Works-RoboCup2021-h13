/*
 * DisplaySchoolMotto.c
 *
 *  Created on: 2021��10��23��
 *      Author: h13
 */

#include <DrawPicture.h>
#include "DisplaySchoolMotto.h"
#include "Drivers.h"
#include "SchoolMotto.h"

void DisplaySchoolMotto(void)
{
	Fill_Screen(WHITE);
	DrawPicture(0, 18, 130, 94, (uint16_t *)GetSchoolMottoPtr());
}
