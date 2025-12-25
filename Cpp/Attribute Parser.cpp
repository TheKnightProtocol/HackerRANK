#include <iostream>
#include <map>
#include <vector>
#include <sstream>
using namespace std;

struct Tag {
    string name;
    map<string, string> attributes;
    vector<Tag*> children;
    Tag* parent;
};

pair<string, string> parseAttribute(const string& line, size_t& pos) {
    size_t eqPos = line.find('=', pos);
    string attrName = line.substr(pos, eqPos - pos - 1);
    
    size_t quotePos = line.find('"', eqPos + 1);
    size_t nextQuote = line.find('"', quotePos + 1);
    string attrValue = line.substr(quotePos + 1, nextQuote - quotePos - 1);
    
    pos = nextQuote + 2;
    return {attrName, attrValue};
}

int main() {
    int N, Q;
    cin >> N >> Q;
    cin.ignore();
    
    vector<string> hrmlLines(N);
    for(int i = 0; i < N; i++) {
        getline(cin, hrmlLines[i]);
    }
    
    map<string, Tag*> tagMap;
    vector<Tag*> tagStack;
    Tag* root = nullptr;
    
    for(const auto& line : hrmlLines) {
        if(line[1] == '/') {
            tagStack.pop_back();
            continue;
        }
        
        size_t pos = 1;
        size_t spacePos = line.find(' ', pos);
        string tagName;
        
        if(spacePos != string::npos) {
            tagName = line.substr(pos, spacePos - pos);
            pos = spacePos + 1;
        } else {
            size_t closePos = line.find('>', pos);
            tagName = line.substr(pos, closePos - pos);
        }
        
        Tag* newTag = new Tag{tagName, {}, {}, tagStack.empty() ? nullptr : tagStack.back()};
        
        if(tagStack.empty()) {
            root = newTag;
        } else {
            tagStack.back()->children.push_back(newTag);
        }
        
        if(spacePos != string::npos) {
            while(pos < line.length() && line[pos] != '>') {
                auto attr = parseAttribute(line, pos);
                newTag->attributes[attr.first] = attr.second;
            }
        }
        
        string fullName = tagName;
        Tag* current = newTag->parent;
        while(current) {
            fullName = current->name + "." + fullName;
            current = current->parent;
        }
        tagMap[fullName] = newTag;
        
        tagStack.push_back(newTag);
    }
    
    for(int i = 0; i < Q; i++) {
        string query;
        cin >> query;
        
        size_t tildePos = query.find('~');
        string path = query.substr(0, tildePos);
        string attrName = query.substr(tildePos + 1);
        
        if(tagMap.find(path) == tagMap.end()) {
            cout << "Not Found!" << endl;
            continue;
        }
        
        Tag* targetTag = tagMap[path];
        if(targetTag->attributes.find(attrName) == targetTag->attributes.end()) {
            cout << "Not Found!" << endl;
        } else {
            cout << targetTag->attributes[attrName] << endl;
        }
    }
    
    return 0;
}
