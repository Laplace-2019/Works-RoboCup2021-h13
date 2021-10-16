/*
 * VoicePlayer.c
 *
 *  Created on: 2021��10��14��
 *      Author: h13
 */
#include "RobotConfigs.h"
#include "Ports.h"
#include "VoicePlayer.h"
#include "DF_PlayerMini.h"

static DF_PlayerMini_t player = VoicePlayer;

void VoicePlayerInit(void)
{
	DF_PlayerInit(&player);
}

void VoicePlayerPlayByID(Voice_t Voice)
{
	DF_PlayerJoinQueue(&player, Voice);
}

void VoicePlayerPlayByIDS(Voice_t *VoicePtr, uint8_t Length)
{
	for(uint8_t i = 0; i < Length; i++)
	{
		DF_PlayerJoinQueue(&player, *(VoicePtr + i));
	}
}
