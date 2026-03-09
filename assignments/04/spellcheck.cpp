#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);
// using Corpus = std::set<Token>;
Corpus tokenize(std::string& source) {
  /* TODO: Implement this method */
  /*int p = 0;
  int p_ = 0;
  std::string temp = "";
  Corpus result;
  for (; p < source.size(); p++){
    if (source[p] = ' '){
      Token n;
      n.content = temp;
      n.src_offset = p_;
      result.push(n);
      p_ = p+1;
      temp = "";
    }
    else{
      temp += source[p];
    }
  }
  return result;*/ //不成熟的方法.
  
  // step 1: Identify all iterators to space characters
  auto iter = find_all(source.begin(), source.end(), ::isspace); //[](char c){return c == ' ';}
  
  // step 2: Generate tokens between consecutive space characters
  std::set<Token> tk;
  std::transform(
    iter.begin(),
    iter.end() - 1,
    iter.begin() + 1,
    std::inserter(tk, tk.end()),
    [&source](auto it1, auto it2){return Token{source, it1, it2};}
  );

  // step 3: Get rid of empty tokens
  std::erase_if(tk, [](const Token& c){return c.content.empty();}); 
  // 在lambda函数中，使用const的好处是语义清晰，表明只读不修改，可以让编译器优化；
  // & 表明不拷贝，直接引用原对象，可以节省开销.
  return tk;
}

std::set<Misspelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  /* TODO: Implement this method */
  // step 1: Skip words that are already correctly spelled. 
  // step 2: Find one-edit-away words in the dictionary using Damerau-Levenshtein
  namespace rv = std::ranges::views; 
  auto view = source | 
            rv::filter([&dictionary](const Token& token){return !(dictionary.contains(token.content));}) | //留下不在字典中的token
            rv::transform([&dictionary](const Token& token){
              auto suggest_view = dictionary | rv::filter([&token](const std::string& word){return levenshtein(token.content, word) == 1;});
              std::set<std::string> suggest(suggest_view.begin(), suggest_view.end());
              return Misspelling{token, suggest};
            }) |
            // std::ranges::view::transform: 对范围中的每个元素应用一个函数，将其转换成另一种类型或值，返回一个包含转换结果的惰性视图（一个迭代器）
            // std::ranges::view::filter: 对范围中的每个元素应用一个函数，决定它的去留，返回一个包含转换结果的惰性视图（一个迭代器）
            
            // step 3: Drop misspellings with no suggestions.
            rv::filter([](const Misspelling& mis){return !mis.suggestions.empty();});

  std::set<Misspelling> res(view.begin(), view.end());
  return res;
};

/* Helper methods */

#include "utils.cpp"