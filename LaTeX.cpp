#include <vector>
#include <iomanip>
#include <map>
#include <iterator>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

#include <stdio.h>      /* puts */
#include <time.h>       /* time_t, struct tm, time, localtime, strftime */


int main(int argc, char* argv[]){
	/*ofstream myfile;
	myfile.open ("example.txt");
	myfile << "Writing this to a file.\n";
	myfile.close();*/
	std::cout<<"\nName of Output File: ";
	std::string filename;
	std::cin >> filename;

	if(filename.find(".tex")==std::string::npos){
		filename = filename + ".tex";
	}

	int hw;
	std::cout<<"\nHomework Number: ";
	std::cin >> hw;

	std::cout<<"\nNumber of Questions: ";
	int q = 0;
	std::cin >> q;

	std::vector<int> s;

	for(int i=0;i<q;i++){
		std::cout<<"\n  Sections of Question "<<i+1<<": ";
		int x;
		std::cin >> x;
		s.push_back(x);
	}

	std::ofstream file;
	file.open(filename);

	time_t rawtime;
  	struct tm * timeinfo;
  	char buffer [80];

  	time (&rawtime);
  	timeinfo = localtime (&rawtime);

  	strftime (buffer,80,"%B %d, %Y",timeinfo);

  	//std::cout<<buffer;
  	
  			file<<"\\documentclass[11pt]{article}";
  			file<<"\n";
  			file<<"\n\\usepackage[margin=1in]{geometry}";
			file<<"\n\\usepackage{fancyhdr}";
			file<<"\n\\pagestyle{fancy}";
			file<<"\n\\usepackage{amsmath}";
			file<<"\n\\usepackage{amssymb}";
			file<<"\n";
			file<<"\n\\lhead{FoCS Homework ";
			file<<hw;
			file<<"}";
			file<<"\n\\chead{Ross Leonard}";
			file<<"\n\\rhead{";
			file<<buffer;
			file<<"}";
			file<<"\n";
			file<<"\n\\begin{document}";
			file<<"\n";
			file<<"\n\\begin{enumerate}";
			file<<"\n";


	for(int i=0;i<q;i++){
		if(s[i]<=1){
			file<<"\n %%Question ";
			file<<(i+1);
			file<<"\n  \\item";
			file<<"\n  \\newpage";
		}else{
			file<<"\n %%Question ";
			file<<(i+1);
			file<<"\n  \\item";
			file<<"\n  \\begin{enumerate}";
			for(int j=0;j<s[i];j++){
				file<<"\n   %%Section ";
				file<<(char)(j+97);
				file<<"\n    \\item";
			}
			file<<"\n  \\end{enumerate}";
			file<<"\n  \\newpage";
		}
		file<<"\n";
	}

	file<<"\n\\end{enumerate}";
	file<<"\n";
	file<<"\n\\end{document}";
	file<<"\n%% Auto-formatter written by Ross Leonard";

  	file.close();
	return 0;
}