#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;
int n, m;
map<string, set<string> > lib;

int main() {
    scanf("%d", &n);
    while (n--) {
        string id, title, author, key, publisher, year;
        cin >> id;
        getchar();
        getline(cin, title);
        lib[title].insert(id);
        getline(cin, author);
        lib[author].insert(id);
        
        while(true) {
            cin >> key;
            lib[key].insert(id);
            char temp = getchar();
            if (temp == '\n') break;
        }
        getline(cin, publisher);
        lib[publisher].insert(id);
        getline(cin, year);
        lib[year].insert(id);
    }
    
    scanf("%d", &m);
    while(m--) {
        int cs;
        string query;
        scanf("%d: ", &cs);
        getline(cin, query);
        cout << cs << ": " << query << endl;
        if (lib[query].size() == 0) cout << "Not Found" << endl;
        else for (auto s : lib[query]) cout << s << endl;
    }
    return 0;
}
