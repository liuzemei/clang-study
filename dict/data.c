struct dictStat {
  int wordLength; // 所有的单词个数
  struct word* words; // 该单词的解释
};

struct word {
  int wordLength; // 单词的长度
  char* content; // 单词的内容
  struct trans* translate; // 该单词的解释
  int transCount; // 解释个数
};

struct trans {
  int transLength; // 解释的长度
  char* content; // 解释的内容
};