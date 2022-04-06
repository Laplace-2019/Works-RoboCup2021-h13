/*
 * OfficialScriptChineseFont.h
 *
 *  Created on: 2022��3��26��
 *      Author: h13
 */

#ifndef APP_UI_OFFICIALSCRIPTCHINESEFONT_H_
#define APP_UI_OFFICIALSCRIPTCHINESEFONT_H_

typedef enum
{
	OfficialScriptChsPing  = 0,      //Chinese ƻ
    OfficialScriptChsGuo   = 1,      //Chinese ��
    OfficialScriptChsXiang = 2,      //Chinese ��
    OfficialScriptChsJiao  = 3,      //Chinese ��
    OfficialScriptChsMi    = 4,      //Chinese �
    OfficialScriptChsHou   = 5,      //Chinese ��
    OfficialScriptChsTao   = 6,      //Chinese ��
    OfficialScriptChsNing  = 7,      //Chinese ��
    OfficialScriptChsMeng  = 8,      //Chinese ��
    OfficialScriptChsJu    = 9,      //Chinese ��
    OfficialScriptChsZi    = 10,     //Chinese ��
    OfficialScriptChsLi    = 11,     //Chinese ��
    OfficialScriptChsHuo   = 12,     //Chinese ��
    OfficialScriptChsLong  = 13,     //Chinese ��
    OfficialScriptChsXue   = 14,     //Chinese ѩ

    OfficialScriptChsYi    = 15,     //Chinese һ
	OfficialScriptChsLiang = 16,     //Chinese ��
    OfficialScriptChsSan   = 17,     //Chinese ��
    OfficialScriptChsSi    = 18,     //Chinese ��
    OfficialScriptChsWu    = 19,     //Chinese ��
    OfficialScriptChsLiu   = 20,     //Chinese ��
    OfficialScriptChsQi    = 21,     //Chinese ��
    OfficialScriptChsGe    = 22,     //Chinese ��
} OfficialScriptChineseFont_t;

uint8_t *GetOfficialScriptChineseFontPtr(OfficialScriptChineseFont_t ChineseCharacterIndex);

#endif /* APP_UI_OFFICIALSCRIPTCHINESEFONT_H_ */
