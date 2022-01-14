/*
 * Luat.h
 *
 *  Created on: 2021��8��18��
 *      Author: h13
 */

#ifndef DRIVERS_LUAT_LUAT_H_
#define DRIVERS_LUAT_LUAT_H_

#ifndef COUNT_ARGS
#define COUNT_ARGS(X...) __COUNT_ARGS(, ##X, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define __COUNT_ARGS(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _n, X...) _n
#endif

#include <stdint.h>

/**
 * @brief: Init peripheral for Luat.
 */
void LuatModuleInit(void);

typedef struct
{
	uint8_t       Index;
	const uint8_t BufferSize;
	char*         BufferPtr;
} LuatMessage_t;

/**
 * @brief: Create new message for Luat.
 * @usage:
 * 		char messageBuffer[128] = { 0 };
 * 		LuatMessage_t message = LuatCreatNewMessage(messageBuffer, 128);
 */
LuatMessage_t LuatCreatNewMessage(char *BufferPtr, uint8_t BufferSize);

typedef enum
{
	//English characters.
	/*
	UnicodeEngOne   = 0x0031,     //English 1
	UnicodeEngTwo   = 0x0032,     //English 2
	UnicodeEngThree = 0x0033,     //English 3
	UnicodeEngFour  = 0x0034,     //English 4
	UnicodeEngFive  = 0x0035,     //English 5
	UnicodeEngSix   = 0x0036,     //English 6
	UnicodeEngComma = 0x002c,     //English ,
	*/

	//Chinese characters.
	UnicodeChsPing  = 0x82f9,     //Chinese ƻ
	UnicodeChsGuo   = 0x679c,     //Chinese ��
	UnicodeChsXiang = 0x9999,     //Chinese ��
	UnicodeChsJiao  = 0x8549,     //Chinese ��
	UnicodeChsMi    = 0x7315,     //Chinese �
	UnicodeChsHou   = 0x7334,     //Chinese ��
	UnicodeChsTao   = 0x6843,     //Chinese ��
	UnicodeChsNing  = 0x67e0,     //Chinese ��
	UnicodeChsMeng  = 0x6aac,     //Chinese ��
	UnicodeChsJu    = 0x6a58,     //Chinese ��
	UnicodeChsZi    = 0x5b50,     //Chinese ��
	UnicodeChsLi    = 0x68a8,     //Chinese ��
	UnicodeChsHuo   = 0x706b,     //Chinese ��
	UnicodeChsLong  = 0x9f99,     //Chinese ��
	UnicodeChsXue   = 0x96ea,     //Chinese ѩ

	UnicodeChsYi    = 0x4e00,     //Chinese һ
	UnicodeChsLiang = 0x4e24,     //Chinese ��
	UnicodeChsSan   = 0x4e09,     //Chinese ��
	UnicodeChsSi    = 0x56db,     //Chinese ��
	UnicodeChsWu    = 0x4e94,     //Chinese ��
	UnicodeChsLiu   = 0x516d,     //Chinese ��
	UnicodeChsQi    = 0x4e03,     //Chinese ��
	UnicodeChsGe    = 0x4e2a,     //Chinese ��

	UnicodeChsComma = 0xff0c,     //Chinese ��
} Unicode_t;

/**
 * @brief: Add one character to message.
 * @param:
 * 		Msg:       LuatMessage_t, The Appended target.
 * 		Character: Unicode_t, The characters you want to add.
 */
int LuatAddMessageContent(LuatMessage_t *Msg, Unicode_t Character);

/**
 * @brief: Add contents to LuatMessage_t.
 * @param:
 * 		Msg: LuatMessage_t, The Appended target.
 * 		...: Unicode_t, List of characters you want to add.
 * @usage:
 * 		LuatAddMessageContents(&message, UnicodeChsPing, UnicodeChsGuo);                              //ƻ��
 * 		LuatAddMessageContents(&message, UnicodeChsPing, UnicodeChsGuo, UnicodeEngOne, UnicodeChsGe); //ƻ��1��
 * @note:
 * 		The number of parameters should be less than 14.
 */
#define LuatAddMessageContents(Msg, ...)  __luatAddMessageContents(Msg, COUNT_ARGS(Msg ##__VA_ARGS__), ##__VA_ARGS__)
int __luatAddMessageContents(LuatMessage_t *Msg, uint8_t Length, ...);

/**
 * @brief: Send message to target phone.
 * @param:
 * 		LuatMessage_t *Msg:            The message you want to send.
 * 		const char* TargetPhoneNumber: Target Phone Number.
 * @note:
 * 		The phone number is a string, not an integer.
 * 		Such as 0371-66667777
 */
void LuatSendMessage(LuatMessage_t *Msg, const char* TargetPhoneNumber);

#endif /* DRIVERS_LUAT_LUAT_H_ */
