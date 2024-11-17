#include <iostream>
#include <sstream>
#include <math.h>
#include <string.h>

using namespace std;

string MemGen(string mem) {
    int p=0;
    for(int i=0;i<mem.size();i++)
    {
      p=p+(mem[i]-'0')*pow(10,mem.size()-i-1);
    }
      
      
    string binary = "";
    while (p != 0) {
        binary = to_string(p % 2) + binary;
        p = p / 2;
    }
    while (binary.size() < 12) {
        binary = "0" + binary;
    }
    return binary;
}

string OpGen(string& op) {
    string command = "";

    if (op[0] == 'L') { // LOAD M[X]
        command = "00000001" + MemGen(op.substr(8,1));
    } else if (op[0] == 'S') { // STOR M[X]
        command = "00100001" + MemGen(op.substr(8,1));
    } else if (op[0] == 'A') { // ADDS M[X]
        command = "00000101" + MemGen(op.substr(7,1));
    } else if (op[0] == 'J') { // JUMP M[X]
        command = "00001101" + MemGen(op.substr(8,3));
    } else if (op[0] == 'C') { // COMP M[X]
        command = "00111110" + MemGen(op.substr(8,1));
    }
    else if(op.substr(0,4) =="GREAT"){      //GRET M[X]
        command = "00111110" + MemGen(op.substr(8,1));
    }
    else if(op.substr(0,4) =="LESS"){//LESS M[X]
        command="00000111" + MemGen(op.substr(8,1));
    }
    else if(op[0]=='H'){
        command="0000000000000000000000000000000000000000";
    }


    return command;
}

int main() {
    string byte_code;
    string newbyte;
    string line;

    while (getline(cin, line)) {
        if (!line.empty()) {
            string l = line.substr(0, 11);
            string r = line.substr(11, 11);
          
              byte_code = OpGen(l) + OpGen(r);
              if(byte_code.size()==20)
              {
                byte_code=byte_code+"00000000000000000000";
              }
              newbyte+=byte_code+"\n";
        }
        else{
        break;
        }
    }

    cout << newbyte << endl;

    return 0;
}
