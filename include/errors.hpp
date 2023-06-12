#ifndef ERROR_H
#define ERROR_H

#define CODE_SUCCESS 0
#define CODE_FAILURE 84

#define INVALID_CONFIGURATION "Error: invalid configuration file."
#define DUPLICATE_CONFIGURATION "Warning: duplicate configuration names (will be ignored)."
#define DUPLICATE_RTEX "Warning: duplicate render texture id (will be ignored)."
#define DUPLICATE_RECT "Warning: duplicate rectangle shape id (will be ignored)."
#define DUPLICATE_TEXT "Warning: duplicate rectangle shape id (will be ignored)."
#define DUPLICATE_CIRCLE "Warning: duplicate circle shape id (will be ignored)."
#define DUPLICATE_SPRITE "Warning: duplicate sprite id (will be ignored)."
#define DUPLICATE_VERTEX "Warning: duplicate vertex array id (will be ignored)."
#define DUPLICATE_SHADER "Error: duplicate shader id."
#define DUPLICATE_TEXTURE "Error: duplicate texture id."
#define DUPLICATE_FONT "Error: duplicate font it."
#define RTEX_FAIL "Error: couldn't create render texture."
#define SHADER_FAIL "Error: couldn't create shader."
#define UNKNOWN_ID "Warning: can't access element (unknown id)."
#define NO_FILE "Error: no such file or directory."

#endif