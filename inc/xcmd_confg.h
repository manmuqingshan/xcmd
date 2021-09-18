/*
 * @Author: your name
 * @Date: 2021-09-17 23:03:06
 * @LastEditTime: 2021-09-17 23:07:03
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /xcmd/inc/xcmd_confg.h
 */
#ifndef XCMD_CONFG_H
#define XCMD_CONFG_H

#ifdef __cplusplus
extern   "C" {
#endif

#define VERSION "1.0.0"

#define XCMD_LINE_MAX_LENGTH    (64) /* 命令行支持的最大字符数 */
#define XCMD_HISTORY_MAX_NUM    (8)  /* 支持的历史记录个数，0为不支持 */
#define XCMD_PARAM_MAX_NUM      (16)  /* 支持输入的参数个数 */

#ifdef __cplusplus
        }
#endif

#endif /* XCMD_CONFG_H */