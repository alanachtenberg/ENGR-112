//Alan Achtenberg
//Engr 112-513
//HW4 PR1

 #include "std_lib_facilities_3.h"
 
 
 
 int main()
 {
 string file1;
 string file2;
 string file3;
 
 cout<<"input the names of 3 files: two input files and an output file.\n";
 cin>>file1>>file2>>file3;
 
 ifstream input1(file1.c_str());
 ifstream input2(file2.c_str());
 ofstream output(file3.c_str());
 if (!input1) error("cant open input file",file1);
 if (!input2) error("cant open input file",file2);
 if (!output) error("cant open input file",file3);

 
 vector<string>first;
 vector<string>second;
 while(input1.good() && !input1.eof()){
	string temp;
	getline(input1,temp);
	first.push_back(temp);
 }
 while(input2.good() && !input2.eof()){
	 string temp2;
	getline(input2,temp2);
	second.push_back(temp2);
 }
 
	int i=0;
	int diff=max(first.size(),second.size())-min(first.size(),second.size());
	diff=abs(diff);
	for (i=0;i<min(first.size(),second.size());i++)
	{
		if (first[i]==second[i])
			output<<i+1<<":OK"<<'\n';
		else 
			output<<i+1<<":DIFF"<<'\n';
			
	}
	
		while (diff>0){
			output<<i+1<<":DIFF"<<'\n';
			--diff;
			++i;
		}
 
 keep_window_open();
 return 0;
 
 
 }