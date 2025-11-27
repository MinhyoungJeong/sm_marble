//
//  smm_node.c
//  SMMarble
//
//  Created by Juyeop Kim on 2023/11/05.
//

#include "smm_common.h"
#include "smm_object.h"
#include <string.h>

#define MAX_NODENR        100
#define MAX_NODETYPE      7
#define MAX_GRADE         9

#define SMMNODE_TYPE_LECTURE                0
#define SMMNODE_TYPE_RESTAURANT             1
#define SMMNODE_TYPE_LABORATORY             2
#define SMMNODE_TYPE_HOME                   3
#define SMMNODE_TYPE_GOTOLAB                4
#define SMMNODE_TYPE_FOODCHANGE             5
#define SMMNODE_TYPE_FESTIVAL               6


static char smmNodeName[MAX_NODETYPE][MAX_CHARNAME] = {
       "lecture",
       "restaurant",
       "laboratory",
       "home",
       "gotoLab",
       "foodChance",
       "festival"
};

static int smm_nodeNr=0;

typedef struct {
    char name[MAX_CHARNAME];
    int type;
    int credit;
    int energy;
} smmObj_board_t;


static smmObj_board_t smmObj_board[MAX_NODENR];

//object generation
int smmObj_genNode(char* name, int type, int credit, int energy)
{
    strcpy(smmObj_board[smm_nodeNr].name, name);
    smmObj_board[smm_nodeNr].type   = type;
    smmObj_board[smm_nodeNr].credit = credit;
    smmObj_board[smm_nodeNr].energy = energy;
    smm_nodeNr++;
    return smm_nodeNr;
}

//member retrieving
char* smmObj_getName(int node_nr)
{
    return smmObj_board[node_nr].name;;
}

int smmObj_getType(int node_nr)
{
    return smmObj_board[node_nr].type;
}


// i번째 칸의 "학점 변화" 반환
int smmObj_getCredit(int node_nr)
{
    return smmObj_board[node_nr].credit;
}

// i번째 칸의 "에너지 변화" 반환
int smmObj_getEnergy(int node_nr)
{
    return smmObj_board[node_nr].energy;
}

// i번째 칸의 "유형 이름(lecture, restaurant…)" 반환
char* smmObj_getNodeName(int node_nr)
{
    int type = smmObj_board[node_nr].type;   // 해당 칸의 type 번호
    return smmNodeName[type];               // 그 type에 대한 문자열
}


#if 0
//element to string
char* smmObj_getNodeName(smmNode_e type)
{
    return smmNodeName[type];
}

char* smmObj_getGradeName(smmGrade_e grade)
{
    return smmGradeName[grade];
}
#endif
