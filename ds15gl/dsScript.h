﻿#ifndef _DSDCRIPT_H
#define _DSDCRIPT_H

#include <string>
#include <list>
#include "dsVector2f.h"

using std::string;

enum ScriptType {
    //next_turn,
    soldier_move,
    soldier_fight,
    soldier_die,
    soldier_pain,
	soldier_skill,
	//传送
	soldier_trans,
    view_move,
	game_over,
	game_begin,
    empty
};

struct Record {
    int round_number;       // 回合数
    bool sync;       // 是否与上一条指令同时发出
    string id;       // 对象id;
    ScriptType type; // 动作
   // 目标
	/*令soldier_pan的x,代表所受伤害
	*/
	int x, y;     

    Record() {}
    Record(Record& record):
        round_number(record.round_number),
        sync(record.sync),
        id(record.id),
        type(record.type),
        x(record.x),
        y(record.y) {}

    Record(
        int _round,
        bool _sync,
        string _id,
        ScriptType _type,
        size_t _x,
        size_t _y
    ):
        round_number(_round),
        sync(_sync),
        id(_id),
        type(_type),
        x(_x),
        y(_y) {}
};

class DSScript {
public:
    DSScript(): emptyRecord(0, false, "", empty, 0, 0) {
        /*scriptQue.push_back(Record(0, false, "sword_man", soldier_fight, 2, 2));
        scriptQue.push_back(Record(0, false, "monkey", soldier_fight, 2, 2));
        scriptQue.push_back(Record(0, false, "bauul", soldier_fight, 2, 2));
        scriptQue.push_back(Record(0, false, "gunman", soldier_fight, 2, 2));

        scriptQue.push_back(Record(1, false, "sword_man", soldier_move, 3, 2));
        scriptQue.push_back(Record(1, false, "monkey", soldier_move, 2, 1));
        scriptQue.push_back(Record(1, false, "bauul", soldier_move, 1, 2));
        scriptQue.push_back(Record(1, false, "gunman", soldier_move, 2, 3));

        scriptQue.push_back(Record(2, false, "sword_man", soldier_fight, 2, 2));
        scriptQue.push_back(Record(2, true, "monkey", soldier_fight, 2, 2));
        scriptQue.push_back(Record(2, true, "bauul", soldier_fight, 2, 2));
        scriptQue.push_back(Record(2, true, "gunman", soldier_fight, 2, 2));

        scriptQue.push_back(Record(2, false, "sword_man", soldier_fight, 2, 2));
        scriptQue.push_back(Record(2, true, "monkey", soldier_fight, 2, 2));
        scriptQue.push_back(Record(2, true, "bauul", soldier_fight, 2, 2));
        scriptQue.push_back(Record(2, true, "gunman", soldier_fight, 2, 2));

        scriptQue.push_back(Record(3, false, "tank", soldier_move, 3, 2));
        scriptQue.push_back(Record(3, true, "sword_man", soldier_die, 3, 2));

        scriptQue.push_back(Record(3, false, "tank", soldier_move, 2, 3));
        scriptQue.push_back(Record(3, true, "gunman", soldier_die, 3, 2));

        scriptQue.push_back(Record(3, false, "tank", soldier_move, 1, 2));
        scriptQue.push_back(Record(3, true, "bauul", soldier_die, 3, 2));

        scriptQue.push_back(Record(3, false, "tank", soldier_move, 2, 1));
        scriptQue.push_back(Record(3, true, "monkey", soldier_die, 3, 2));

        scriptQue.push_back(Record(1, false, "sword_man", soldier_fight, 3, 2));
        scriptQue.push_back(Record(1, false, "disgustin", soldier_fight, 5, 1));
        scriptQue.push_back(Record(1, false, "chastit", soldier_fight, 1, 2));
        scriptQue.push_back(Record(1, false, "monkey", soldier_fight, 5, 1));
        scriptQue.push_back(Record(1, false, "mage", soldier_fight, 1, 6));
        scriptQue.push_back(Record(1, false, "gunman", soldier_fight, 0, 1));
        scriptQue.push_back(Record(1, false, "bauul", soldier_fight, 5, 1));

        scriptQue.push_back(Record(1, false, "sword_man", soldier_move, 3, 2));

        scriptQue.push_back(Record(1, false, "sword_man", soldier_fight, 1, 1));

        
        scriptQue.push_back(Record(1, true, "disgustin", soldier_pain, 5, 1));
        scriptQue.push_back(Record(1, false, "disgustin", soldier_die, 5, 1));

        scriptQue.push_back(Record(2, false, "chastit", soldier_fight, 1, 2));
        scriptQue.push_back(Record(2, false, "mage", soldier_fight, 0, 1));
        scriptQue.push_back(Record(2, false, "gunman", soldier_fight, 0, 1));
        scriptQue.push_back(Record(2, false, "bauul", soldier_fight, 5, 1));
        scriptQue.push_back(Record(2, false, "fighter", soldier_fight, 5, 1));
        
        scriptQue.push_back(Record(2, false, "monkey", soldier_fight, 5, 1));
        scriptQue.push_back(Record(2, false, "", view_move, 10, 10));

        scriptQue.push_back(Record(2, false, "mage", soldier_pain, 1, 6));
        scriptQue.push_back(Record(2, false, "sword_man", soldier_pain, 2, 9));
        scriptQue.push_back(Record(2, false, "sword_man", soldier_die, 2, 9));

        scriptQue.push_back(Record(3, false, "sword_man", soldier_move, 1, 1));
        scriptQue.push_back(Record(3, false, "mage", soldier_die, 0, 1));

        scriptQue.push_back(Record(4, false, "sword_man", soldier_move, 5, 1));
        scriptQue.push_back(Record(4, false, "mage", soldier_move, 1, 5));
        scriptQue.push_back(Record(4, false, "fighter", soldier_die, 2, 3));

        scriptQue.push_back(Record(5, false, "sword_man", soldier_move, 2, 5));*/
    }

	void add(
		int _round,
		bool _sync,
		string _id,
		ScriptType _type,
		size_t _x,
		size_t _y){
		scriptQue.push_back(Record(_round,_sync,_id,_type,_x,_y));
	}

	void clear(){
		scriptQue.clear();
		
	}

    // 窥探接下来的一条记录，但是不将该记录挤出队列
    Record peekNextRecord() {
        if (scriptQue.empty()) {
            return emptyRecord;
        }
        return scriptQue.front();
    }

    // 获取接下来的一条记录，同时将该记录挤出队列
    Record getNextRecord() {
        if (scriptQue.empty()) {
            return emptyRecord;
        }
        Record r = scriptQue.front();
        scriptQue.pop_front();
        return r;
    }

    bool notEmpty() {
        return !scriptQue.empty();
    }

    int nextRound() {
        if (scriptQue.empty()) {
            return 0;
        }
        return scriptQue.front().round_number;
    }
	//弹出刚入列的记录
	Record pop() {
		if (scriptQue.empty()) {
			return emptyRecord;
		}
		Record r = scriptQue.back();
		scriptQue.pop_back();
		return r;
	}

public:
    //脚本队列
    std::list<Record> scriptQue;

    //有一个空 Record
    Record emptyRecord;
};


#endif
