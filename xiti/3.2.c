/*
 * =====================================================================================
 *
 *       Filename:  3.2.c
 *
 *    Description:
 *
 *
 *        Version:  1.0
 *        Created:  2014年09月27日 21时45分07秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hexing, 1776898728@qq.com
 *        Company:  Xiyou linux
 *
 * =====================================================================================
 */

#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Maxlen 50

int Operate(int left, int right, char str[], int length)
{
	if(length == 0 || length == 1)
	      return 0;
	if(str[left] != str[right])
	      return 1;
	return Operate(left+1, right-1, str, length-2);
}

int main(int argc, char *argv[])
{
	char str[Maxlen];

	printf("请输入要判断的字符串：");
	scanf("%s", str);
	if(!Operate(0, strlen(str)-1, str, strlen(str)))
	      printf("该字符串是回文的!\n");
	else
	      printf("该字符串不是回文的!\n");

	return EXIT_SUCCESS;
}

