/*
 * @lc app=leetcode.cn id=65 lang=cpp
 *
 * [65] 有效数字
 */

// @lc code=start
class Solution {
private:
    // 有限状态机
    enum State {
        STATE_INITIAL,
        STATE_INT_SIGN,
        STATE_INT,
        STATE_POINT,
        STATE_POINT_WITHOUT_INT,
        STATE_FRACTION,
        STATE_EXP,
        STATE_EXP_SIGN,
        STATE_EXP_INT,
        STATE_END,
    };

    enum CharType {
        CHAR_SIGN,
        CHAR_INT,
        CHAR_POINT,
        CHAR_EXP,
        CHAR_ILLEGAL,
        CHAR_EMPTY,
    };

    CharType toCharType(char ch) {
        if (ch == '+' || ch == '-')
            return CHAR_SIGN;
        else if (ch <= '9' && ch >= '0')
            return CHAR_INT;
        else if (ch == '.')
            return CHAR_POINT;
        else if (ch == 'e' || ch == 'E')
            return CHAR_EXP;
        else if (ch == ' ')
            return CHAR_EMPTY;
        else
            return CHAR_ILLEGAL;
    }

public:
    bool isNumber(string s) {
        unordered_map<State, unordered_map<CharType, State>> transfer{
            {STATE_INITIAL, {{CHAR_SIGN, STATE_INT_SIGN}, {CHAR_INT, STATE_INT}, {CHAR_POINT, STATE_POINT_WITHOUT_INT}, {CHAR_EMPTY, STATE_INITIAL}}},
            {STATE_INT_SIGN, {{CHAR_INT, STATE_INT}, {CHAR_POINT, STATE_POINT_WITHOUT_INT}}},
            {STATE_INT, {{CHAR_INT, STATE_INT}, {CHAR_POINT, STATE_POINT}, {CHAR_EXP, STATE_EXP}, {CHAR_EMPTY, STATE_END}}},
            {STATE_POINT_WITHOUT_INT, {{CHAR_INT, STATE_FRACTION}}},
            {STATE_POINT, {{CHAR_INT, STATE_FRACTION}, {CHAR_EXP, STATE_EXP}, {CHAR_EMPTY, STATE_END}}},
            {STATE_FRACTION, {{CHAR_INT, STATE_FRACTION}, {CHAR_EXP, STATE_EXP}, {CHAR_EMPTY, STATE_END}}},
            {STATE_EXP, {{CHAR_SIGN, STATE_EXP_SIGN}, {CHAR_INT, STATE_EXP_INT}}},
            {STATE_EXP_SIGN, {{CHAR_INT, STATE_EXP_INT}}},
            {STATE_EXP_INT, {{CHAR_INT, STATE_EXP_INT}, {CHAR_EMPTY, STATE_END}}},
            {STATE_END, {{CHAR_EMPTY, STATE_END}}}
        };
        
        int len = s.length();
        State st = STATE_INITIAL;

        for (int i = 0; i < len; i++) {
            CharType typ = toCharType(s[i]);
            if (transfer[st].find(typ) == transfer[st].end()) {
                return false;
            } else {
                st = transfer[st][typ];
            }
        }

        return st == STATE_INT || st == STATE_POINT || st == STATE_FRACTION || st == STATE_EXP_INT || st == STATE_END;
    }
};

// @lc code=end
