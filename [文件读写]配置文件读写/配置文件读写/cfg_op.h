#pragma once

//pFileName ���ļ�Ŀ¼  pKey���ļ���Key pValue���ļ���ֵ pValueLen�ǳ���
int Cfg_Write_Data(const char *pFileName, const char *pKey, const char *pValue);

int Cfg_Read_Data(const char *pFileName, const char *pKey, char *pValue);