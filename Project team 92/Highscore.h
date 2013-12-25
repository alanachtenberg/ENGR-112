//read and write high scores
//Engr 112-513
// team 92
#include "std_lib_facilities_3.h"

void Read_Score( vector<int> &a, vector<string> &b)
	{
 string hs="High Scores.txt";

 ifstream hs_in(hs.c_str());
 if (!hs_in) error("cant open input file",hs);
 
 string temp;
 int tempint;
 int i=0;
 while(i<5){ //read in 5 scores
	getline(hs_in,temp,':');
	stringstream ss;
    ss<<temp;
	ss>>tempint;
	a.push_back(tempint);
	getline(hs_in,temp);
	b.push_back(temp);
	++i;
	}
 hs_in.close();

	}
 

void Save_Score(int score, string name)
{
 string hs="High Scores.txt";

 vector<int> scores;
 vector<string> names;
 Read_Score(scores,names);
 
 ofstream hs_out(hs.c_str());
 if (!hs_out) error("cant open output file",hs);


 int i=0;
 while(i<5){
	if (score>=scores[i])
	{
		hs_out<<score<<':'<<name<<'\n';

		score=-1;
	}
	else{
	hs_out<<scores[i]<<':'<<names[i]<<'\n';

	++i;
	}
 }

 hs_out.close();
 }
