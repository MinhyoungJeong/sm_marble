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
#define MAX_GRADE         13

#define OBJTYPE_BOARD 0
#define OBJTYPE_GRADE 1
#define OBJTYPE_FOOD 2
#define OBJTYPE_FEST 3


#define GRADE_A+ 0
#define GRADE_A0 1
#define GRADE_A- 2
#define GRADE_B+ 3
#define GRADE_B- 4
#define GRADE_C+ 5
#define GRADE_C0 6
#define GRADE_C- 7
#define GRADE_D+ 8
#define GRADE_D0 9
#define GRADE_D- 10
#define GRADE_F 11

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

static char smmObj_gradeName[MAX_GRADE][MAX_CHARNAME] = {
       "A+",
       "A0",
       "A-",
       "B+",
       "B0",
       "B-",
       "C+",
       "C-",
       "D+",
       "D-",
       "F",
};

static int smm_nodeNr=0;

typedef struct {
    char name[MAX_CHARNAME];
    int objType;
    int type;
    int credit;
    int energy;
    int grade;
} smmObj_object_t;
//배열 형태가 아니라 linkedlist - database에 넣기
//object generation
//node->확장시킬예정, 동적메모리형태로 할당하기
void* smmObj_genObject(char* name, int objType int type, int credit, int energy, int grade)
{
    smmObj_object_t* ptr;
    ptr = (smmObj_object_t*)malloc(sizeof(smmObj_object_t));
    
    strcpy(ptr->name, name);
    ptr->type = type;
    ptr->objType = objType;
    ptr->credit = credit;
    ptr->energy = energy;
    ptr->grade = grade;

    return ((void*)ptr);
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
char* smmObj_getNodeName(void *ptr)
{
    smmObj_genObject_t* objPtr = (smmObj_object_t*)ptr;
    return (objPtr->name);            // 그 type에 대한 문자열
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
