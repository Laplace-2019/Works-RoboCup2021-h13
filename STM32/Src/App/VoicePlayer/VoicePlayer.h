/*
 * VoicePlayer.h
 *
 *  Created on: 2021��10��14��
 *      Author: h13
 */

#ifndef APP_VOICEPLAYER_VOICEPLAYER_H_
#define APP_VOICEPLAYER_VOICEPLAYER_H_

void VoicePlayerInit(void);

void VoicePlayerReset(void);

typedef enum
{
	BroadcastFruitDetectResult = 1,
	BroadcastApple = 2,
	BroadcastOne = 3
} Voice_t;

void VoicePlayerPlayByID(Voice_t Voice);

#endif /* APP_VOICEPLAYER_VOICEPLAYER_H_ */
