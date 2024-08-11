#include <bits/extc++.h>

#define int long long

std::ifstream fin("struct.in");
std::ofstream fout("struct.out");

using std::operator""s;

struct Struct {
    Struct() = default;
    template <typename T1, typename T2, typename T3, typename T4>
    Struct(T1 &&t1, T2 &&t2, T3 &&t3, T4 &&t4) {
        this->name = std::forward<T1>(t1);
        this->mates = std::forward<T2>(t2);
        this->large = std::forward<T3>(t3);
        this->names = std::forward<T4>(t4);
    }
    Struct(const Struct &) = default;
    Struct(Struct &&) noexcept = default;

    auto operator=(const Struct &) -> Struct & = default;
    auto operator=(Struct &&) noexcept -> Struct & = default;

    std::string name;
    std::vector<Struct> mates;
    int large{0};
    std::vector<std::string> names;

    auto findMates(std::string name) -> Struct {
        for (int i = 0; i < this->names.size(); ++i) {
            if (this->names.at(i) == name) {
                return this->mates.at(i);
            }
        }
        return Struct("NULL"s, std::vector<Struct>{}, 0, std::vector<std::string>{});
    }

    auto operator<(const Struct &oth) const -> bool {
        return this->large < oth.large;
    }

    auto operator==(const Struct &oth) const -> bool {
        return this->name == oth.name;
    }
}
INT{"INT"s, std::vector<Struct>{}, 4, std::vector<std::string>{}},
SHORT{"SHORT"s, std::vector<Struct>{}, 2, std::vector<std::string>{}},
BYTE{"BYTE"s, std::vector<Struct>{}, 1, std::vector<std::string>{}},
LONG{"LONG"s, std::vector<Struct>{}, 8, std::vector<std::string>{}},
Null_t{"NULL_t"s, std::vector<Struct>{}, 0, std::vector<std::string>{}};

auto isSimple(const Struct &type) -> bool {
    return type == INT || type == SHORT || type == BYTE || type == LONG;
}

struct Var {
    Struct type;
    std::string name;
    int start;
} Null{Null_t, "Null_t", -1};

int nowEnd = 0;
std::vector<Struct> poses;
std::vector<Struct> structs{INT, SHORT, BYTE, LONG, Null_t};
std::vector<Var> vars;

auto findStruct(std::string name) -> Struct {
    for (auto &s: structs) {
        if (s.name == name) {
            return s;
        }
    }
    return Null_t;
}

auto findVar(std::string name) -> Var {
    for (auto &v: vars) {
        if (v.name == name) {
            return v;
        }
    }
    return Null;
}

auto addStruct(std::string name, const std::vector<std::pair<Struct, std::string>> &mates) -> void {
    Struct newType;
    newType.name = name;
    int maxsiz = -1;
    for (auto &it: mates) {
        maxsiz = std::max(maxsiz, it.first.large);
    }
    for (auto &m: mates) {
        Struct type;
        std::string n;
        std::tie(type, n) = m;
        newType.mates.push_back(type);
        newType.large += maxsiz;
        newType.names.push_back(n);
    }
    structs.push_back(newType);
}

auto setPos(const Struct &type, int maxsiz) -> void {
    std::cout << type.name << ", " << maxsiz << ": " << std::endl;
    if (isSimple(type)) {
        std::cout << "Simple!" << std::endl;
        for (int i = 1; i <= type.large; ++i) {
            poses.push_back(type);
            std::cout << type.name << " ";
        }
        for (int i = type.large + 1; i <= maxsiz; ++i) {
            poses.push_back(Null_t);
            std::cout << Null_t.name << " ";
        }
        std::cout << std::endl;
        return;
    }
    int maxisiz = -1;
    for (auto &m: type.mates) {
        std::cout << m.name << " ";
        maxisiz = std::max(maxisiz, m.large);
    }
    std::cout << std::endl;
    int sum = 0;
    for (auto &m: type.mates) {
        std::cout << "goto " << m.name << std::endl;
        setPos(m, maxisiz);
        std::cout << "leave " << m.name << std::endl;
        sum += maxisiz;
    }
    if (maxsiz != -1) {
        for (int i = sum + 1; i <= maxsiz; ++i) {
            poses.push_back(Null_t);
        }
    }
}

auto addVar(const Struct &type, std::string name) -> void {
    Var newVar{type, name, nowEnd};
    nowEnd += type.large;
    vars.push_back(newVar);
    setPos(type, -1);
}

auto getStruct(int position) -> bool {
    if (position >= poses.size()) {
        return false;
    }
    return isSimple(poses.at(position));
}

auto getPos(int position) -> std::string {
    std::string res;
    Var var;
    for (auto &v: vars) {
        if (v.start + v.type.large > position) {
            res = v.type.name;
            var = v;
        }
    }
    while (!var.type.mates.empty()) {
        var = findVar(var.type.names.front());
        res += '.';
        res += var.type.name;
    }
    return res;
}

int n;

auto main() -> signed {
    fin >> n;
    while (n--) {
        int op;
        fin >> op;
        switch(op) {
        case 1: {
            std::string s;
            int k;
            fin >> s >> k;
            std::vector<std::pair<Struct , std::string>> mates;
            for (int i = 1; i <= k; ++i) {
                std::string structname;
                std::string name;
                fin >> structname >> name;
                Struct type;
                if (structname == "int") {
                    type = INT;
                } else if (structname == "short") {
                    type = SHORT;
                } else if (structname == "byte") {
                    type = BYTE;
                } else if (structname == "long") {
                    type = LONG;
                } else {
                    type = findStruct(structname);
                }
                mates.emplace_back(type, name);
            }
            addStruct(s, mates);
            fout << structs.back().large << " " << structs.back().large / structs.back().mates.size() << "\n";
            break;
        }
        case 2: {
            std::string t, name;
            fin >> t >> name;
            Struct type;
            if (t == "int") {
                type = INT;
            } else if (t == "short") {
                type = SHORT;
            } else if (t == "byte") {
                type = BYTE;
            } else if (t == "long") {
                type = LONG;
            } else {
                type = findStruct(t);
            }
            addVar(type, name);
            fout << vars.back().start << "\n";
            break;
        }
        case 3: {
            std::string s;
            fin >> s;
            fout << findVar(s).start << "\n";
            break;
        }
        case 4: {
            int p;
            fin >> p;
            fout << (getStruct(p) ? getPos(p) : "ERR"s) << "\n";
            break;
        }
        default:
            break;
        }
    }
    return 0;
}
