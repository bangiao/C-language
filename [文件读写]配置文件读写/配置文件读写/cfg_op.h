#pragma once

//pFileName 是文件目录  pKey是文件的Key pValue是文件的值 pValueLen是长度
int Cfg_Write_Data(const char *pFileName, const char *pKey, const char *pValue);

int Cfg_Read_Data(const char *pFileName, const char *pKey, char *pValue);