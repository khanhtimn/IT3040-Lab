/*
Xây dựng một máy tìm kiếm (search engine) đơn giản.
Cho N văn bản và Q truy vấn. Với mỗi truy vấn, cần trả về văn bản khớp với truy vấn đó nhất.
Sử dụng phương pháp tính điểm TF-IDF:
- f(t,d) là số lần xuất hiện của từ t trong văn bản d
- maxf(d) là giá trị lớn nhất của f(t,d) với mọi t
- df(t) là số văn bản chứa từ t
- TF(t,d) = 0.5 + 0.5⋅f(t,d) / maxf(t,d)
- IDF(t)=log2(N / df(t))
- Điểm số của từ t trong văn bản d là score(t,d) = TF(t,d)⋅IDF(t), nếu từ t không xuất hiện trong văn bản d thì score(t,d)=0.
- Điểm số của văn bản d đối với truy vấn gồm các từ (có thể trùng nhau) t1,t2,...,tq là ∑i=1qscore(ti,d)
Ta coi văn bản có điểm số càng cao thì càng khớp với truy vấn.
Input:
Dòng đầu tiên chứa số N
Dòng thứ i trong N dòng tiếp theo thể hiện văn bản i, mỗi dòng là một dãy các từ ngăn cách nhau bởi dấu phẩy
Dòng tiếp theo chứa số Q
Dòng thứ i trong Q dòng tiếp theo thể hiện truy vấn thứ i, mỗi dòng là một dãy các từ ngăn cách nhau bởi dấu phẩy
Output:
Gồm Q dòng, dòng thứ i là chỉ số của văn bản khớp với truy vấn thứ i nhất. Nếu có nhiều văn bản có điểm số bằng nhau, in ra văn bản có chỉ số nhỏ nhất.
*/

#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int n, q;
vector<vector<string>> texts;
vector<vector<string>> queries;
map<pair<string, int>, int> word_frequency;
vector<int> max_frequency;
map<string, int> document_frequency;

inline vector<string> splitByComma(const string& s)
{
    vector<string> result;
    string current_word;
    for (char ch : s) {
        if (ch != ',') {
            current_word.push_back(ch);
        } else {
            result.push_back(current_word);
            current_word.clear();
        }
    }
    result.push_back(current_word);
    return result;
}

inline void readInput()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string text;
        cin >> text;
        texts.push_back(splitByComma(text));
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        string query;
        cin >> query;
        queries.push_back(splitByComma(query));
    }
}

inline void calculateWordFrequency()
{
    for (int i = 0; i < n; ++i) {
        int max_word_count = 0;
        for (auto& word : texts[i]) {
            pair<string, int> key = make_pair(word, i);
            if (word_frequency.find(key) != word_frequency.end()) {
                ++word_frequency[key];
            } else {
                word_frequency[key] = 1;
            }
            max_word_count = max(max_word_count, word_frequency[key]);
        }
        max_frequency.push_back(max_word_count);
    }
}

inline int calculateDocumentFrequency(const string& word)
{
    if (document_frequency.find(word) != document_frequency.end()) {
        return document_frequency[word];
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (string& s : texts[i]) {
            if (word == s) {
                ++count;
                break;
            }
        }
    }
    document_frequency[word] = count;
    return count;
}

inline double computeScore(const string& word, int text_index)
{
    if (word_frequency[{ word, text_index }] == 0)
        return 0;
    return (0.5 + 0.5 * word_frequency[{ word, text_index }] / max_frequency[text_index]) * log2(n / calculateDocumentFrequency(word));
}

inline int findBestMatchingText(const vector<string>& query_words)
{
    int best_index = -1;
    double highest_score = -1;
    for (int i = 0; i < n; ++i) {
        double current_score = 0;
        for (auto& word : query_words) {
            current_score += computeScore(word, i);
        }

        if (current_score > highest_score) {
            highest_score = current_score;
            best_index = i;
        }
    }
    return best_index + 1;
}

int main()
{
    readInput();
    calculateWordFrequency();
    for (auto& query : queries) {
        cout << findBestMatchingText(query) << endl;
    }

    return 0;
}
