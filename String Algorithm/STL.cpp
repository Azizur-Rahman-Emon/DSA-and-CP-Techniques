//Substring
s.substr(pos, len);
//Find
s.find("abc");     // first occurrence
s.rfind("abc");    // last occurrence

if(s.find("abc") == string::npos)
    cout << "Not found";
//Insert & Erase
s.insert(pos, "abc");
s.erase(pos, len);
// Replace
s.replace(pos, len, "xyz");
//Case Conversion
for(char &c : s) c = tolower(c);
for(char &c : s) c = toupper(c);
//Conversion
// string → int
int x = stoi(s);
long long y = stoll(s);
//int → string
string s = to_string(123);
//Unique characters (sorted)
sort(s.begin(), s.end());
s.erase(unique(s.begin(), s.end()), s.end());
//Check digit / alpha
isdigit(c)
isalpha(c)
islower(c)
isupper(c)
