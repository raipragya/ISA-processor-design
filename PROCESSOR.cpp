# include <bits/stdc++.h>
using namespace std;
string MAR,IBR,mem[1000];
int AC=0,PC=420,MBR;


//decoder
void decoder(string inst,vector <int> &M)
{
  string opL,opR,iR,iL,rhs,lhs;
  lhs=inst.substr(0,20);
  rhs=inst.substr(20,20);
  opL=lhs.substr(0,8);
  opR=rhs.substr(0,8);
  iL=lhs.substr(8,12);
  iR=rhs.substr(8,12);
  IBR=rhs;//storing right instruction in IBR
  MAR=iL;
  //LOAD M[X]
  if(opL=="00000001")
  {
    cout<<"PC: "<<PC<<endl;
    MAR=to_string(PC);
    AC=M[stoi(iL,0,2)];
    cout<<"AC: "<<AC<<endl;
    MBR=M[stoi(iL,0,2)];
    cout<<"MBR: "<<MBR<<endl;
  }
  // STOR M[X]
  else if (opL == "00100001")
    {
        cout<<"PC: "<<PC<<endl;
        M[stoi(iL, 0, 2)] = AC;
        cout<<"AC: "<<AC<<endl;
        MBR = M[stoi(iL, 0, 2)];
        cout<<"MBR: "<<MBR<<endl;
    }

    // ADD M[X]
    else if (opL == "00000101")
    {
        cout<<"PC: "<<PC<<endl;
        AC += M[stoi(iL, 0, 2)];
        cout<<"AC: "<<AC<<endl;
        MBR = M[stoi(iL, 0, 2)];
        cout<<"MBR: "<<MBR<<endl;
    }
    
    
   
     //LESS M[X]
    else if(opL =="00000111")
      {
        cout<<"PC :"<<PC<<endl;
        if(M[M[stoi(iL,0,2)]]<M[3])
        {
          AC=M[3];
          MBR=M[3];
        }
      cout<<"AC: "<<AC<<endl;
      cout<<"MBR: "<<MBR<<endl;
     }
   
   
    PC++;
    MAR=iR;
    if (opR == "00000001")
    {
        cout<<"PC: "<<PC<<endl;
        AC = M[stoi(iR, 0, 2)];
        cout<<"AC: "<<AC<<endl;
        MBR = M[stoi(iR, 0, 2)];
        cout<<"MBR: "<<MBR<<endl;
    }

    // STOR M[X]
    else if (opR == "00100001")
    {
        cout<<"PC: "<<PC<<endl;
        M[stoi(iR, 0, 2)] = AC;
        cout<<"AC: "<<AC<<endl;
        MBR = M[stoi(iR, 0, 2)];
        cout<<"MBR: "<<MBR<<endl;
    }

    // ADD M[X]
    else if (opR == "00000101")
    {
        cout<<"PC: "<<PC<<endl;
        AC += M[stoi(iR, 0, 2)];
        cout<<"AC: "<<AC<<endl;
        MBR = M[stoi(iR, 0, 2)];
        cout<<"MBR: "<<MBR<<endl;
    }
    //GRET M[X] 
    else if(opR== "00111110")
    {
      cout<<"PC: "<<PC<<endl;
      if(M[M[stoi(iR,0,2)]]>M[3])
      {
          AC=M[M[stoi(iR,0,2)]];
          MBR=M[M[stoi(iR,0,2)]];
      }
      cout<<"AC: "<<AC<<endl;
      cout<<"MBR: "<<MBR<<endl;
    }
    
   
  }    




int main()
{
  string h;
  for(int i=0;i<40;i++)
  {
    h+='0';
  }
  int count=420;
  cout<<"enter the 40 bit instruction\n";
  //the following loop takes 40 bit instruction in memory named array
  //memory is an array of strings(mem[1000])
  // we will give here 13 instructions
  string i;
  while(1)
  {
    cin>>i;
    mem[count++]=i;
    
    if(i==h)
      break;
  }
  //keeps track of what instruction to execute next
  int ctr=420;
  int n,element;
  cin>>n;
  vector <int> M={7,0,0,0,n-1,n,1};
  for(int j=0;j<n;j++)
  {
    cin>>element;
    M.push_back(element);
  }
  string t;
  int m=1;
  while(1)
  {
    t=mem[ctr];
    //JUMP instruction
    if(t=="0000000000000000000000001101000110100101")
    {
      ctr=421;
      if(m==n)
      {
        for(auto i:M)
        {
          cout<<i;
        }
        cout<<"max element in our array is:"<<M[3];
        break;
      }
      else
      {
        m++;
        continue;
      }
    }
    else
    {
      decoder(t,M);
    }
    ctr++;
  }
  return 0;
}
//we give inputs as follows:
 //-------start of input--------
//0000000100000000011100100001000000000011

//0000000100000000000000000101000000000110

//0010000100000000001000111110000000000010  

//0000011100000000001000100001000000000011 

//0000000100000000001000100001000000000000

//0000000000000000000000001101000110100101

//0000000000000000000000000000000000000000
//5           //number of elements in a vector array
 //3 2 4 0 1  one by  one taking  elements as an input of our vector array
